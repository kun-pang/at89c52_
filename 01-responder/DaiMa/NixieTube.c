#include <REGX52.H>

unsigned char NixieTube_Nums[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};	//0 1 2 3 4 5 6 7 8 9 标志位 -
unsigned char NixieTube_Buf[5]={0,10,10,11,10};			// 0 1 2 3 4  4个数码管，

/*******************************************************************************
  * @brief  共阴极数码管显示
  * @param which 哪一个数码管显示 值范围：1、2、4
  * @param numBer 数码管显示什么数字 值范围：0~9
  * @retval 无
*******************************************************************************/
void NixieTube_Show(unsigned char which,unsigned numBer){
	switch(which){
		case 1:
			P2_0 = 0;P2_1 = 1;P2_3=1;P2_5=1;
		break;
		case 2:
			P2_0 = 1;P2_1 = 0;P2_3=1;P2_5=1;
		break;
		case 3:
			P2_0 = 1;P2_1 = 1;P2_3=1;P2_5=0;
		break;	
		case 4:
			P2_0 = 1;P2_1 = 1;P2_3=0;P2_5=1;
		break;	
		default:
			break;
		
	}
	
	//亮哪个数字
	P0 = NixieTube_Nums[numBer];
}

/*******************************************************************************
  * @brief  设置数码管标志数组
  * @param which 几号数码管 范围：1 2 4
  * @param num 显示什么 范围：0~9 11
  * @retval 
*******************************************************************************/
void NixeTube_SetBuf(unsigned char which,unsigned char num){
	NixieTube_Buf[which]=num;
}

/*******************************************************************************
  * @brief  用于中断函数，扫描数码管状态
  * @param 无
  * @retval 无
*******************************************************************************/
void NixieTube_Time(){
	static unsigned char i=1;
	NixieTube_Show(i,NixieTube_Buf[i]);
	i++;
	if(i>=5){i=1;}
}