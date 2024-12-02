#include <REGX52.H>


/*******************************************************************************
  * @brief  初始化定时器0 1ms溢出1次
  * @param 无
  * @retval 无
*******************************************************************************/
void TIM0_Init(){
	EA=1;
	ET0=1;
	
	TMOD&=0xF0;			//定时器0 模式1
	TMOD|=0x01;
	
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	
	TR0=1;
	TF0=0;
}