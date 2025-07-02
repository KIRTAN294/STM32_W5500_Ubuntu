/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tcp_server.h"
#include "Imu_handler.h"
#include "Bms_handler.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
FDCAN_HandleTypeDef hfdcan1;

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;

TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
//uint8_t S_ADDR[4] = {176,162,10,2};
//uint16_t S_PORT = 6565;
uint8_t RxData[8];
FDCAN_RxHeaderTypeDef RxHeader;
bool Newmessage1= false;
bool Nextmessage1 = false;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_FDCAN1_Init(void);
static void MX_TIM3_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

typedef void (*CAN_HandlerFunc)(uint32_t id, uint8_t* data, uint8_t dlc);

typedef struct {
    uint32_t can_id;
    CAN_HandlerFunc handler;
} CAN_ID_HandlerMap;

void Handlebmsmessage_wrapper(uint32_t id, uint8_t* data, uint8_t dlc) {
    Handlebmsmessage(id, data, dlc);
}

void Handleimumessage_wrapper(uint32_t id, uint8_t* data, uint8_t dlc) {
    Handleimumessage(id, data);
}

const CAN_ID_HandlerMap can_handlers[] = {
    {APP_flag_error_CANID,                Handlebmsmessage_wrapper},
    {BAT_BMS_IntTemp_CANID,              Handlebmsmessage_wrapper},
    {BAT_BMS_ExtTemp_CANID,              Handlebmsmessage_wrapper},
    {BAT_AFE_Fet_Status_CANID,           Handlebmsmessage_wrapper},
    {BAT_BMS_Charger_Load_Status_CANID,  Handlebmsmessage_wrapper},
    {BMS_Temp_Sensor_Present_CANID,      Handlebmsmessage_wrapper},
    {BAT_GAUGE_OvrVIEW_CANID,            Handlebmsmessage_wrapper},
    {BAT_GAUGE_ViT_CANID,                Handlebmsmessage_wrapper},
    {0x22,                                Handleimumessage_wrapper},
    {0x34,                                Handleimumessage_wrapper},
    {0x11,                                Handleimumessage_wrapper},
    {0x12,                                Handleimumessage_wrapper},
    {0x13,                                Handleimumessage_wrapper},
};

typedef uint8_t Commandtype;
Commandtype received_cmd;

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs){

    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK) {

        uint32_t id = RxHeader.Identifier;
        uint8_t dlc = RxHeader.DataLength;

        for (int i = 0; i < sizeof(can_handlers)/sizeof(can_handlers[0]); i++) {
            if (can_handlers[i].can_id == id) {
                can_handlers[i].handler(id, RxData, dlc);
                break;

            }
        }
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

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
  MX_DMA_Init();
  MX_FDCAN1_Init();
  MX_TIM3_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim3);

  if(HAL_FDCAN_Start(&hfdcan1)!= HAL_OK) Error_Handler();

  if(HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)  Error_Handler();

 W5500_Init();
 wizchip_setnetinfo(&netInfo);

