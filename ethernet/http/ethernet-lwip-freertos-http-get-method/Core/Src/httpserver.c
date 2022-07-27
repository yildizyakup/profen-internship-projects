
/* Includes ------------------------------------------------------------------*/
#include "lwip/opt.h"
#include "lwip/arch.h"
#include "lwip/api.h"
#include "lwip/apps/fs.h"
#include "string.h"
#include <stdio.h>
#include "httpserver.h"
#include "cmsis_os.h"

char colour;
int indx = 0;
char test[100] = {0};
char test2[100] = {0};
char baud[20] = {0};
char parity[20] = {0};
char data[20] = {0};
char stop[20] = {0};
char hardware[20] = {0};
char send[20] = {0};

char baudResult[20] = {0};
char parityResult[20] = {0};
char dataResult[20] = {0};
char stopResult[20] = {0};
char hardwareResult[20] = {0};
char sendResult[20] = {0};


extern UART_HandleTypeDef huart3;

void removeChar(char * str, char charToRemove){
    int i, j;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == charToRemove)
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}

char* getValue(char* string){
        char* arg;
        arg = strchr(string, '=');
		if (arg != NULL)
			arg++;
		else
			;

	return arg;
}

static void http_server(struct netconn *conn)
{
	struct netbuf *inbuf;
	err_t recv_err;
	char* buf;
	u16_t buflen;
	struct fs_file file;
	char *arg;


	/* Read the data from the port, blocking if nothing yet there */
	recv_err = netconn_recv(conn, &inbuf);

	if (recv_err == ERR_OK)
	{
		if (netconn_err(conn) == ERR_OK)
		{
			/* Get the data pointer and length of the data inside a netbuf */
			netbuf_data(inbuf, (void**)&buf, &buflen);

			/* Check if request to get the index.html */
			if (strncmp((char const *)buf,"GET /index.html",15)==0)
			{
				fs_open(&file, "/index.html");

				huart3.Instance = USART3;
				huart3.Init.Mode = UART_MODE_TX_RX;
				huart3.Init.OverSampling = UART_OVERSAMPLING_16;

				arg = strchr((char const *)buf, '?');
				strcpy(test, arg);
				removeChar(test, '?');
				char * token = strtok(test, " ");

				sscanf(token, "%[^&] & %[^&] & %[^&] & %[^&] & %[^&] & %[^&]",baud, parity,data,stop,hardware,send);

				strcpy(baudResult,getValue(baud));

				strcpy(parityResult,getValue(parity));

				strcpy(dataResult,getValue(data));

				strcpy(stopResult,getValue(stop));

				strcpy(hardwareResult,getValue(hardware));

				strcpy(sendResult,getValue(send));

				int intBaud = atoi(baudResult);
				huart3.Init.BaudRate = intBaud;

				if (!(strcmp(parityResult, "None")))
					huart3.Init.Parity = UART_PARITY_NONE;

				else  if (!(strcmp(parityResult, "Odd")))
				huart3.Init.Parity = UART_PARITY_ODD;

				else  if (!(strcmp(parityResult, "Even")))
					huart3.Init.Parity = UART_PARITY_EVEN;

				int intData = atoi(dataResult);
				if (intData == 8)
					huart3.Init.WordLength = UART_WORDLENGTH_8B;
				else
					huart3.Init.WordLength = UART_WORDLENGTH_8B;

				int intStop = atoi(stopResult);
				if(intStop == 1)
					huart3.Init.StopBits = UART_STOPBITS_1;
				else if (intStop == 2)
					huart3.Init.StopBits = UART_STOPBITS_2;

				if (!(strcmp(hardwareResult, "None")))
					huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
				else if (!(strcmp(hardwareResult, "RTS/CTS")))
					huart3.Init.HwFlowCtl = UART_HWCONTROL_RTS_CTS;

				HAL_UART_Transmit(&huart3, sendResult, strlen(sendResult), 3000);

				netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
				HAL_Delay(100);
				fs_close(&file);
				HAL_Delay(100);
			}

			else
			{
				/* Load Error page */
				fs_open(&file, "/404.html");
				netconn_write(conn, (const unsigned char*)(file.data), (size_t)file.len, NETCONN_NOCOPY);
				fs_close(&file);
			}
		}
	}
	/* Close the connection (server closes in HTTP) */
	netconn_close(conn);

	/* Delete the buffer (netconn_recv gives us ownership,
   so we have to make sure to deallocate the buffer) */
	netbuf_delete(inbuf);
}


static void http_thread(void *arg)
{ 
  struct netconn *conn, *newconn;
  err_t err, accept_err;
  
  /* Create a new TCP connection handle */
  conn = netconn_new(NETCONN_TCP);
  
  if (conn!= NULL)
  {
    /* Bind to port 80 (HTTP) with default IP address */
    err = netconn_bind(conn, IP_ADDR_ANY, 80);
    
    if (err == ERR_OK)
    {
      /* Put the connection into LISTEN state */
      netconn_listen(conn);
  
      while(1) 
      {
        /* accept any incoming connection */
        accept_err = netconn_accept(conn, &newconn);
        if(accept_err == ERR_OK)
        {
          /* serve connection */
          http_server(newconn);

          /* delete connection */
          netconn_delete(newconn);
        }
      }
    }
  }
}


void http_server_init()
{
  sys_thread_new("http_thread", http_thread, NULL, DEFAULT_THREAD_STACKSIZE, osPriorityNormal);
}


