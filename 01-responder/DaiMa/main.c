#include <REGX52.H>

#include "KEY.h"
#include "NixieTube.h"
#include "TIME.h"
#include "BUZZER.h"

unsigned char KeyNum;
unsigned char Flag=1;		//倒计时标志
unsigned char PlayerFlag=0;			//选手选择标志
unsigned char SecNum=10;

void Sec(){
	if(Flag){
		if(SecNum<=0){
			Flag=!Flag;
		}
		SecNum--;
	}
}

void main(){
	TIM0_Init();
	
	
	while(1){
		KeyNum=KEY_GetVaule();
		switch(KeyNum){
			case 1:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,1);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(100);
				}			
				break;
			case 2:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,2);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(200);
				}	
				break;
			case 3:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,3);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(300);
				}	
				break;
			case 4:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,4);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(400);
				}	
				break;
			case 5:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,5);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(500);
				}	
				break;
			case 6:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,6);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(600);
				}	
				break;
			case 7:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,7);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(700);
				}	
				break;
			case 8:
				if(!PlayerFlag){
					NixeTube_SetBuf(4,8);
					SecNum=60;
					PlayerFlag=1;
					Buzzer_Time(800);
				}	
				break;
			case 9:							//主持人按钮 清零或者抢答
				NixeTube_SetBuf(4,0);
				SecNum=10;
				PlayerFlag=0;
				Flag=1;
				break;
		}

		NixeTube_SetBuf(1,SecNum/10);
		NixeTube_SetBuf(2,SecNum%10);

		
		
	}
}


void TIM0_Routine() interrupt 1
{
		static unsigned int T0Key,T0NixeTube,T0Sec;
		TL0 = 0x18;				
		TH0 = 0xFC;				
		T0Key++;
		T0NixeTube++;
		T0Sec++;
		if(T0Key >= 20)			//20ms 扫描一次按键
		{
			T0Key = 0;
			KEY_Time();
			
		}
		if(T0NixeTube >= 2)			//2ms 扫描一次数码管
		{
			T0NixeTube = 0;
			NixieTube_Time();
		}
		if(T0Sec>=1000){
			T0Sec=0;
			Sec();
		}
}