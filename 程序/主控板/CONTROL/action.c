///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-车辆动作
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "action.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/********************************************************************************
    功能：	车辆运行
    参数：	speedl 左电机速度
					speedr 右电机速度
    返回：	无
    备注：	无
*********************************************************************************/
void Car_Run(int16_t speedl,int16_t speedr)
{
	if(speedl>=0)
	{
		MotorL_P		=	speedl;
		MotorL_N		=	0;
	}			
	else			
	{
		MotorL_P		=	0;
		MotorL_N		=	-speedl;
	}	
		
	if(speedr>=0)	
	{
		MotorR_P		=	speedr;
		MotorR_N		=	0;
	}			
	else			
	{
		MotorR_P		=	0;
		MotorR_N		=	-speedr;
	}
}
/********************************************************************************
    功能：	等待启动指令
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
uint8_t Car_WaitCMD(void)
{
	while((IR_RM_Judge)||(IR_RB_Judge)||(IR_RF_Judge)){}
	LED_RGB_ALLON();
	delay_ms(100);
	LED_RGB_ALLOFF();
	delay_ms(100);
	LED_RGB_ALLON();
	delay_ms(100);
	LED_RGB_ALLOFF();
	while((!IR_RM_Judge)&&(!IR_RB_Judge)&&(!IR_RF_Judge))
	{
		if(UART4_Res==__KEY_BACK)
			return 0;
	}
	return 1;
}
/********************************************************************************
    功能：	判断车辆位置
    参数：	无
    返回：	1	台下
			0	台上
    备注：	无
*********************************************************************************/
uint8_t Judge_Location(void)
{
	if((OS_L_Judge&&OS_R_Judge))
	{
		if(GRAY_FL_Judge+GRAY_FR_Judge+GRAY_BL_Judge+GRAY_BR_Judge>=3)
		{
			if((IR_FL_JudgeFall||IR_FML_JudgeFall||IR_FMR_JudgeFall||IR_FR_JudgeFall)&&(IR_BL_JudgeFall||IR_BM_JudgeFall||IR_BR_JudgeFall))
				return 1;
			else if((IR_LF_JudgeFall||IR_LM_JudgeFall||IR_LB_JudgeFall)&&(IR_RF_JudgeFall||IR_RM_JudgeFall||IR_RB_JudgeFall))  
				return 1;
		}
	}
	return 0;		
}
/********************************************************************************
    功能：	判断车辆位置
    参数：	无
    返回：	1	角落
			0	非角落
    备注：	无
*********************************************************************************/
uint8_t Judge_Location_Corner(void)
{
	if(0)//((IR_LF_JudgeFall||IR_LM_JudgeFall)||(IR_RF_JudgeFall||IR_RM_JudgeFall))&&IR_BM_JudgeFall)
		return 1;
	else if(!IR_FML_JudgeFall&&!IR_FMR_JudgeFall&&!IR_BM_JudgeFall)
		return 0;
	else if(!IR_FL_JudgeFall&&!IR_BR_JudgeFall)
		return 0;
	else if(!IR_FR_JudgeFall&&!IR_BL_JudgeFall)
		return 0;
	else if(!IR_LF_JudgeFall&&!IR_RB_JudgeFall)
		return 0;
	else if(!IR_RF_JudgeFall&&!IR_LB_JudgeFall)
		return 0;
	else if(!IR_RM_JudgeFall&&!IR_LM_JudgeFall)
		return 0;
	return 1;		
}
/********************************************************************************
    功能：	寻找角落
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void Car_FindCorner(void)
{
	Car_Run(200,200);
	delay_ms(200);
	if(!Judge_Location_Corner())
		while(!(IR_LF_JudgeFall&&IR_LM_JudgeFall&&IR_LB_JudgeFall)&&!(IR_RF_JudgeFall&&IR_RM_JudgeFall&&IR_RB_JudgeFall))
		{
			Car_Run( 300,-300);
			WirelessStop();//无线遥控死机保护
		}
	while(!Judge_Location_Corner())
	{
		uint16_t temp=5000;
		if(IR_FL_Judge&&IR_FR_Judge)
			Car_Run(300, 300);
		else if(IR_FL_Judge)
			Car_Run( 100,-100);
		else if(IR_FR_Judge)
			Car_Run(-100, 100);
		else
			Car_Run(300, 300);
		if(temp--==0)return;
		delay_ms(1);
	}
	Car_Run(0, 0);
	delay_ms(10);
	while(!Judge_Location_Corner())
	{
		uint16_t temp=5000;
		if(IR_FL_Judge&&IR_FR_Judge)
			Car_Run(300, 300);
		else if(IR_FL_Judge)
			Car_Run( 100,-100);
		else if(IR_FR_Judge)
			Car_Run(-100, 100);
		else
			Car_Run(300, 300);
		if(temp--==0)return;
		delay_ms(1);
	}
}
/********************************************************************************
    功能：	离开角落
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void Car_LeaveCorner(void)
{
	uint16_t temp=0;
	while(!(IR_BALL_Judge&&(IR_BM_JudgeFall+IR_LM_JudgeFall==1)&&!IR_TF_Judge))
	{
		Car_Run(-200, 200);
		WirelessStop();//无线遥控死机保护
//		temp++;
//		delay_ms(1);
//		if(temp>=1000)
//		{
//			Car_Run( 200,200);
//			delay_ms(1000);
//			temp=0;
//		}
	}
//	while(Judge_Location_Corner())
//	{
		Car_Run(-200, -200);
		delay_ms(1000);
		Car_Run(200, 200);
		delay_ms(1000);
//		delay_ms(500);
//	}
	
	while(temp<=1000)
	{
		if(IR_FL_Judge&&IR_FR_Judge)
			Car_Run(300, 300);
		else if(IR_FL_Judge)
			Car_Run( 100,-100);
		else if(IR_FR_Judge)
			Car_Run(-100, 100);
		else
			Car_Run(300, 300);
		temp++;
		delay_ms(1);
	}
		Car_Run(0, 0);
}
/********************************************************************************
    功能：	面对擂台
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void Car_FaceRing(void)
{
	Car_Run(-200,200);
	while(!(WAVE_BL_Judge&&WAVE_BR_Judge&&!IR_TF_Judge))
	{WirelessStop();}//无线遥控死机保护
	Car_Run(0,0);
	delay_ms(100);
	while(abs(WAVE_BL-WAVE_BR)>=3&&(WAVE_BL_Judge&&WAVE_BR_Judge&&!IR_TF_Judge))
	{
		if(WAVE_BL>WAVE_BR)
		{
			Car_Run(-100,100);
		}
		else
		{
			Car_Run(100,-100);
		}
		WirelessStop();//无线遥控死机保护
	}
	Car_Run(-300,-300);
	delay_ms(500);
	Car_Run(0,0);
	delay_ms(400);
//	Car_Jump();
		
}
/********************************************************************************
    功能：	车辆跳台
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void Car_Jump(void)
{
	Car_Run(450,450);
	delay_ms(130);
	MotorJ_N=0;
	MotorJ_P=90;
	delay_ms(120);
	while(IR_JUMP_Judge)
	{
		if(UART4_Res==__KEY_BACK)
			return;
	}
	MotorJ_P=10;
	while(!IR_JUMP_Judge)
	{
		if(UART4_Res==__KEY_BACK)
			return;
	}
	MotorJ_P=0;
//	MotorJ_N=30;
//	while(!IR_JUMP_Judge)
//	{
//		if(UART4_Res==__KEY_BACK)
//			return;
//	}
	MotorJ_N=0;
	delay_ms(400);
	Car_Run(0,0);
}
//{
//	Car_Run(450,450);
//	delay_ms(130);
//	MotorJ_N=0;
//	MotorJ_P=90;
//	delay_ms(220);
//	MotorJ_P=0;
////	MotorJ_N=30;
////	while(!IR_JUMP_Judge)
////	{
////		if(UART4_Res==__KEY_BACK)
////			return;
////	}
//	MotorJ_N=0;
//	delay_ms(400);
//	Car_Run(0,0);
//}
/********************************************************************************
    功能：	推棋子时某个红外发现目标
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void PutChess_FM_Find(uint16_t waittime)
{
	#define AttackSpeed_PushChess (400-(GRAY_FL+GRAY_FR)/60)
	uint16_t time=0;
	
	Car_Run(AttackSpeed_PushChess,AttackSpeed_PushChess);
	
	//如果目标是箱子
	if(IR_FL_Judge||IR_FR_Judge)return;
	
	//如果目标是棋子，猛冲一次，甩飞棋子
	while(IR_FML_Judge||IR_FMR_Judge)
	{
		if(GRAY_FL_Judge||GRAY_FR_Judge)
		{
			return;
		}
		if(time>=waittime)
		{
			Car_Run(900,900);
			delay_ms(70);
			Car_Run(0,0);
			delay_ms(300);
			return;
		}
		else
		{
			time++;
			delay_ms(1);
		}
		WirelessStop();//无线遥控死机保护
	}
	return;
}
void PutChess_L_Find(uint16_t speed,uint16_t waittime)
{
	uint16_t time=0;
	
	Car_Run(-speed, speed);
				
	while(!(IR_FML_Judge||IR_FMR_Judge))
	{
		if(time>=waittime)
		{
			return;
		}
		else
		{
			time++;
			delay_ms(1);
		}
		WirelessStop();//无线遥控死机保护
	}
	return;
}
void PutChess_R_Find(uint16_t speed,uint16_t waittime)
{
	uint16_t time=0;
	
	Car_Run( speed, -speed);
				
	while(!(IR_FML_Judge||IR_FMR_Judge))
	{
		if(time>=waittime)
		{
			return;
		}
		else
		{
			time++;
			delay_ms(1);
		}
		WirelessStop();//无线遥控死机保护
	}
	return;
}
/********************************************************************************
    功能：	车辆推棋子模式
    参数：	无
    返回：	无
    备注：	无
*********************************************************************************/
void Car_PutChess(void)
{	
	#define SearchSpeed1 (((350-(GRAY_FL+GRAY_FR)/10)>=200)?(350-(GRAY_FL+GRAY_FR)/10):200)
	BEEP_USING_FLAG=1;
	while(UART4_Res!=__KEY_BACK&&!KEY_R_Scan())
	{
		BEEP=BEEP_OFF;
//========================台边检测========================
		IF((OS_L_Judge||OS_R_Judge),
		{
			BEEP=BEEP_ON;
			Car_Run(-300,-300);
			
			//如果前方红外仍有值，说明是箱子，延长后退时间
			if(IR_FML_Judge||IR_FMR_Judge)
				delay_ms(600);
			else
				delay_ms(400);
			
			Car_Run(500,-500);
			delay_ms(130);
		})
//========================前红外扫到=======================
		else IF((IR_FML_Judge||IR_FMR_Judge),
		{
			PutChess_FM_Find(WaitTimeFM);
			continue;
		})
//========================左红外扫到=======================
		else IF((IR_FL_Judge),//左
		{
			PutChess_L_Find(TurnSpeedFL,WaitTimeFL);
			continue;
		})
		else IF((IR_LF_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLF,WaitTimeLF);
			continue;
		})
		else IF((IR_LM_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLM,WaitTimeLM);
			continue;
		})
		else IF((IR_LB_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLB,WaitTimeLB);
			continue;
		})
		else IF((IR_BL_Judge),//左
		{
			PutChess_L_Find(TurnSpeedBL,WaitTimeBL);
			continue;
		})
		else IF((IR_BM_Judge),//左
		{
			PutChess_L_Find(TurnSpeedBM,WaitTimeBM);
			continue;
		})
