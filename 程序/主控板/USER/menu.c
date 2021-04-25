///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-菜单
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "menu.h"
#include "main.h"
#include "data.h"
#include "modes.h"
#include "adc.h"
#include "action.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
extern uint16_t fan;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void WirelessRun(void);
void Test_PID(void);
void Test_Jump(void);
void Test_Run(void);
void Test_Fan(void);
void Test_PushChess(void);
void DATA_Display(void);
void TEST_FM_Find(void);
void TEST_FL_Find(void);
void TEST_FR_Find(void);
void TEST_LF_Find(void);
void TEST_RF_Find(void);
void TEST_LM_Find(void);
void TEST_RM_Find(void);
void TEST_LB_Find(void);
void TEST_RB_Find(void);
void TEST_BL_Find(void);
void TEST_BR_Find(void);
void TEST_BML_Find(void);
void TEST_BMR_Find(void);
void AUTO_TH(void);
void Test_JudgeLocation(void);
void Test_JudgeLocationCorner(void);
void Test_FaceRing(void);
void Test_FindCorner(void);
void Test_LeaveCorner(void);
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//注意！所有新建的页面都需要在这里添加:
MENU_PAGE Homepage,
			Test,
			Modes,
			Settings,
				ADCSet,
					ADCTHSet,
					ADCChannelSet,
				PushChessSet,
					Front,
					FrontFlank,
					FlankFront,
					Flank,
					FlankBack,
					BackFlank,
					Back,
				BattleSet,
			Author;
