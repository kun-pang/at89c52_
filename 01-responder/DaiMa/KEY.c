#include <REGX52.H>

#include "Delay.h"

//选数按键1~8
sbit KEY_Player1=P3^0;
sbit KEY_Player2=P3^1;
sbit KEY_Player3=P3^2;
sbit KEY_Player4=P3^3;
sbit KEY_Player5=P3^4;
sbit KEY_Player6=P3^5;
sbit KEY_Player7=P3^6;
sbit KEY_Player8=P3^7;

sbit KEY_Compere=P2^7;

unsigned char KEY_Vaule;

/*******************************************************************************
  * @brief  按键键码扫描
  * @param 无
  * @retval KeyNum返回键码值（未消抖）
*******************************************************************************/
unsigned char Key(){
	unsigned char KeyNum = 0;
	
	if(KEY_Player1 == 0){KeyNum = 1;}
	if(KEY_Player2 == 0){KeyNum = 2;}
	if(KEY_Player3 == 0){KeyNum = 3;}
	if(KEY_Player4 == 0){KeyNum = 4;}
	if(KEY_Player5 == 0){KeyNum = 5;}
	if(KEY_Player6 == 0){KeyNum = 6;}
	if(KEY_Player7 == 0){KeyNum = 7;}
	if(KEY_Player8 == 0){KeyNum = 8;}
	if(KEY_Compere == 0){KeyNum = 9;}
			
	return KeyNum;
}

/*******************************************************************************
  * @brief  用于中断函数中，扫描按键状态
  * @param 无
  * @retval 无
*******************************************************************************/
void KEY_Time(){
	static unsigned char latsNum,nowNum;
	latsNum=nowNum;
	nowNum=Key();
	if(latsNum!=0 && nowNum==0){			//检测按键是否抬起
		KEY_Vaule=latsNum;
	}
}

/*******************************************************************************
  * @brief  放回具体键码值
  * @param 无
  * @retval temp 具体键码
*******************************************************************************/
unsigned char KEY_GetVaule(){
	unsigned char temp;
	temp=KEY_Vaule;
	KEY_Vaule=0;
	return temp;
}