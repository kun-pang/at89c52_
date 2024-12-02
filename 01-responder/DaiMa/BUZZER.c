#include <REGX52.H>
#include <INTRINS.H>

sbit buzzer_BEEP = P2^2;


/*******************************************************************************
  * @brief  蜂鸣器私有延时函数 指定延时500ms
  * @param 无
  * @retval 无
*******************************************************************************/
void Buzzer_Delay500us(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



/*******************************************************************************
   * @brief：蜂鸣器发声时间
   * @param：ms 以发声多少时间
   * @retval：无
*******************************************************************************/
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i = 0; i < ms * 2; i++)				//以ms为周期  1/ms为频率    一个for循环为500us（0.5ms）*2  =》1ms
	{
		buzzer_BEEP = !buzzer_BEEP;			//翻转  不同频率输出，以此振动
		Buzzer_Delay500us();
	}
	
}