//========================右红外扫到=======================
		else IF((IR_FR_Judge),//右
		{
			PutChess_R_Find(TurnSpeedFR,WaitTimeFR);
			continue;
		})
		else IF((IR_RF_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRF,WaitTimeRF);
			continue;
		})
		else IF((IR_RM_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRM,WaitTimeRM);
			continue;
		})
		else IF((IR_RB_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRB,WaitTimeRB);
			continue;
		})
		else IF((IR_BR_Judge),//右
		{
			PutChess_R_Find(TurnSpeedBR,WaitTimeBR);
			continue;
		})
		else IF((IR_BM_Judge),//右
		{
			PutChess_R_Find(TurnSpeedBM,WaitTimeBM);
			continue;
		})
//======================没有红外扫到=====================
		else//灰度值精确后，可加上当灰度判断到台边即后撤
		{
//				IF((GRAY_F_Judge),
//				{
//					Car_Run(-200,-200);
//					delay_ms(150);
//					
//					Car_Run(500,-500);
//					delay_ms(100);
//				})
//				else
			Car_Run(SearchSpeed1,SearchSpeed1);
			continue;
		}
	}
	
	BEEP_USING_FLAG=0;
	Car_Run(0,0);
}
/********************************************************************************
    功能：	车辆打擂台模式1
    参数：	无
    返回：	无
    备注：	瞎jb扫台
*********************************************************************************/
void Car_Battle(void)
{	
	#define SearchSpeed2 0//(((200-(GRAY_FL+GRAY_FR)/40)>=100)?(200-(GRAY_FL+GRAY_FR)/40):100)
	uint8_t FanSwitch=0;
	BEEP_USING_FLAG=1;
	while(UART4_Res!=__KEY_BACK&&!KEY_R_Scan())
	{
		if(Judge_Location())
		{
			Car_FindCorner();
			Car_LeaveCorner();
			Car_FaceRing();
			Car_Jump();
			continue;
		}
		else
		{
//========================台边检测========================
			if(OS_L_Judge||OS_R_Judge)
			{
				if(!(IR_FML_Judge||IR_FMR_Judge)||(OS_L_Judge&&OS_R_Judge))
				{
					uint16_t Waittime=1000;
					FanSwitch=1;
					TestFan=50;
					Car_Run(-300,-300);
					delay_ms(300);
					Car_Run(0,0);
					while(Waittime--)
					{
						if(IR_ALL_Judge)break;
						delay_ms(1);
					}
					if(Waittime<=1)
					{
						Car_Run(500,-500);
						delay_ms(250);
					}
				}
			}
//=======================前红外检测=======================
			if(IR_FML_Judge&&IR_FMR_Judge)
			{
				static uint16_t FanOpenTime=0;
				
				BEEP=BEEP_OFF;
				
				Car_Run(900,900);
				if(FanSwitch==1)
				{
					TestFan=75;
					FanOpenTime++;
					delay_ms(1);
					if(FanOpenTime>=9000)
						FanSwitch=0;
				}
				else
				{
					TestFan=50;
					FanOpenTime=0;
				}
				
			}
			else if(IR_FML_Judge)
			{
				BEEP=BEEP_OFF;
				Car_Run(700,900);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_FMR_Judge)
			{
				BEEP=BEEP_OFF;
				Car_Run(900,700);
				FanSwitch=1;
				TestFan=50;
			}
//=======================左红外检测=======================
			else if(IR_FL_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_L_Find(300,100);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_LF_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_L_Find(350,200);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_LM_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_L_Find(400,300);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_LB_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_L_Find(450,400);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_BL_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_L_Find(500,500);
				FanSwitch=1;
				TestFan=50;
			}
//=======================右红外检测=======================
			else if(IR_FR_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(300,100);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_RF_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(350,200);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_RM_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(400,300);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_RB_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(450,350);
				FanSwitch=1;
				TestFan=50;
			}
			else if(IR_BR_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(500,400);
				FanSwitch=1;
				TestFan=50;
			}
//=======================后红外检测=======================
			else if(IR_BM_Judge)
			{
				BEEP=BEEP_ON;
				PutChess_R_Find(550,450);
				FanSwitch=1;
				TestFan=50;
			}
			else
			{
				BEEP=BEEP_OFF;
				Car_Run(SearchSpeed2,SearchSpeed2);
				FanSwitch=1;
				TestFan=50;
			}
		}
	BEEP_USING_FLAG=0;
	}
}
/********************************************************************************
    功能：	车辆打擂台模式2
    参数：	无
    返回：	无
    备注：	瞎jb扫台
*********************************************************************************/
void Car_Battle2(void)
{	
	#define SearchSpeed3 (((200-(GRAY_FL+GRAY_FR)/40)>=100)?(200-(GRAY_FL+GRAY_FR)/40):100)
	BEEP_USING_FLAG=1;
	while(UART4_Res!=__KEY_BACK&&!KEY_R_Scan())
	{
		BEEP=BEEP_OFF;
		if(Judge_Location())
		{
			Car_FindCorner();
			Car_LeaveCorner();
			Car_FaceRing();
			Car_Jump();
			continue;
		}
		else
		{
//========================台边检测========================
		IF((OS_L_Judge||OS_R_Judge),
		{
			if(!(IR_FML_Judge||IR_FMR_Judge)||(OS_L_Judge&&OS_R_Judge))
			{
				BEEP=BEEP_ON;
				Car_Run(-300,-300);
				delay_ms(400);
				
				Car_Run(500,-500);
				delay_ms(130);
			}
		})
//========================前红外扫到=======================
		else IF((IR_FML_Judge||IR_FMR_Judge),
		{
			Car_Run(900,900);
			continue;
		})
//========================左红外扫到=======================
		else IF((IR_FL_Judge),//左
		{
			PutChess_L_Find(TurnSpeedFL,WaitTimeFL);
			continue;
		})
		else IF((IR_LF_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLF,WaitTimeLF);
			continue;
		})
		else IF((IR_LM_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLM,WaitTimeLM);
			continue;
		})
		else IF((IR_LB_Judge),//左
		{
			PutChess_L_Find(TurnSpeedLB,WaitTimeLB);
			continue;
		})
		else IF((IR_BL_Judge),//左
		{
			PutChess_L_Find(TurnSpeedBL,WaitTimeBL);
			continue;
		})
		else IF((IR_BM_Judge),//左
		{
			PutChess_L_Find(TurnSpeedBM,WaitTimeBM);
			continue;
		})
//========================右红外扫到=======================
		else IF((IR_FR_Judge),//右
		{
			PutChess_R_Find(TurnSpeedFR,WaitTimeFR);
			continue;
		})
		else IF((IR_RF_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRF,WaitTimeRF);
			continue;
		})
		else IF((IR_RM_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRM,WaitTimeRM);
			continue;
		})
		else IF((IR_RB_Judge),//右
		{
			PutChess_R_Find(TurnSpeedRB,WaitTimeRB);
			continue;
		})
		else IF((IR_BR_Judge),//右
		{
			PutChess_R_Find(TurnSpeedBR,WaitTimeBR);
			continue;
		})
		else IF((IR_BM_Judge),//右
		{
			PutChess_R_Find(TurnSpeedBM,WaitTimeBM);
			continue;
		})
//======================没有红外扫到=====================
		else//灰度值精确后，可加上当灰度判断到台边即后撤
		{
//				IF((GRAY_F_Judge),
//				{
//					Car_Run(-200,-200);
//					delay_ms(150);
//					
//					Car_Run(500,-500);
//					delay_ms(100);
//				})
//				else
			Car_Run(SearchSpeed3,SearchSpeed3);
			continue;
		}
	}
}
	BEEP_USING_FLAG=0;
	Car_Run(0,0);
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
