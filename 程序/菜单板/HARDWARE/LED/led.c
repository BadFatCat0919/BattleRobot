///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���ߵ��Բ˵���-LED����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "led.h"
/********************************************************************************
  ���ܣ�	LED��ʼ��
  ������	��
  ���أ�	��
  ��ע��	��ʼ����LEDĬ�Ϲر�
*********************************************************************************/
void LED_Init()
{
  GPIO_InitTypeDef  GPIO_InitStructure;										//������ʼ���ṹ��
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
                                                          //��GPIOʱ��
  GPIO_StructInit(&GPIO_InitStructure);                   //Ϊ��ʼ���ṹ�帳ȱʡֵ
  GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_Out_PP;       //����IOģʽΪ�������
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_11|GPIO_Pin_15;
  GPIO_Init(GPIOA, &GPIO_InitStructure);							    //��ȡ��ʼ���ṹ���ֵ
  GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_3;             //���ó�ʼ�����ű��
  GPIO_Init(GPIOB, &GPIO_InitStructure);							    //��ȡ��ʼ���ṹ���ֵ
  
	LED_USER=LED_USER_ON;
  LED_R = LED_RGB_OFF;                                     //IO��ʼ����ɺ�ر�LED
  LED_G = LED_RGB_OFF;                                     //IO��ʼ����ɺ�ر�LED
  LED_B = LED_RGB_OFF;                                     //IO��ʼ����ɺ�ر�LED
	BLUETOOTH_EN=BLUETOOTH_OFF;
}
/********************************************************************************
	���ܣ�	LED_User��˸
	������	time	��˸Ƶ�ʣ����������ж��ٴ�ʱ�ı�LED_User����״̬��
	���أ�	��
	��ע��	��
*********************************************************************************/
void LED_User_Flash( uint16_t time)
{
	  static int temp;
	  if(time==0)
	  	LED_USER=LED_USER_OFF;
	  else
	  	if(++temp==time)
				LED_USER=!LED_USER,temp=0;
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
