/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define M24512_I2C_SDA_PIN GPIO_PIN_9
#define M24512_I2C_SCL_PIN GPIO_PIN_8
#define M24512_I2C_GPIO GPIOB

// Define the Page Size and number of pages
#define PAGE_SIZE 128     // in Bytes
#define PAGE_NUM  500    // number of pages


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

ETH_TxPacketConfig TxConfig;
ETH_DMADescTypeDef  DMARxDscrTab[ETH_RX_DESC_CNT]; /* Ethernet Rx DMA Descriptors */
ETH_DMADescTypeDef  DMATxDscrTab[ETH_TX_DESC_CNT]; /* Ethernet Tx DMA Descriptors */

 ETH_HandleTypeDef heth;

I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart3;

PCD_HandleTypeDef hpcd_USB_OTG_FS;

/* USER CODE BEGIN PV */
uint8_t testReceiveData[60];
static const uint8_t M24512_DEV_ADDR = 0xA0;
const uint8_t addrhex[2] = "0x";
uint8_t test[13];
uint16_t memAddr;
uint8_t memHighAddr;
uint8_t memLowAddr;
uint8_t memAddrArr[12];


int errorFlag = 0;
int writeFlag = 0;
int readFlag = 0;
int i2cFlag = 0;
int clearFlag = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ETH_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USB_OTG_FS_PCD_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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

void slice(const char *str, char *result, size_t start, size_t end){
    strncpy(result, str + start, end - start);
}


void MY_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout){

	removeChar(pData,'\n');
	removeChar(pData,'\r');
	strcat(pData, "\r\n");

	HAL_UART_Transmit(&huart3, pData, strlen(pData), Timeout);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t dataBuffer[10] = {0};
	int deviceReadyFlag = 1;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ETH_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart3,testReceiveData,sizeof(testReceiveData));
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  if(deviceReadyFlag)
	  {
		  deviceReadyFlag = 0;
		  HAL_StatusTypeDef ready = HAL_I2C_IsDeviceReady(&hi2c1, M24512_DEV_ADDR, 1, 1000);
		  if (ready != HAL_OK)
			  strcpy((char*)dataBuffer, "NOT READY\r\n");
		  else
			  MY_UART_Transmit(&huart3, "READY\r\n", 7, 1000);
	  }

/*
	  HAL_StatusTypeDef stat = HAL_I2C_Mem_Write(&hi2c1, M24512_DEV_ADDR, addrTest, 8, dataTestBuffer, sizeof(dataTestBuffer), HAL_MAX_DELAY);
	  if ( stat != HAL_OK )
	  	strcpy((char*)dataBuffer, "Error Tx\r\n");

	  HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c1, M24512_DEV_ADDR, addrTest, 8, dataBuffer, sizeof(dataBuffer), HAL_MAX_DELAY);
	  if ( ret != HAL_OK )
	  {
	  	strcpy((char*)dataBuffer, "Error Rx\r\n");
	  }
	  else
	  {
	  	HAL_UART_Transmit(&huart3, "Received: ", 9, 1000);
		MY_UART_Transmit(&huart3, dataBuffer, strlen(dataBuffer), 1000);
	  }

	  HAL_Delay(1000);
*/

	if(i2cFlag)
	  	{
	  		i2cFlag = 0;
	  		if(writeFlag || clearFlag)
	  		{
	  			HAL_StatusTypeDef stat = HAL_I2C_Master_Transmit(&hi2c1, M24512_DEV_ADDR, memAddrArr, 10, 3000);
	  			if ( stat != HAL_OK )
	  			{
	  				strcpy((char*)dataBuffer, "Error MemAddr Tx\r\n");
	  				errorFlag = 1;
	  			}

	  			writeFlag = 0;
	  			clearFlag = 0;
	  		}

	  		else if(readFlag)
	  		{
	  			HAL_StatusTypeDef ret = HAL_I2C_Master_Transmit(&hi2c1, M24512_DEV_ADDR, memAddrArr, 2, 3000);
	  			if ( ret != HAL_OK )
	  			{
	  				strcpy((char*)dataBuffer, "Error MemAddrArr Tx in Rx\r\n");
	  				errorFlag = 1;
	  			}

	  			ret = HAL_I2C_Master_Receive(&hi2c1, M24512_DEV_ADDR, dataBuffer, sizeof(dataBuffer), 3000);
	  			if(ret != HAL_OK)
	  			{
	  				strcpy((char*)dataBuffer, "Error Data Rx\r\n");
	  				errorFlag = 1;
	  			}

	  			else
	  			{
	  				HAL_UART_Transmit(&huart3, "RECEIVED: ", 10, 1000);
	  				MY_UART_Transmit(&huart3, dataBuffer, strlen(dataBuffer), 1000);
	  			}
	  			readFlag = 0;
	  	  	}
	  	if(errorFlag)
	  	{
			errorFlag = 0;
			MY_UART_Transmit(&huart3, dataBuffer, strlen(dataBuffer), 1000);
	  	}
		  HAL_UART_Receive_IT(&huart3,testReceiveData,sizeof(testReceiveData));
	}