// tcp_server_host();
// uint8_t SOCKET = socket(TCP_SOCKET,Sn_MR_TCP,LOCAL_PORT,0);
// if(SOCKET == TCP_SOCKET){
//
//	  listen(TCP_SOCKET);
//}
 uint8_t UDP_socket = socket(UDP_SOCKET,Sn_MR_UDP ,LOCAL_PORT,0);

  if(UDP_socket != UDP_SOCKET){
 	 Error_Handler();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  sendimudata();
//	  HAL_Delay(10);
//	  switch (getSn_SR(TCP_SOCKET)) {
//	          case SOCK_ESTABLISHED:
//	              if (getSn_IR(TCP_SOCKET) & Sn_IR_CON) {
//	                  setSn_IR(TCP_SOCKET, Sn_IR_CON);
//	                  Newmessage1 = false;
//	                  Nextmessage1 = false;
//	              }
//
//	              uint16_t rxSize = getSn_RX_RSR(TCP_SOCKET);
//	              if (rxSize >= sizeof(Commandtype)) {
//	                  int32_t received = recv(TCP_SOCKET, &received_cmd, sizeof(received_cmd));
//	                  if (received == sizeof(received_cmd)) {
//
//	                      if (received_cmd == Send_IMU_Data) {
//	                          Newmessage1 = true;
//	                          Nextmessage1 = false;
//	                          HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
//	                      } else if (received_cmd == Send_BMS_Data) {
//	                          Newmessage1 = false;
//	                          Nextmessage1 = true;
//	                          HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
//	                      }
//	                  }
//	              }
//	              if (Newmessage1 && getSn_SR(TCP_SOCKET) == SOCK_ESTABLISHED){
//	                  sendimudata();
//	              }
//	              if (Nextmessage1) {
//	                  sendbmsdata();
//	              }
//	              break;
//
//	          case SOCK_CLOSE_WAIT:
//	              disconnect(TCP_SOCKET);
//
//	              break;
//
//	          case SOCK_CLOSED:
//	              if (socket(TCP_SOCKET, Sn_MR_TCP, LOCAL_PORT, 0) == TCP_SOCKET) {
//	                  listen(TCP_SOCKET);
//	                  total_size = 0;
//
//	              }
//	              break;
//	           }
//	      if (getSn_IR(TCP_SOCKET) & Sn_IR_TIMEOUT) {
//	          setSn_IR(TCP_SOCKET, Sn_IR_TIMEOUT);
//	          disconnect(TCP_SOCKET);
//
//	      }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
    HAL_Delay(100);
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV4;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief FDCAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.ClockDivider = FDCAN_CLOCK_DIV1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 1;
  hfdcan1.Init.NominalSyncJumpWidth = 16;
  hfdcan1.Init.NominalTimeSeg1 = 63;
  hfdcan1.Init.NominalTimeSeg2 = 16;
  hfdcan1.Init.DataPrescaler = 2;
  hfdcan1.Init.DataSyncJumpWidth = 4;
  hfdcan1.Init.DataTimeSeg1 = 5;
  hfdcan1.Init.DataTimeSeg2 = 5;
  hfdcan1.Init.StdFiltersNbr = 3;
  hfdcan1.Init.ExtFiltersNbr = 4;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */
  FDCAN_FilterTypeDef s;

        s.FilterConfig = FDCAN_FILTER_TO_RXFIFO0 ;
        s.FilterType = FDCAN_FILTER_DUAL ;
        s.IdType= FDCAN_STANDARD_ID;
        s.FilterID1 = 0x110;
        s.FilterID2 = 0x11;
        s.FilterIndex = 0;
    if(HAL_FDCAN_ConfigFilter(&hfdcan1,&s)!= HAL_OK){

         Error_Handler();

        }
        s.FilterID1 = 0x12;
        s.FilterID2 = 0x13;
        s.FilterIndex = 1;

    if(HAL_FDCAN_ConfigFilter(&hfdcan1,&s)!= HAL_OK){

      	 Error_Handler();
        }
        s.FilterID1 = 0x22;
        s.FilterID2 = 0x34;
        s.FilterIndex = 2;

    if(HAL_FDCAN_ConfigFilter(&hfdcan1,&s)!= HAL_OK){

  	     Error_Handler();
        }
  FDCAN_FilterTypeDef Filterconfigure;

        Filterconfigure.FilterConfig = FDCAN_FILTER_TO_RXFIFO0 ;
        Filterconfigure.FilterType = FDCAN_FILTER_DUAL;
        Filterconfigure.IdType= FDCAN_EXTENDED_ID;
        Filterconfigure.FilterIndex = 0;
        Filterconfigure.FilterID1 = 0x1FF310;
        Filterconfigure.FilterID2 = 0x1FF310;
     if(HAL_FDCAN_ConfigFilter(&hfdcan1,&Filterconfigure)!= HAL_OK){

         Error_Handler();

        }

        Filterconfigure.FilterIndex = 1;
        Filterconfigure.FilterID1 = 0x1FF615;
        Filterconfigure.FilterID2 = 0x1FF110;
     if(HAL_FDCAN_ConfigFilter(&hfdcan1,&Filterconfigure)!= HAL_OK){

         Error_Handler();

        }

        Filterconfigure.FilterIndex = 2;
        Filterconfigure.FilterID1 = 0x1FF611;
        Filterconfigure.FilterID2 = 0x1FF612;
     if(HAL_FDCAN_ConfigFilter(&hfdcan1,&Filterconfigure)!= HAL_OK){

         Error_Handler();

        }

        Filterconfigure.FilterIndex = 3;
        Filterconfigure.FilterID1 = 0x1FF810;
        Filterconfigure.FilterID2 = 0x1FF820;
     if(HAL_FDCAN_ConfigFilter(&hfdcan1,&Filterconfigure)!= HAL_OK){

      	 Error_Handler();

        }
  /* USER CODE END FDCAN1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 159;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMAMUX1_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|CS_PIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 CS_PIN_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|CS_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
