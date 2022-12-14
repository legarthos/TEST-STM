/* ************************************************************************************************************************
 * ************************************************************************************************************************
 * Bare Metal (Low Layer/Register) / Standard Peripheral Library (SPL) / Hardware Abstraction Layer Library (HAL)
 * By Mustafa Onur Parlak
 * GitHub Link: https://github.com/legarthos
 * ***********************************************************************************************************************/
/* ************************************************************************************************************************
 * Project Purpose:
 * It contains the basic notes and contents I took while learning STM32 with LL-SPL-HAL DRIVER.
 * General Draft Code Style with Standard Peripheral Library
 *
 * ************************************************************************************************************************
 * Peripherals to be used:
 * GPIO (General Purpose Input Output)
 *
 * ************************************************************************************************************************
 * Update Time and Reason:
 * 2022.28.10 - Initialize
 *
 * ************************************************************************************************************************/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

void GPIO_Configuration();
void delay(uint32_t time);

int main(void) {
	GPIO_Configuration();

	while (1) {
		GPIO_SetBits(GPIOD, GPIO_Pin_All);
		delay(1680000);

		GPIO_ResetBits(GPIOD, GPIO_Pin_All);
		delay(3360000);
	}
}

void GPIO_Configuration() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void delay(uint32_t time) {
	while(time--);
}

extern "C" void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size) {return;}
extern "C" uint16_t EVAL_AUDIO_GetSampleCallBack(void) {return -1;}
