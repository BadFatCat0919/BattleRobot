CAUC拳皇-主控板-通用工程模板
版本：V0.0
编委：徐天泽 吴金峰 胡冀威 邱樟保 丁  涛
中国民航大学电子科技创新创业实践基地505创客实验室

参考代码：
1.正点原子SYSTEM文件夹与部分驱动代码
2.SOLGUI_V2-master菜单
3.UNO匿名四轴上位机通信协议

更新日志:
3.0.1.190721_Beta
1.在main.h中加入数据缺省值设置项，在菜单中加入导入缺省值选项
2.修正PID控制器声明与函数体名称不统一的问题
3.优化部分init函数
3.1.0.190725_Beta
1.修改菜单细节，调整参数时可按BACK键退出，按下函数执行按钮时反白显示
2.修正数据存储逻辑，消除数据在菜单中无法更改的bug
3.增加ADC调试页面
4.根据核心板修正按键接口及蜂鸣器接口

说明:
1.从menu.c开始看，把菜单的各个选项当做目录。
2.使用本工程时，建议将周期性执行的控制代码写在control.c里，
如PID的计算等；将程序最后需要执行的模式编写在mode.c里，
需要存入flash的数据编写在data.c里。建议HARDWARE文件夹中
已有的内容不要修改，可在此基础上新建别的文件夹写入自己的
代码。这样在后续版本发布修正BUG的时候可以直接复制替换，
省去不必要的麻烦。
3.PID参数在第一次下载完程序后于菜单中设置
4.发现BUG请务必及时联系徐天泽！！！

附:
单片机引脚占用：
LED(LED灯)
  LED2           PE5
  LED1           PB5
  
BEEP(蜂鸣器)
  BEEP           PB7
 
KEY(按键)
  KEY_OK         PD5
  KEY_BACK       PD6
  KEY_UP         PD0
  KEY_DOWN       PD2
  KEY_LEFT       PD3
  KEY_RIGHT      PD4
  KEY_USER       PD1
  
OLED(显示屏)
  D0/SCLK        PB2
  D1/SDIN/MOSI   PE7
  RES/RST        PE8
  DC             PE10
  CS             PE12
  
TIMMER(定时器引脚)
  TIM1  引脚完全重映射
        CH1      PE9
        CH2      PE11
        CH3      PE13
        CH4      PE14
  TIM2  引脚完全重映射
        CH1      PA15
        CH2      PB3
  TIM3  
        CH1      PA6
        CH2      PA7
  TIM4  引脚完全重映射
        CH1      PD12
        CH2      PD13
  TIM5
        CH1      PA0
        CH2      PA1
  TIM8  引脚完全重映射
        CH1      PC6
        CH2      PC7
        CH3      PC8
        CH4      PC9
		
USART(串口)
  USART1
        TX       PA9
        RX       PA10
  USART2
        TX       PA2
        RX       PA3
  USART3
        TX       PB10
        RX       PB11
		
ADC(模拟输入)
  ADC1
        IN1      PA4
        IN2      PA5
        IN3      PC0
        IN4      PC1
        IN5      PC2
        IN6      PC3
        IN7      PC4
        IN8      PC5

代码默认中断优先级:
                  抢占优先级(Preemption)  响应优先级(Sub)
TIM6定时中断                1                   0
TIM7定时中断                1                   1
USART1接收空闲中断          3                   3
USART2接收空闲中断          3                   2
USART3接收空闲中断          3                   1