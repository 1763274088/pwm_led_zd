#include "music.h" 

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"

// ��������������������硷
const tNote MyScore[]=
{
  {L6,TT/4},{L3,TT/8},{L5,TT/8},{L6,TT/4},{L6,TT/8},{M1,TT/8},{M1,TT/4},{M2,TT/8},{M1,TT/8},{L6,TT/2},{M1,TT/4},{M1,TT/8},{L5,TT/8},{M1,TT/8},{M2,TT/8},{M3,TT/8},{M5,TT/8},
  {M5,TT/8},{M3,TT/8},{M2,TT/4},{M3,TT/2},{M6,TT/8},{M6,TT/8},{M6,TT/8},{M5,TT/8},{M3,TT/8},{M3,TT/4},{M1,TT/8},{L6,TT/8},{L6,TT/8},{L6,TT/8},{M3,TT/8},//��ã���������ҵİ���������ѽ��ҡ
  {M2,TT/2},{M3,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/8},{L6,TT/4},{L5,TT/4},{L6,TT/2}, //�ڣ�ʲô���ĸ����������
  {L6,TT/4},{L3,TT/8},{L5,TT/8},{L6,TT/4},{L6,TT/8},{M1,TT/8},{M1,TT/4},{M2,TT/8},{M1,TT/8},{L6,TT/2},{M1,TT/4},{M1,TT/8},{L5,TT/8},{M1,TT/8},{M2,TT/8},{M3,TT/8},{M5,TT/8},
  {M5,TT/8},{M3,TT/8},{M2,TT/4},{M3,TT/2},{M6,TT/8},{M6,TT/8},{M6,TT/8},{M5,TT/8},{M3,TT/8},{M3,TT/4},{M1,TT/8},{L6,TT/8},{L6,TT/8},{L6,TT/8},{M3,TT/8},//��ã���������ҵİ���������ѽ��ҡ
  {M2,TT/2},{M3,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/8},{L6,TT/4},{L5,TT/4},{L6,TT/2}, //�ڣ�ʲô���ĸ����������
  {M3,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M3,TT/8},{M5,TT/8},{M5,TT/8},{M6,TT/8},{H1,TT/8},{M6,TT/8},{M5,TT/4},{M6,TT/2},{L6,TT/4},{L6,TT/8},
  {L5,TT/8},{L6,TT/4},{M1,TT/4},{M2,TT/8},{M3,TT/16},{M2,TT/16},{M1,TT/8},{M2,TT/8},{M3,TT/2},{L6,TT/8},{M6,TT/8},{M6,TT/8},{M5,TT/8},{M2,TT/8},{M3,TT/16},{M2,TT/16},
  {M1,TT/8},{M2,TT/8},{M3,TT/2},//������
  {M1,TT/8},{L6,TT/8},{L6,TT/8},{M1,TT/8},{M2,TT/4},{L5,TT/8},{L5,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/2},{L6,TT/8},{M1,TT/8},{M2,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/8},
  {L5,TT/8},{L3,TT/8},{L6,TT/2},{L6,TT/4},{L6,TT/8},{L5,TT/8},{L6,TT/4},{M1,TT/4},{M2,TT/8},{M3,TT/16},{M2,TT/16},{M1,TT/8},{M2,TT/8},{M3,TT/2},{L6,TT/8},{M6,TT/8},
  {M6,TT/8},{M5,TT/8},{M2,TT/8},{M3,TT/16},{M2,TT/16},
  {M1,TT/8},{M2,TT/8},{M3,TT/2},//������
  {M1,TT/8},{L6,TT/8},{L6,TT/8},{M1,TT/8},{M2,TT/4},{L5,TT/8},{L5,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/4+TT/8},{M1,TT/8},{L6,TT/8},
  {M1,TT/8},{M2,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M3,TT/8},{M5,TT/8},{M6,TT/2},{M6,TT/2},{L6,TT/4},{L6,TT/8},{L5,TT/8},{L6,TT/4},
  {L6,TT/8},{M1,TT/8},{M2,TT/8},{M3,TT/16},{M2,TT/16},{M1,TT/8},{M2,TT/8},{M3,TT/2},
  {M6,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/8},{M1,TT/2},//����������������̨
  {L6,TT/4},{L6,TT/8},{L5,TT/8},{L6,TT/4},{M1,TT/4},{M2,TT/8},{M3,TT/16},{M2,TT/16},{M1,TT/8},{M2,TT/8},{M3,TT/2},{L6,TT/8},{M6,TT/8},{M6,TT/8},{M5,TT/8},{M2,TT/8},{M3,TT/16},{M2,TT/16},
  {M1,TT/8},{M2,TT/8},{M3,TT/2},//������
  {M1,TT/8},{L6,TT/8},{L6,TT/8},{M1,TT/8},{M2,TT/4},{L5,TT/8},{L5,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/2},{L6,TT/8},{M1,TT/8},{M2,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/8},
  {L5,TT/8},{L3,TT/8},{L6,TT/2},{L6,TT/4},{L6,TT/8},{L5,TT/8},{L6,TT/4},{M1,TT/4},{M2,TT/8},{M3,TT/16},{M2,TT/16},{M1,TT/8},{M2,TT/8},{M3,TT/2},{L6,TT/8},{M6,TT/8},
  {M6,TT/8},{M5,TT/8},{M2,TT/8},{M3,TT/16},{M2,TT/16},
  {M1,TT/8},{M2,TT/8},{M3,TT/2},//������
  {M1,TT/8},{L6,TT/8},{L6,TT/8},{M1,TT/8},{M2,TT/4},{L5,TT/8},{L5,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M2,TT/8},{M1,TT/4+TT/8},{M1,TT/8},{L6,TT/8},
  {M1,TT/8},{M2,TT/8},{M3,TT/8},{M5,TT/8},{M3,TT/8},{M3,TT/8},{M5,TT/8},{M6,TT/2},{M6,TT/2},
  {0,0},
};


//����������ָ��Ƶ�ʵ�����
//usFreq�Ƿ���Ƶ�ʣ�ȡֵ (ϵͳʱ��/65536)+1 �� 20000����λ��Hz
void buzzerSound(unsigned short usFreq)	 
{
//		GPIO_InitTypeDef  GPIO_InitStructure;
		  unsigned long  ulVal;


//		GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5    
//			 //���ø�����Ϊ�����������,���TIM3 CH2��PWM���岨��	GPIOB.5
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //TIM_CH2
//		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
//		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//		GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO	  
			ulVal=usFreq;
		  TIM_SetCompare1(TIM14,ulVal);	//�޸ıȽ�ֵ���޸�ռ�ձ�  
}





// ��������
void musicPlay(void) 
{ 
		u8 i=0; 
		while(1) 
		{ 
				if (MyScore[i].mTime == 0) break; 
				buzzerSound(MyScore[i].mName); 
					 delay_ms(MyScore[i].mTime);
				i++; 
////				buzzerQuiet(); // ����������
				delay_ms(10);// 10 ms 
		} 
} 

