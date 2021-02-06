
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int i;

GPIO_InitTypeDef Led;
DAC_InitTypeDef DACstruct;

void config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	Led.GPIO_Mode=GPIO_Mode_OUT;
	Led.GPIO_OType=GPIO_OType_PP;
	Led.GPIO_PuPd=GPIO_PuPd_NOPULL;
	Led.GPIO_Speed=0x03;

	GPIO_Init(GPIOA,&Led);

	DACstruct.DAC_OutputBuffer=DAC_OutputBuffer_Enable;
	DACstruct.DAC_Trigger=DAC_Trigger_None;
	DACstruct.DAC_WaveGeneration=DAC_WaveGeneration_None;

	DAC_Init(DAC_Channel_1,&DACstruct);

	DAC_Cmd(DAC_Channel_1,ENABLE);

}

void delay(uint32_t time){

	while(time--){

	}
}
int main(void)
{
 config();

  while (1)
  {

	  for(i=2000;i<4095; i+=100){

		  DAC_SetChannel1Data(DAC_Align_12b_R,i);
		  delay(8400000);
	  }

	  i=2000;
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