/*
		  if(i2cFlag)
	  	{
	  		i2cFlag = 0;
	  		if(writeFlag || clearFlag)
	  		{
	  			HAL_StatusTypeDef stat = HAL_I2C_Mem_Write(&hi2c1, M24512_DEV_ADDR, memAddr, 8, test, sizeof(test), 3000);
	  			if ( stat != HAL_OK )
	  			{
	  				strcpy((char*)dataBuffer, "Error Tx\r\n");
	  			}
	  			writeFlag = 0;
	  			clearFlag = 0;
	  		}

	  		else if(readFlag)
	  		{
	  			HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c1, M24512_DEV_ADDR, memAddr, 8, dataBuffer, sizeof(dataBuffer), 3000);
	  			if ( ret != HAL_OK )
	  			{
	  				strcpy((char*)dataBuffer, "Error Rx\r\n");
	  			}
	  			else
	  			{
	  				HAL_UART_Transmit(&huart3, "Received: ", 9, 1000);
	  				MY_UART_Transmit(&huart3, dataBuffer, strlen(dataBuffer), 1000);
	  			}
	  			readFlag = 0;
	  			HAL_Delay(1000);
	  	  	}

	  //MY_UART_Transmit(&huart3, dataBuffer, strlen(dataBuffer), 1000);
	  HAL_UART_Receive_IT(&huart3,testReceiveData,sizeof(testReceiveData));
	}
*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ETH Initialization Function
  * @param None
  * @retval None
  */
static void MX_ETH_Init(void)
{

  /* USER CODE BEGIN ETH_Init 0 */

  /* USER CODE END ETH_Init 0 */

   static uint8_t MACAddr[6];

  /* USER CODE BEGIN ETH_Init 1 */

  /* USER CODE END ETH_Init 1 */
  heth.Instance = ETH;
  MACAddr[0] = 0x00;
  MACAddr[1] = 0x80;
  MACAddr[2] = 0xE1;
  MACAddr[3] = 0x00;
  MACAddr[4] = 0x00;
  MACAddr[5] = 0x00;
  heth.Init.MACAddr = &MACAddr[0];
  heth.Init.MediaInterface = HAL_ETH_RMII_MODE;
  heth.Init.TxDesc = DMATxDscrTab;
  heth.Init.RxDesc = DMARxDscrTab;
  heth.Init.RxBuffLen = 1524;

  /* USER CODE BEGIN MACADDRESS */

  /* USER CODE END MACADDRESS */

  if (HAL_ETH_Init(&heth) != HAL_OK)
  {
    Error_Handler();
  }

  memset(&TxConfig, 0 , sizeof(ETH_TxPacketConfig));
  TxConfig.Attributes = ETH_TX_PACKETS_FEATURES_CSUM | ETH_TX_PACKETS_FEATURES_CRCPAD;
  TxConfig.ChecksumCtrl = ETH_CHECKSUM_IPHDR_PAYLOAD_INSERT_PHDR_CALC;
  TxConfig.CRCPadCtrl = ETH_CRC_PAD_INSERT;
  /* USER CODE BEGIN ETH_Init 2 */

  /* USER CODE END ETH_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_PCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hpcd_USB_OTG_FS.Init.dev_endpoints = 4;
  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	char *arg;
	//char *temp = strdup(addrhex);
	char *temp1 = strdup(addrhex);
	char *temp2 = strdup(addrhex);


	if(!(strncmp(testReceiveData,"W",1)))
		writeFlag = 1;
	else
		writeFlag = 0;
	if(!(strncmp(testReceiveData,"R",1)))
		readFlag = 1;
	else
		readFlag = 0;
	if(!(strncmp(testReceiveData,"C",1)))
		clearFlag = 1;
	else
		clearFlag = 0;


	if(writeFlag)
	{
		arg = strchr(testReceiveData, ',');
		if (arg != NULL)
			arg++;
		else
			;
		strcpy(test, arg);
		removeChar(test, ',');
		//removeChar(test, '\r');
		//removeChar(test, '\n');

		for(int i = 2; i < sizeof(memAddrArr); i++)
		{
			memAddrArr[i] = test[i-2];
		}

	}

	else if(clearFlag)
	{
		memset(test,0xff,sizeof(test));
		memset(memAddrArr,0xff,sizeof(memAddrArr));
	}

	else
	{
		memset(test,0,sizeof(test));
		memset(memAddrArr,0,sizeof(memAddrArr));
	}

	/*
	 * 	char addr[4] = {0};

	//slice(testReceiveData, addr, 1, 5);
	strcat(temp,addr);
	 */
	char addr1[2] = {0};
	char addr2[2] = {0};

	//slice(testReceiveData, addr, 1, 5);
	slice(testReceiveData, addr1, 1, 3);
	slice(testReceiveData, addr2, 3, 5);
	//strcat(temp,addr);
	strcat(temp1,addr1);
	strcat(temp2,addr2);

	//memAddr = (int)strtol(temp, NULL, 16);
	memHighAddr = (int)strtol(temp1, NULL, 16);
	memLowAddr = (int)strtol(temp2, NULL, 16);

	memAddrArr[0] = memHighAddr;
	memAddrArr[1] = memLowAddr;

	//MY_UART_Transmit(&huart3, temp, strlen(temp), 100);;
	MY_UART_Transmit(&huart3, testReceiveData, strlen(testReceiveData), 100);
	memset(testReceiveData,0,sizeof(testReceiveData));
	i2cFlag = 1;

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