/********************************************************************************
  页面名：	主页
  父页面：	空
*********************************************************************************/
__M_PAGE(Homepage,"HOMEPAGE",PAGE_NULL,
{
	SOLGUI_Cursor(6,4,4);
	DATA_Display();
	
  SOLGUI_Widget_GotoPage	(1,&Test);
  SOLGUI_Widget_GotoPage	(2,&Settings);
  SOLGUI_Widget_GotoPage	(0,&Modes);
  SOLGUI_Widget_GotoPage	(3,&Author);
});
/********************************************************************************
  页面名：	测试
  父页面：	主页
*********************************************************************************/
__M_PAGE(Test,"TEST",&Homepage,
{
	SOLGUI_Cursor(6,4,11);
	DATA_Display();
	
	SOLGUI_Widget_Button(0,"Wireless Run",&WirelessRun);
	SOLGUI_Widget_Button(1,"Test Jump",&Test_Jump);
	SOLGUI_Widget_Spin  (2,"JUDGE TH",INT16,4095,0,&IR_JUDGE_TH);
	SOLGUI_Widget_Button(3,"Test Location",&Test_JudgeLocation);
	SOLGUI_Widget_Button(4,"Test Corner",&Test_JudgeLocationCorner);
	SOLGUI_Widget_Button(5,"Test FaceRing",&Test_FaceRing);
	SOLGUI_Widget_Button(6,"Test Fan",&Test_Fan);
	SOLGUI_Widget_Button(7,"Test FindCorner",&Test_FindCorner);
	SOLGUI_Widget_Button(8,"Test LeaveCorner",&Test_LeaveCorner);
	SOLGUI_Widget_Spin  (9,"Fan",INT16,80,50,&TestFan);
	SOLGUI_Widget_Button(10,"Test Run",&Test_Run);
});
/********************************************************************************
  页面名：	模式
  父页面：	主页
*********************************************************************************/
__M_PAGE(Modes,"MODES",&Homepage,
{
	SOLGUI_Cursor(6,4,3);
	DATA_Display();
	
	SOLGUI_Widget_Button(0,"MODE 1",&MODE1);
	SOLGUI_Widget_Button(1,"MODE 2",&MODE2);
	SOLGUI_Widget_Button(2,"MODE 3",&MODE3);
});
/********************************************************************************
  页面名：	设置
  父页面：	主页
*********************************************************************************/
__M_PAGE(Settings,"SETTINGS",&Homepage,
{
	SOLGUI_Cursor(6,4,2);
	DATA_Display();
	
  SOLGUI_Widget_GotoPage(0,&ADCSet);
  SOLGUI_Widget_GotoPage(1,&PushChessSet);
});
/********************************************************************************
  页面名：	ADC调试
  父页面：	设置
*********************************************************************************/
uint16_t TH_NOW;
__M_PAGE(ADCSet,"ADC",&Settings,
{
	/*建立光标页面*/
	SOLGUI_Cursor(6,4,14);
	DATA_Display();

	SOLGUI_Widget_GotoPage	(0 ,&ADCTHSet);
	SOLGUI_Widget_GotoPage	(1 ,&ADCChannelSet);
	SOLGUI_Widget_Button	(2 ,"AUTO SET",&AUTO_TH);
	SOLGUI_Widget_Button	(3 ,"SAVE",	&DATA_Save);
	SOLGUI_Widget_Button	(4 ,"DEFAULT",&DATA_Default);
	SOLGUI_Widget_Button	(5 ,"LODE",	&DATA_Load);
	SOLGUI_Widget_Spin		(6 ,"IR   ALL"  ,INT16,4095,0,&TH_NOW		  );
	SOLGUI_Widget_Spin		(7 ,"IR   JUMP" ,INT16,4095,0,&IR_JUMP_TH );
	SOLGUI_Widget_Spin		(8 ,"GRAY FL",INT16,4095,0,&GRAY_FL_TH	);
	SOLGUI_Widget_Spin		(9 ,"GRAY FR",INT16,4095,0,&GRAY_FR_TH	);
	SOLGUI_Widget_Spin		(10,"GRAY BL",INT16,4095,0,&GRAY_BL_TH	);
	SOLGUI_Widget_Spin		(11,"GRAY BR",INT16,4095,0,&GRAY_BR_TH	);
	SOLGUI_Widget_Spin		(12,"OS   LEFT" ,INT16,4095,0,&OS_L_TH	  );
	SOLGUI_Widget_Spin		(13,"OS   RIGHT",INT16,4095,0,&OS_R_TH	  );
	
	if(TH_NOW!=IR_ALL_TH)
	{
		int16_t temp=TH_NOW-IR_ALL_TH;
		
		IR_FL_TH  	+= temp;
		IR_FML_TH 	+= temp;
		IR_FMR_TH 	+= temp;
		IR_FR_TH  	+= temp;
		IR_BL_TH  	+= temp;
		IR_BM_TH  	+= temp;
		IR_BR_TH  	+= temp;
		IR_LF_TH  	+= temp;
		IR_LM_TH  	+= temp;
		IR_LB_TH  	+= temp;
		IR_RF_TH  	+= temp;
		IR_RM_TH  	+= temp;
		IR_RB_TH  	+= temp;
		
		IR_ALL_TH=TH_NOW;
	}
});
/********************************************************************************
  页面名：	ADC调试
  父页面：	设置
*********************************************************************************/
__M_PAGE(ADCTHSet,"ADC THRESHOLD",&ADCSet,
{
	/*建立光标页面*/
	SOLGUI_Cursor(6,0,24);

	/*显示ADC实时读数*/
	SOLGUI_Widget_OptionText(0 ,(const u8*)(GRAY_FL_Judge	? "GRAY FL  %4d>" : "GRAY FL  %4d"),GRAY_FL	);
	SOLGUI_Widget_OptionText(1 ,(const u8*)(GRAY_FR_Judge	? "GRAY FR  %4d>" : "GRAY BR  %4d"),GRAY_FR	);
	SOLGUI_Widget_OptionText(2 ,(const u8*)(GRAY_BL_Judge	? "GRAY BL  %4d>" : "GRAY FL  %4d"),GRAY_BL	);
	SOLGUI_Widget_OptionText(3 ,(const u8*)(GRAY_BR_Judge	? "GRAY BR  %4d>" : "GRAY BR  %4d"),GRAY_BR	);
	SOLGUI_Widget_OptionText(4 ,(const u8*)(IR_JUMP_Judge	? "IR JUMP  %4d>" : "IR JUMP  %4d"),IR_JUMP	);
	SOLGUI_Widget_OptionText(5 ,(const u8*)(IR_FL_Judge		? "IR FL    %4d>" : "IR FL    %4d"),IR_FL  	);
	SOLGUI_Widget_OptionText(6 ,(const u8*)(IR_FML_Judge	? "IR FML   %4d>" : "IR FML   %4d"),IR_FML 	);
	SOLGUI_Widget_OptionText(7 ,(const u8*)(IR_FMR_Judge	? "IR FMR   %4d>" : "IR FMR   %4d"),IR_FMR 	);
	SOLGUI_Widget_OptionText(8 ,(const u8*)(IR_FR_Judge		? "IR FR    %4d>" : "IR FR    %4d"),IR_FR  	);
	SOLGUI_Widget_OptionText(9 ,(const u8*)(IR_RF_Judge		? "IR RF    %4d>" : "IR RF    %4d"),IR_RF  	);
	SOLGUI_Widget_OptionText(10,(const u8*)(IR_RM_Judge		? "IR RM    %4d>" : "IR RM    %4d"),IR_RM  	);
	SOLGUI_Widget_OptionText(11,(const u8*)(IR_RB_Judge		? "IR RB    %4d>" : "IR RB    %4d"),IR_RB  	);
	SOLGUI_Widget_OptionText(12,(const u8*)(IR_BR_Judge		? "IR BR    %4d>" : "IR BR    %4d"),IR_BR  	);
	SOLGUI_Widget_OptionText(13,(const u8*)(IR_BM_Judge		? "IR BM    %4d>" : "IR BM    %4d"),IR_BM  	);
	SOLGUI_Widget_OptionText(14,(const u8*)(IR_BL_Judge		? "IR BL    %4d>" : "IR BL    %4d"),IR_BL  	);
	SOLGUI_Widget_OptionText(15,(const u8*)(IR_LB_Judge		? "IR LB    %4d>" : "IR LB    %4d"),IR_LB  	);
	SOLGUI_Widget_OptionText(16,(const u8*)(IR_LM_Judge		? "IR LM    %4d>" : "IR LM    %4d"),IR_LM  	);
	SOLGUI_Widget_OptionText(17,(const u8*)(IR_LF_Judge		? "IR LF    %4d>" : "IR LF    %4d"),IR_LF  	);
	SOLGUI_Widget_OptionText(18,(const u8*)(IR_TF_Judge		? "IR TF    %4d>" : "IR TF    %4d"),IR_TF  	);
	SOLGUI_Widget_OptionText(19,(const u8*)(WAVE_BL_Judge 	? "WAVE BL  %4d>" : "WAVE BL  %4d"),WAVE_BL	);
	SOLGUI_Widget_OptionText(20,(const u8*)(WAVE_BR_Judge 	? "WAVE BR  %4d>" : "WAVE BR  %4d"),WAVE_BR	);

	/*放置ADC阈值调节旋钮*/
	SOLGUI_Widget_Spin(0 ,"",INT16,4095,0,&GRAY_FL_TH	);
	SOLGUI_Widget_Spin(1 ,"",INT16,4095,0,&GRAY_FR_TH	);
	SOLGUI_Widget_Spin(2 ,"",INT16,4095,0,&GRAY_BL_TH	);
	SOLGUI_Widget_Spin(3 ,"",INT16,4095,0,&GRAY_BR_TH	);
	SOLGUI_Widget_Spin(4 ,"",INT16,4095,0,&IR_JUMP_TH	);
	SOLGUI_Widget_Spin(5 ,"",INT16,4095,0,&IR_FL_TH		);
	SOLGUI_Widget_Spin(6 ,"",INT16,4095,0,&IR_FML_TH	);
	SOLGUI_Widget_Spin(7 ,"",INT16,4095,0,&IR_FMR_TH	);
	SOLGUI_Widget_Spin(8 ,"",INT16,4095,0,&IR_FR_TH		);
	SOLGUI_Widget_Spin(9 ,"",INT16,4095,0,&IR_RF_TH		);
	SOLGUI_Widget_Spin(10,"",INT16,4095,0,&IR_RM_TH		);
	SOLGUI_Widget_Spin(11,"",INT16,4095,0,&IR_RB_TH		);
	SOLGUI_Widget_Spin(12,"",INT16,4095,0,&IR_BR_TH		);
	SOLGUI_Widget_Spin(13,"",INT16,4095,0,&IR_BM_TH		);
	SOLGUI_Widget_Spin(14,"",INT16,4095,0,&IR_BL_TH		);
	SOLGUI_Widget_Spin(15,"",INT16,4095,0,&IR_LB_TH		);
	SOLGUI_Widget_Spin(16,"",INT16,4095,0,&IR_LM_TH		);
	SOLGUI_Widget_Spin(17,"",INT16,4095,0,&IR_LF_TH		);
	SOLGUI_Widget_Spin(18,"",INT16,4095,0,&IR_TF_TH		);
	SOLGUI_Widget_Spin(19,"",INT16,4095,0,&WAVE_BL_TH	);
	SOLGUI_Widget_Spin(20,"",INT16,4095,0,&WAVE_BR_TH	);
	
	/*放置保存、读取、重置按钮*/
	SOLGUI_Widget_Button(21,"SAVE",	&DATA_Save);
	SOLGUI_Widget_Button(22,"LODE",	&DATA_Load);
	SOLGUI_Widget_Button(23,"DEFAULT",&DATA_Default);
});
/********************************************************************************
  页面名：	ADC调试
  父页面：	设置
*********************************************************************************/
__M_PAGE(ADCChannelSet,"ADC CHANNEL",&ADCSet,
{
	SOLGUI_Cursor(6,0,16);
	
	SOLGUI_Widget_OptionText(0 ,"ADC LEFT:");
	SOLGUI_Widget_OptionText(1 ,"L0:%04d L5:%04d",ADC_L0,ADC_L5);
	SOLGUI_Widget_OptionText(2 ,"L1:%04d L6:%04d",ADC_L1,ADC_L6);
	SOLGUI_Widget_OptionText(3 ,"L2:%04d L7:%04d",ADC_L2,ADC_L7);
	SOLGUI_Widget_OptionText(4 ,"L3:%04d L8:%04d",ADC_L3,ADC_L8);
	SOLGUI_Widget_OptionText(5 ,"L4:%04d L9:%04d",ADC_L4,ADC_L9);
	
	SOLGUI_Widget_OptionText(6 ,"ADC FORWARD:");
	SOLGUI_Widget_OptionText(7 ,"F0:%04d F4:%04d",ADC_F0,ADC_F4);
	SOLGUI_Widget_OptionText(8 ,"F1:%04d F5:%04d",ADC_F1,ADC_F5);
	SOLGUI_Widget_OptionText(9 ,"F2:%04d F6:%04d",ADC_F2,ADC_F6);
	SOLGUI_Widget_OptionText(10,"F3:%04d F7:%04d",ADC_F3,ADC_F7);
	
	SOLGUI_Widget_OptionText(11,"ADC RIGHT:");
	SOLGUI_Widget_OptionText(12,"R0:%04d R4:%04d",ADC_R0,ADC_R4);
	SOLGUI_Widget_OptionText(13,"R1:%04d R5:%04d",ADC_R1,ADC_R5);
	SOLGUI_Widget_OptionText(14,"R2:%04d R6:%04d",ADC_R2,ADC_R6);
	SOLGUI_Widget_OptionText(15,"R3:%04d R7:%04d",ADC_R3,ADC_R7);
});
/********************************************************************************
  页面名：	推棋子设置
  父页面：	设置
*********************************************************************************/
__M_PAGE(PushChessSet,"PUSH CHESS",&Settings,
{
	SOLGUI_Cursor(6,4,11);
	DATA_Display();
	
	SOLGUI_Widget_Button	(0 ,"Test Push",&Test_PushChess);
	SOLGUI_Widget_GotoPage	(1 ,&Front);
	SOLGUI_Widget_GotoPage	(2 ,&FrontFlank);
	SOLGUI_Widget_GotoPage	(3 ,&FlankFront);
	SOLGUI_Widget_GotoPage	(4 ,&Flank);
	SOLGUI_Widget_GotoPage	(5 ,&FlankBack);
	SOLGUI_Widget_GotoPage	(6 ,&BackFlank);
	SOLGUI_Widget_GotoPage	(7 ,&Back);
	SOLGUI_Widget_Button  	(8 ,"SAVE",	&DATA_Save);
	SOLGUI_Widget_Button  	(9 ,"LODE",	&DATA_Load);
	SOLGUI_Widget_Button  	(10,"DEFAULT",&DATA_Default);
});
/********************************************************************************
  页面名：	发现目标后动作设置
  父页面：	推棋子设置
*********************************************************************************/
__M_PAGE(Front,"FM",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
//	SOLGUI_Widget_Spin  (0,"SPEED"		,INT16,1000,0,&GRAY_F_TH	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeFM	);
	SOLGUI_Widget_Button(2,"TEST"		,&TEST_FM_Find				);
	SOLGUI_Widget_Button(3,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(4,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(5,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(FrontFlank,"FL FR",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedFL	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeFL	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_FL_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_FR_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(FlankFront,"LF RF",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedLF	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeLF	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_LF_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_RF_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(Flank,"LM RM",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedLM	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeLM	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_LM_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_RM_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(FlankBack,"LB RB",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedLB	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeLB	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_LB_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_RB_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(BackFlank,"BL BR",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedBL	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeBL	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_BL_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_BR_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
__M_PAGE(Back,"BM",&PushChessSet,
{
	SOLGUI_Cursor(6,4,7);
	DATA_Display();
	
	SOLGUI_Widget_Spin  (0,"TURN SPEED"	,INT16,1000,0,&TurnSpeedBM	);
	SOLGUI_Widget_Spin  (1,"WAIT TIME"	,INT16,3000,0,&WaitTimeBM	);
	SOLGUI_Widget_Button(2,"TEST LEFT"	,&TEST_BML_Find				);
	SOLGUI_Widget_Button(3,"TEST RIGHT"	,&TEST_BMR_Find				);
	SOLGUI_Widget_Button(4,"SAVE"		,&DATA_Save					);
	SOLGUI_Widget_Button(5,"LODE"		,&DATA_Load					);
	SOLGUI_Widget_Button(6,"DEFAULT"	,&DATA_Default				);
});
/********************************************************************************
  页面名：	作者信息
  父页面：	主页
*********************************************************************************/
__M_PAGE(Author,"AUTHOR",&Homepage,
{
	SOLGUI_Widget_OptionText(0,"COMPANY:   505_Tech");
	SOLGUI_Widget_OptionText(1,"QQ:      2843067579");
	SOLGUI_Widget_OptionText(2,"VERSION:      V%04d",PROGRAM_REFRESH_PASSWORD);
});
/*===========================新建菜单页面格式及常用函数=============================
__M_PAGE(name(),pageTitle,parentPage,
//（该页面名称，“页面标题”，&上级页面名）
{

    SOLGUI_Cursor( uint8_t rowBorder_Top, uint8_t rowBorder_Bottom, uint8_t option_num)
    //（上边界行，下边界行，选项个数）

    页面跳转控件:
    SOLGUI_Widget_GotoPage( uint8_t USN,MENU_PAGE *page)
    //(该选项所处位置,	&页面地址)

    按键控件：
    SOLGUI_Widget_Button( uint8_t USN,const  uint8_t *name,void (*func)(void))
    //(该选项所处位置,"该选项显示的文字",&按下该按键时执行的无参数void类型函数);

    数字旋钮控件：
    SOLGUI_Widget_Spin( uint8_t USN,const  uint8_t *name, uint8_t type,double max,double min,void* value)
    //(该选项所处位置,"该选项显示的文字",变量类型（如INT32）,变化上限,变化下限,&变量地址);

    自由文本控件：
    SOLGUI_Widget_Text( uint32_t x0, uint32_t y0, uint8_t mode,const  uint8_t* str,...)
    //(横坐标,纵坐标,字号（如F4X6）,"需要显示的文字（格式同printf）",用法同printf字符串后的参数);

});
================================================================================*/
/********************************************************************************
    功能：	ADC读数页面
    参数：	无
    返回：	无
    备注：	在菜单中调用
*********************************************************************************/
#define ShowADCX(X,Y,ADCX) SOLGUI_Widget_Text(X,Y,ADCX>ADCX##_TH?R4X6:F4X6,"%04d",ADCX)
void DATA_Display(void)
{
	//跳台
	SOLGUI_Widget_Text(0,16,IR_JUMP>IR_JUMP_TH?R4X6:F4X6,(const u8*)(IR_JUMP>IR_JUMP_TH?" X":" O"));
	//铲子	
	ShowADCX(0  ,24	,OS_L	);
	ShowADCX(112,24	,OS_R	);
	//前	
	ShowADCX(28 ,24	,IR_FL	);
	ShowADCX(46 ,24	,IR_FML	);		
	ShowADCX(66 ,24	,IR_FMR	);		
	ShowADCX(84 ,24	,IR_FR	);		
	//左           	   			 
	ShowADCX(16 ,6 	,IR_LB	);		
	ShowADCX(14 ,12	,IR_LM	);		
	ShowADCX(12 ,18	,IR_LF	);		
	//右           	 		 	
	ShowADCX(96 ,6 	,IR_RB	);		
	ShowADCX(98 ,12	,IR_RM	);		
	ShowADCX(100,18	,IR_RF	);	
	//后        		
	ShowADCX(32 ,0 	,IR_BL	);
	ShowADCX(56 ,0 	,IR_BM	);
	ShowADCX(80 ,0 	,IR_BR	);
	//顶        		
	ShowADCX(55 ,16	,IR_TF	);	
	//超声波        	
	ShowADCX(0  ,0	,WAVE_BL);
	ShowADCX(112,0 	,WAVE_BR);	
	//灰度         	  		 	
	ShowADCX(34 ,16	,GRAY_FL);
	ShowADCX(38 ,8 	,GRAY_BL);
	ShowADCX(78 ,16	,GRAY_FR);
	ShowADCX(74 ,8 	,GRAY_BR);
	//编码器
//	SOLGUI_Widget_Text(0  ,0 ,F4X6,(const u8*)(SpeedL==0?"":(SpeedL>0?"+%03d":"-%03d")),SpeedL>0?SpeedL:-SpeedL);
//	SOLGUI_Widget_Text(112,0 ,F4X6,(const u8*)(SpeedR==0?"":(SpeedR>0?"+%03d":"-%03d")),SpeedR>0?SpeedR:-SpeedR);
}
/********************************************************************************
    功能：	无线遥控
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void WirelessRun(void)
{
	#define WirelessRunSpeed  300
	#define WirelessTurnSpeed 200
	#define FanSpeed          65
	
//	uint8_t fanflag=0;
	
	while(UART4_Res!=__KEY_BACK)
	{
		switch(UART4_Res)
		{
			case __KEY_OK		:
//				Test_Jump();
//				fanflag=!fanflag;
//			
//				if(fanflag)
//					TestFan=FanSpeed;
//				else
//					TestFan=59;
				
				break;
			case __KEY_UP 	:Car_Run( WirelessRunSpeed , WirelessRunSpeed );break;
			case __KEY_DOWN :Car_Run(-WirelessRunSpeed ,-WirelessRunSpeed );break;
			case __KEY_LEFT :Car_Run(-WirelessTurnSpeed, WirelessTurnSpeed);break;
			case __KEY_RIGHT:Car_Run( WirelessTurnSpeed,-WirelessTurnSpeed);break;
			default					:Car_Run(                 0,                 0);break;
		}
	}
	
	TestFan=59;
}
/********************************************************************************
    功能：	测试跳台
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_Jump(void)
{
	BEEP_Hint(2);
	while(UART4_Res!=__KEY_OK)
	{if(UART4_Res==__KEY_BACK)return;}
	BEEP_USING_FLAG=0;
	
	Car_Jump();	
}
/********************************************************************************
    功能：	测试找角落
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_FindCorner(void)
{
	BEEP_Hint(2);
	while(UART4_Res!=__KEY_OK)
	{if(UART4_Res==__KEY_BACK)return;}
	BEEP_USING_FLAG=0;
	
	Car_FindCorner();	
}
/********************************************************************************
    功能：	测试风扇
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_Fan(void)
{
	uint16_t i;
	
	BEEP_Hint(2);
	while(UART4_Res!=__KEY_OK)
	{if(UART4_Res==__KEY_BACK)return;}
	BEEP_USING_FLAG=0;
	
	TestFan=60;
	delay_ms(500);
	TestFan=59;
	delay_ms(100);
	TestFan=60;
	delay_ms(500);
	TestFan=59;
	delay_ms(100);
	TestFan=60;
	delay_ms(500);
	for(i=60;i<=80;i++)
	{
		TestFan=i;
		delay_ms(100);
	}
	delay_ms(1000);
	for(i=80;i>59;i--)
	{
		TestFan=i;
		delay_ms(200);
	}
	delay_ms(500);
	TestFan=59;
}
/********************************************************************************
    功能：	测试找台
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_FaceRing(void)
{
	BEEP_Hint(2);
	while(UART4_Res!=__KEY_OK)
	{if(UART4_Res==__KEY_BACK)return;}
	BEEP_USING_FLAG=0;
	
	Car_FaceRing();
	
	BEEP_Hint(2);
}
/********************************************************************************
    功能：	测试离开角落
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_LeaveCorner(void)
{
	BEEP_Hint(2);
	while(UART4_Res!=__KEY_OK)
	{if(UART4_Res==__KEY_BACK)return;}
	BEEP_USING_FLAG=0;
	
	Car_LeaveCorner();
	
	BEEP_Hint(2);
}
/********************************************************************************
    功能：	测试台上台下检测
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_JudgeLocation(void)
{
	while(UART4_Res!=__KEY_BACK)
	{
		if(Judge_Location())
			BEEP = BEEP_ON;
		else
			BEEP = BEEP_OFF;
	}
}
/********************************************************************************
    功能：	测试角落检测
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_JudgeLocationCorner(void)
{
	while(UART4_Res!=__KEY_BACK)
	{
		if(Judge_Location_Corner())
			BEEP = BEEP_ON;
		else
			BEEP = BEEP_OFF;
	}
}
/********************************************************************************
    功能：	测试推棋子
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_PushChess(void)
{
	Car_PutChess();
}
/********************************************************************************
    功能：	测试红外发现目标后的动作
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void TEST_FM_Find(void)
{
	PutChess_FM_Find(WaitTimeFM);
	Car_Run(0,0);
}
void TEST_FL_Find(void)
{
	PutChess_L_Find(TurnSpeedFL,WaitTimeFL);
	Car_Run(0,0);
}
void TEST_FR_Find(void)
{
	PutChess_R_Find(TurnSpeedFR,WaitTimeFR);
	Car_Run(0,0);
}
void TEST_LF_Find(void)
{
	PutChess_L_Find(TurnSpeedLF,WaitTimeLF);
	Car_Run(0,0);
}
void TEST_RF_Find(void)
{
	PutChess_R_Find(TurnSpeedRF,WaitTimeRF);
	Car_Run(0,0);
}
void TEST_LM_Find(void)
{
	PutChess_L_Find(TurnSpeedLM,WaitTimeLM);
	Car_Run(0,0);
}
void TEST_RM_Find(void)
{
	PutChess_R_Find(TurnSpeedRM,WaitTimeRM);
	Car_Run(0,0);
}
void TEST_LB_Find(void)
{
	PutChess_L_Find(TurnSpeedLB,WaitTimeLB);
	Car_Run(0,0);
}
void TEST_RB_Find(void)
{
	PutChess_R_Find(TurnSpeedRB,WaitTimeRB);
	Car_Run(0,0);
}
void TEST_BL_Find(void)
{
	PutChess_L_Find(TurnSpeedBL,WaitTimeBL);
	Car_Run(0,0);
}
void TEST_BR_Find(void)
{
	PutChess_R_Find(TurnSpeedBR,WaitTimeBR);
	Car_Run(0,0);
}
void TEST_BML_Find(void)
{
	PutChess_L_Find(TurnSpeedBM,WaitTimeBM);
	Car_Run(0,0);
}
void TEST_BMR_Find(void)
{
	PutChess_R_Find(TurnSpeedBM,WaitTimeBM);
	Car_Run(0,0);
}
/********************************************************************************
    功能：	自动阈值
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void AUTO_TH(void)
{
	#define SearchSpeed (((200-(GRAY_FL+GRAY_FR)/40)>=100)?(300-(GRAY_FL+GRAY_FR)/40):100)
	
//	IR_FL_TH	=	0;
//	IR_FR_TH	=	0;
//	IR_BL_TH	=	0;
//	IR_BM_TH	=	0;
//	IR_BR_TH	=	0;
//	IR_LF_TH	=	0;
//	IR_LM_TH	=	0;
//	IR_LB_TH	=	0;
//	IR_RF_TH	=	0;
//	IR_RM_TH	=	0;
//	IR_RB_TH	=	0;
	BEEP_USING_FLAG=1;
	Car_Run(SearchSpeed,SearchSpeed);
	while(UART4_Res!=__KEY_BACK)
	{
//========================台边检测========================
		IF((OS_L_Judge||OS_R_Judge),
		{
			Car_Run(-300,-300);
			
			delay_ms(400);
			
			Car_Run(500,-500);
			delay_ms(220);
			
			Car_Run(SearchSpeed,SearchSpeed);
		})
//========================前红外扫到=======================
//		else IF((IR_FML_Judge),
//		{
//			IR_FML_TH+=100;
//			continue;
//		})
//		else IF((IR_FMR_Judge),
//		{
//			IR_FMR_TH+=100;
//			continue;
//		})
//========================左红外扫到=======================
		else IF((IR_FL_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_FL_TH+=100;
			continue;
		})
		else IF((IR_LF_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_LF_TH+=100;
			continue;
		})
		else IF((IR_LM_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_LM_TH+=100;
			continue;
		})
		else IF((IR_LB_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_LB_TH+=100;
			continue;
		})
		else IF((IR_BL_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_BL_TH+=100;
			continue;
		})
		else IF((IR_BM_Judge),//左
		{
			BEEP=BEEP_ON;
			IR_BM_TH+=100;
			continue;
		})
//========================右红外扫到=======================
		else IF((IR_FR_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_FR_TH+=100;
			continue;
		})
		else IF((IR_RF_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_RF_TH+=100;
			continue;
		})
		else IF((IR_RM_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_RM_TH+=100;
			continue;
		})
		else IF((IR_RB_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_RB_TH+=100;
			continue;
		})
		else IF((IR_BR_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_BR_TH+=100;
			continue;
		})
		else IF((IR_BM_Judge),//右
		{
			BEEP=BEEP_ON;
			IR_BM_TH+=100;
			continue;
		})
//======================没有红外扫到=====================
		else
		{
			BEEP=BEEP_OFF;
			Car_Run(SearchSpeed,SearchSpeed);
			continue;
		}
	}
	
//	IR_FL_TH  +=300;
//	IR_FR_TH  +=300;
//	IR_BL_TH  +=300;
//	IR_BM_TH  +=300;
//	IR_BR_TH  +=300;
//	IR_LF_TH  +=300;
//	IR_LM_TH  +=300;
//	IR_LB_TH  +=300;
//	IR_RF_TH  +=300;
//	IR_RM_TH  +=300;
//	IR_RB_TH  +=300;
	BEEP_USING_FLAG=0;
	Car_Run(0,0);
}
/********************************************************************************
    功能：	测试运行
    参数：	无
    返回：	无
    备注：	在菜单中调用，为空返回无参数函数
*********************************************************************************/
void Test_Run(void)
{
	{
			static uint16_t FanOpenTime=0;
			
			uint8_t FanSwitch=1;
			BEEP_USING_FLAG=1;
		
			while(1)
			if(FanSwitch==1)
			{
				BEEP=BEEP_ON;
				FanOpenTime++;
				delay_ms(1);
				if(FanOpenTime>=9000)
					FanSwitch=0;
			}
			else
			{
				BEEP=BEEP_OFF;
				FanOpenTime=0;
			BEEP_USING_FLAG=0;
				return;
			}
			
		}
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
