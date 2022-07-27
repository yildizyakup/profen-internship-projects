/*
 * http_ssi.c
 *
 *  Created on: 11-Oct-2021
 *      Author: controllerstech
 */


#include"http_ssi.h"
#include "string.h"
#include "stdio.h"

#include "lwip/tcp.h"
#include "lwip/apps/httpd.h"

#include "stm32f4xx_hal.h"

int indx = 0;
/* we will use character "x", "y","z" as tag for SSI */
char const* TAGCHAR[]={"x", "y", "z"};
char const** TAGS=TAGCHAR;

extern UART_HandleTypeDef huart3;

uint16_t ssi_handler (int iIndex, char *pcInsert, int iInsertLen)
{
	switch (iIndex) {
		case 0:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 1:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		case 2:
			indx+=1;
			sprintf(pcInsert, "%d", indx);
			return strlen(pcInsert);
			break;
		default :
			break;
	}

	return 0;
}

/************************ CGI HANDLER ***************************/
const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
const char *CGIUART_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);


const tCGI FORM_CGI = {"/form.cgi", CGIForm_Handler};
const tCGI LED_CGI = {"/led.cgi", CGILED_Handler};
const tCGI UART_CGI = {"/uart.cgi", CGIUART_Handler};

char name[30];
char buff[30];
tCGI CGI_TAB[3];


const char *CGIForm_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 0)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (strcmp(pcParam[i], "fname") == 0)  // if the fname string is found
			{
				memset(name, '\0', 30);
				strcpy(name, pcValue[i]);
			}

			else if (strcmp(pcParam[i], "lname") == 0)  // if the fname string is found
			{
				strcat(name, " ");
				strcat(name, pcValue[i]);
			}
		}
	}

	return "/cgiform.html";
}


const char *CGILED_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	if (iIndex == 1)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (!(strcmp(pcParam[i], "led1")))
			{
				HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
			}

			else if (!(strcmp(pcParam[i], "led2")))
			{
				HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			}

			else if (!(strcmp(pcParam[i], "led3")))
			{
				HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
			}
		}
	}

	return "/cgiled.html";
}

const char *CGIUART_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
	int baud,parity,data,stop;

	huart3.Instance = USART3;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;

	if (iIndex == 2)
	{
		for (int i=0; i<iNumParams; i++)
		{
			if (!(strcmp(pcParam[i], "baud")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);
				baud = atoi(buff);
				huart3.Init.BaudRate = baud;
			}

			else if (!(strcmp(pcParam[i], "parity")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);

				if (!(strcmp(buff, "None")))
					huart3.Init.Parity = UART_PARITY_NONE;

				else  if (!(strcmp(buff, "Odd")))
					huart3.Init.Parity = UART_PARITY_ODD;

				else  if (!(strcmp(buff, "Even")))
					huart3.Init.Parity = UART_PARITY_EVEN;

			}

			else if (!(strcmp(pcParam[i], "data")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);
				data = atoi(buff);
				if (data == 8)
					 huart3.Init.WordLength = UART_WORDLENGTH_8B;
				else
					 huart3.Init.WordLength = UART_WORDLENGTH_8B;
			}

			else if (!(strcmp(pcParam[i], "stop")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);
				stop = atoi(buff);
				if(stop == 1)
					huart3.Init.StopBits = UART_STOPBITS_1;
				else if (stop == 2)
					huart3.Init.StopBits = UART_STOPBITS_2;

			}

			else if (!(strcmp(pcParam[i], "hardware")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);

				if (!(strcmp(buff, "None")))
					huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
				else if (!(strcmp(buff, "RTS/CTS")))
					huart3.Init.HwFlowCtl = UART_HWCONTROL_RTS_CTS;
			}

			else if (!(strcmp(pcParam[i], "send")))
			{
				memset(buff, '\0', 30);
				strcpy(buff, pcValue[i]);
				HAL_UART_Transmit(&huart3, buff, strlen(buff), 3000);
			}

			 if (HAL_UART_Init(&huart3) != HAL_OK)
			 {
			   Error_Handler();
			 }
		}
	}

	return "/cgiuart.html";
}

void http_server_init (void)
{
	httpd_init();

	http_set_ssi_handler(ssi_handler, (char const**) TAGS, 3);

	CGI_TAB[0] = FORM_CGI;
	CGI_TAB[1] = LED_CGI;
	CGI_TAB[2] = UART_CGI;

	http_set_cgi_handlers(CGI_TAB, 3);
}


