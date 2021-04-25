///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "main.h"
#include "menu.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern MENU_PAGE Homepage;
uint8_t BeepUseFlag=1;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void JTAGDisable(void);
/********************************************************************************
  功能：	主函数
  参数：	无
  返回：	无
  备注：	无
*********************************************************************************/
int main()
{
	uint8_t  modeflag=1,key_value;
	uint16_t temp=0;
	
  delay_init();
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  JTAGDisable();
	
  USART1_Init(115200);
  LED_Init(); 
	LED_ShowWhite();
	BEEP_Init();
  KEY_Init();
  OLED_Init();
  
	BLUETOOTH_EN = BLUETOOTH_ON;
	
  OLED_ShowLogo();
	LED_ShowLightblue();
  
  SOLGUI_Init(&Homepage);
	
  while( (++temp!=200)&&(!KEY_Scan()) )delay_ms(10);
  
  OLED_Clear();
	
  while(1)
  {
		static uint8_t flag,bluetoothflag=0;
		
		switch(KEY_USER_Scan(500))
		{
			case 1:
				BLUETOOTH_EN = BLUETOOTH_OFF;
				bluetoothflag=0;
				LED_ShowWhite();
				OLED_Init();
				BLUETOOTH_EN = BLUETOOTH_ON;
			
				temp=0;
				OLED_ShowLogo();
				while( (++temp!=100)&&(!KEY_Scan()) )delay_ms(10);
				OLED_Clear();
			
				while(KEY_USER == KEY_PRESS);
				break;
			
			case 2:
				if(modeflag)
				{
					LED_ShowGreen();
				}
				else
				{
					LED_ShowBlue();
				}
				modeflag=!modeflag;
				if(modeflag)
				{
					OLED_Clear();
					OLED_ShowText(3,10,15);
					if(BeepUseFlag)BEEP = BEEP_ON;
				}
				else
				{
					OLED_Clear();
					OLED_ShowText(3,5,9);
					if(BeepUseFlag)BEEP = BEEP_ON;
				}
				while(KEY_USER == KEY_PRESS);
				break;
		}
		
		BEEP = BEEP_OFF;
		
		if(modeflag)
		{
			
			KEY_Scan_USART();
			
			if(BLUETOOTH)
			{
				if(bluetoothflag==0)
				{
					bluetoothflag=1;
					if(BeepUseFlag)BEEP_Hint(1);
				}
				LED_ShowBlue();
				flag=1;
				OLED_Show(USART1_Buf);
			}
			else
			{
				static uint16_t time=0;
				
				if(flag==1)
				{
					OLED_Clear();
					flag=0;
				}
				
				if(time++<500)
				{
					LED_ShowRed();
					OLED_ShowText(3,16,20);
				}
				else if(time++<1500)
				{
					LED_RGB_ALLOFF();
					OLED_ShowText(3,0,4);
				}
				else
					time=0;
				
				if(bluetoothflag==1)
				{
					bluetoothflag=0;
					if(BeepUseFlag)BEEP_SlowHint(1);
				}
			}
		}
		else
		{
			flag=1;
			LED_ShowGreen();
			
			key_value=KEY_Scan();
			
			SOLGUI_InputKey(key_value);
			SOLGUI_Menu_PageStage();
			SOLGUI_Refresh();
		}
  }
}
/********************************************************************************
  功能：	禁用JTAG
  参数：	无
  返回：	无
  备注：	禁用JTAG调试，释放PA15、PB3、PB4
*********************************************************************************/
void JTAGDisable()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
