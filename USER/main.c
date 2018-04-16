#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"


//ALIENTEK ̽����STM32F407������ ʵ��9
//PWM���ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//�������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK

int main(void)
{ 
	u16 led0pwmval=0;    
	u8 dir=1;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM14_PWM_Init(2000-1,840-1);	//84M/840=1Mhz/10�ļ���Ƶ��,��װ��ֵ2000������PWMƵ��Ϊ 1M/10/2000=2Khz/4/10.     
////		TIM14_PWM_Init(500-1,840-1);	//84M/840=1Mhz/10�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/10/500=2Khz/10.     
   while(1) //ʵ�ֱȽ�ֵ��0-300��������300���300-0�ݼ���ѭ��
	{
		
 		delay_ms(1);	 
		if(dir)led0pwmval++;//dir==1 led0pwmval����
		else led0pwmval--;	//dir==0 led0pwmval�ݼ� 
 		if(led0pwmval>2000)dir=0;//led0pwmval����300�󣬷���Ϊ�ݼ�
		if(led0pwmval==0)dir=1;	//led0pwmval�ݼ���0�󣬷����Ϊ����
 
		TIM_SetCompare1(TIM14,led0pwmval);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//		TIM_SetCompare1(TIM14,0);	//�޸ıȽ�ֵ���޸�ռ�ձ�
	}
}