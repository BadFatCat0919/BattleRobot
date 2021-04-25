///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-FLASH操作代码
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#ifndef __STMFLASH_H__
#define __STMFLASH_H__
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "sys.h"  
///////////////////////////////////////////////////////////////////-=505-Tech=-///
/*设置芯片容量*/
#ifdef  STM32F10X_MD
#define STM32_FLASH_SIZE      128
#endif
#ifdef  STM32F10X_HD
#define STM32_FLASH_SIZE      512
#endif
/*FLASH起始地址*/
#define STM32_FLASH_BASE      ((uint32_t)0x08000000)
/*FLASH各页地址，每页1KB*/
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base of Page 0 */
#define ADDR_FLASH_PAGE_1     ((uint32_t)0x08000400) /* Base of Page 1 */
#define ADDR_FLASH_PAGE_2     ((uint32_t)0x08000800) /* Base of Page 2 */
#define ADDR_FLASH_PAGE_3     ((uint32_t)0x08000C00) /* Base of Page 3 */
#define ADDR_FLASH_PAGE_4     ((uint32_t)0x08001000) /* Base of Page 4 */
#define ADDR_FLASH_PAGE_5     ((uint32_t)0x08001400) /* Base of Page 5 */
#define ADDR_FLASH_PAGE_6     ((uint32_t)0x08001800) /* Base of Page 6 */
#define ADDR_FLASH_PAGE_7     ((uint32_t)0x08001C00) /* Base of Page 7 */
#define ADDR_FLASH_PAGE_8     ((uint32_t)0x08002000) /* Base of Page 8 */
#define ADDR_FLASH_PAGE_9     ((uint32_t)0x08002400) /* Base of Page 9 */
#define ADDR_FLASH_PAGE_10    ((uint32_t)0x08002800) /* Base of Page 10 */
#define ADDR_FLASH_PAGE_11    ((uint32_t)0x08002C00) /* Base of Page 11 */
#define ADDR_FLASH_PAGE_12    ((uint32_t)0x08003000) /* Base of Page 12 */
#define ADDR_FLASH_PAGE_13    ((uint32_t)0x08003400) /* Base of Page 13 */
#define ADDR_FLASH_PAGE_14    ((uint32_t)0x08003800) /* Base of Page 14 */
#define ADDR_FLASH_PAGE_15    ((uint32_t)0x08003C00) /* Base of Page 15 */
#define ADDR_FLASH_PAGE_16    ((uint32_t)0x08004000) /* Base of Page 16 */
#define ADDR_FLASH_PAGE_17    ((uint32_t)0x08004400) /* Base of Page 17 */
#define ADDR_FLASH_PAGE_18    ((uint32_t)0x08004800) /* Base of Page 18 */
#define ADDR_FLASH_PAGE_19    ((uint32_t)0x08004C00) /* Base of Page 19 */
#define ADDR_FLASH_PAGE_20    ((uint32_t)0x08005000) /* Base of Page 20 */
#define ADDR_FLASH_PAGE_21    ((uint32_t)0x08005400) /* Base of Page 21 */
#define ADDR_FLASH_PAGE_22    ((uint32_t)0x08005800) /* Base of Page 22 */
#define ADDR_FLASH_PAGE_23    ((uint32_t)0x08005C00) /* Base of Page 23 */
#define ADDR_FLASH_PAGE_24    ((uint32_t)0x08006000) /* Base of Page 24 */
#define ADDR_FLASH_PAGE_25    ((uint32_t)0x08006400) /* Base of Page 25 */
#define ADDR_FLASH_PAGE_26    ((uint32_t)0x08006800) /* Base of Page 26 */
#define ADDR_FLASH_PAGE_27    ((uint32_t)0x08006C00) /* Base of Page 27 */
#define ADDR_FLASH_PAGE_28    ((uint32_t)0x08007000) /* Base of Page 28 */
#define ADDR_FLASH_PAGE_29    ((uint32_t)0x08007400) /* Base of Page 29 */
#define ADDR_FLASH_PAGE_30    ((uint32_t)0x08007800) /* Base of Page 30 */
#define ADDR_FLASH_PAGE_31    ((uint32_t)0x08007C00) /* Base of Page 31 */
#define ADDR_FLASH_PAGE_32    ((uint32_t)0x08008000) /* Base of Page 32 */
#define ADDR_FLASH_PAGE_33    ((uint32_t)0x08008400) /* Base of Page 33 */
#define ADDR_FLASH_PAGE_34    ((uint32_t)0x08008800) /* Base of Page 34 */
#define ADDR_FLASH_PAGE_35    ((uint32_t)0x08008C00) /* Base of Page 35 */
#define ADDR_FLASH_PAGE_36    ((uint32_t)0x08009000) /* Base of Page 36 */
#define ADDR_FLASH_PAGE_37    ((uint32_t)0x08009400) /* Base of Page 37 */
#define ADDR_FLASH_PAGE_38    ((uint32_t)0x08009800) /* Base of Page 38 */
#define ADDR_FLASH_PAGE_39    ((uint32_t)0x08009C00) /* Base of Page 39 */
#define ADDR_FLASH_PAGE_40    ((uint32_t)0x0800A000) /* Base of Page 40 */
#define ADDR_FLASH_PAGE_41    ((uint32_t)0x0800A400) /* Base of Page 41 */
#define ADDR_FLASH_PAGE_42    ((uint32_t)0x0800A800) /* Base of Page 42 */
#define ADDR_FLASH_PAGE_43    ((uint32_t)0x0800AC00) /* Base of Page 43 */
#define ADDR_FLASH_PAGE_44    ((uint32_t)0x0800B000) /* Base of Page 44 */
#define ADDR_FLASH_PAGE_45    ((uint32_t)0x0800B400) /* Base of Page 45 */
#define ADDR_FLASH_PAGE_46    ((uint32_t)0x0800B800) /* Base of Page 46 */
#define ADDR_FLASH_PAGE_47    ((uint32_t)0x0800BC00) /* Base of Page 47 */
#define ADDR_FLASH_PAGE_48    ((uint32_t)0x0800C000) /* Base of Page 48 */
#define ADDR_FLASH_PAGE_49    ((uint32_t)0x0800C400) /* Base of Page 49 */
#define ADDR_FLASH_PAGE_50    ((uint32_t)0x0800C800) /* Base of Page 50 */
#define ADDR_FLASH_PAGE_51    ((uint32_t)0x0800CC00) /* Base of Page 51 */
#define ADDR_FLASH_PAGE_52    ((uint32_t)0x0800D000) /* Base of Page 52 */
#define ADDR_FLASH_PAGE_53    ((uint32_t)0x0800D400) /* Base of Page 53 */
#define ADDR_FLASH_PAGE_54    ((uint32_t)0x0800D800) /* Base of Page 54 */
#define ADDR_FLASH_PAGE_55    ((uint32_t)0x0800DC00) /* Base of Page 55 */
#define ADDR_FLASH_PAGE_56    ((uint32_t)0x0800E000) /* Base of Page 56 */
#define ADDR_FLASH_PAGE_57    ((uint32_t)0x0800E400) /* Base of Page 57 */
#define ADDR_FLASH_PAGE_58    ((uint32_t)0x0800E800) /* Base of Page 58 */
#define ADDR_FLASH_PAGE_59    ((uint32_t)0x0800EC00) /* Base of Page 59 */
#define ADDR_FLASH_PAGE_60    ((uint32_t)0x0800F000) /* Base of Page 60 */
#define ADDR_FLASH_PAGE_61    ((uint32_t)0x0800F400) /* Base of Page 61 */
#define ADDR_FLASH_PAGE_62    ((uint32_t)0x0800F800) /* Base of Page 62 */
#define ADDR_FLASH_PAGE_63    ((uint32_t)0x0800FC00) /* Base of Page 63 */
#define ADDR_FLASH_PAGE_64    ((uint32_t)0x08010000) /* Base of Page 64 */
#define ADDR_FLASH_PAGE_65    ((uint32_t)0x08010400) /* Base of Page 65 */
#define ADDR_FLASH_PAGE_66    ((uint32_t)0x08010800) /* Base of Page 66 */
#define ADDR_FLASH_PAGE_67    ((uint32_t)0x08010C00) /* Base of Page 67 */
#define ADDR_FLASH_PAGE_68    ((uint32_t)0x08011000) /* Base of Page 68 */
#define ADDR_FLASH_PAGE_69    ((uint32_t)0x08011400) /* Base of Page 69 */
#define ADDR_FLASH_PAGE_70    ((uint32_t)0x08011800) /* Base of Page 70 */
#define ADDR_FLASH_PAGE_71    ((uint32_t)0x08011C00) /* Base of Page 71 */
#define ADDR_FLASH_PAGE_72    ((uint32_t)0x08012000) /* Base of Page 72 */
#define ADDR_FLASH_PAGE_73    ((uint32_t)0x08012400) /* Base of Page 73 */
#define ADDR_FLASH_PAGE_74    ((uint32_t)0x08012800) /* Base of Page 74 */
#define ADDR_FLASH_PAGE_75    ((uint32_t)0x08012C00) /* Base of Page 75 */
#define ADDR_FLASH_PAGE_76    ((uint32_t)0x08013000) /* Base of Page 76 */
#define ADDR_FLASH_PAGE_77    ((uint32_t)0x08013400) /* Base of Page 77 */
#define ADDR_FLASH_PAGE_78    ((uint32_t)0x08013800) /* Base of Page 78 */
#define ADDR_FLASH_PAGE_79    ((uint32_t)0x08013C00) /* Base of Page 79 */
#define ADDR_FLASH_PAGE_80    ((uint32_t)0x08014000) /* Base of Page 80 */
#define ADDR_FLASH_PAGE_81    ((uint32_t)0x08014400) /* Base of Page 81 */
#define ADDR_FLASH_PAGE_82    ((uint32_t)0x08014800) /* Base of Page 82 */
#define ADDR_FLASH_PAGE_83    ((uint32_t)0x08014C00) /* Base of Page 83 */
#define ADDR_FLASH_PAGE_84    ((uint32_t)0x08015000) /* Base of Page 84 */
#define ADDR_FLASH_PAGE_85    ((uint32_t)0x08015400) /* Base of Page 85 */
#define ADDR_FLASH_PAGE_86    ((uint32_t)0x08015800) /* Base of Page 86 */
#define ADDR_FLASH_PAGE_87    ((uint32_t)0x08015C00) /* Base of Page 87 */
#define ADDR_FLASH_PAGE_88    ((uint32_t)0x08016000) /* Base of Page 88 */
#define ADDR_FLASH_PAGE_89    ((uint32_t)0x08016400) /* Base of Page 89 */
#define ADDR_FLASH_PAGE_90    ((uint32_t)0x08016800) /* Base of Page 90 */
#define ADDR_FLASH_PAGE_91    ((uint32_t)0x08016C00) /* Base of Page 91 */
#define ADDR_FLASH_PAGE_92    ((uint32_t)0x08017000) /* Base of Page 92 */
#define ADDR_FLASH_PAGE_93    ((uint32_t)0x08017400) /* Base of Page 93 */
#define ADDR_FLASH_PAGE_94    ((uint32_t)0x08017800) /* Base of Page 94 */
#define ADDR_FLASH_PAGE_95    ((uint32_t)0x08017C00) /* Base of Page 95 */
#define ADDR_FLASH_PAGE_96    ((uint32_t)0x08018000) /* Base of Page 96 */
#define ADDR_FLASH_PAGE_97    ((uint32_t)0x08018400) /* Base of Page 97 */
#define ADDR_FLASH_PAGE_98    ((uint32_t)0x08018800) /* Base of Page 98 */
#define ADDR_FLASH_PAGE_99    ((uint32_t)0x08018C00) /* Base of Page 99 */
#define ADDR_FLASH_PAGE_100   ((uint32_t)0x08019000) /* Base of Page 100 */
#define ADDR_FLASH_PAGE_101   ((uint32_t)0x08019400) /* Base of Page 101 */
#define ADDR_FLASH_PAGE_102   ((uint32_t)0x08019800) /* Base of Page 102 */
#define ADDR_FLASH_PAGE_103   ((uint32_t)0x08019C00) /* Base of Page 103 */
#define ADDR_FLASH_PAGE_104   ((uint32_t)0x0801A000) /* Base of Page 104 */
#define ADDR_FLASH_PAGE_105   ((uint32_t)0x0801A400) /* Base of Page 105 */
#define ADDR_FLASH_PAGE_106   ((uint32_t)0x0801A800) /* Base of Page 106 */
#define ADDR_FLASH_PAGE_107   ((uint32_t)0x0801AC00) /* Base of Page 107 */
#define ADDR_FLASH_PAGE_108   ((uint32_t)0x0801B000) /* Base of Page 108 */
#define ADDR_FLASH_PAGE_109   ((uint32_t)0x0801B400) /* Base of Page 109 */
#define ADDR_FLASH_PAGE_110   ((uint32_t)0x0801B800) /* Base of Page 110 */
#define ADDR_FLASH_PAGE_111   ((uint32_t)0x0801BC00) /* Base of Page 111 */
#define ADDR_FLASH_PAGE_112   ((uint32_t)0x0801C000) /* Base of Page 112 */
#define ADDR_FLASH_PAGE_113   ((uint32_t)0x0801C400) /* Base of Page 113 */
#define ADDR_FLASH_PAGE_114   ((uint32_t)0x0801C800) /* Base of Page 114 */
#define ADDR_FLASH_PAGE_115   ((uint32_t)0x0801CC00) /* Base of Page 115 */
#define ADDR_FLASH_PAGE_116   ((uint32_t)0x0801D000) /* Base of Page 116 */
#define ADDR_FLASH_PAGE_117   ((uint32_t)0x0801D400) /* Base of Page 117 */
#define ADDR_FLASH_PAGE_118   ((uint32_t)0x0801D800) /* Base of Page 118 */
#define ADDR_FLASH_PAGE_119   ((uint32_t)0x0801DC00) /* Base of Page 119 */
#define ADDR_FLASH_PAGE_120   ((uint32_t)0x0801E000) /* Base of Page 120 */
#define ADDR_FLASH_PAGE_121   ((uint32_t)0x0801E400) /* Base of Page 121 */
#define ADDR_FLASH_PAGE_122   ((uint32_t)0x0801E800) /* Base of Page 122 */
#define ADDR_FLASH_PAGE_123   ((uint32_t)0x0801EC00) /* Base of Page 123 */
#define ADDR_FLASH_PAGE_124   ((uint32_t)0x0801F000) /* Base of Page 124 */
#define ADDR_FLASH_PAGE_125   ((uint32_t)0x0801F400) /* Base of Page 125 */
#define ADDR_FLASH_PAGE_126   ((uint32_t)0x0801F800) /* Base of Page 126 */
#define ADDR_FLASH_PAGE_127   ((uint32_t)0x0801FC00) /* Base of Page 127 */
///////////////////////////////////////////////////////////////////-=505-Tech=-///
void STMFLASH_Write( uint32_t WriteAddr, uint16_t *pBuffer, uint16_t NumToWrite);		
                                                  //从指定地址开始写入指定长度的数据
void STMFLASH_Read( uint32_t ReadAddr, uint16_t *pBuffer, uint16_t NumToRead);   		
                                                  //从指定地址开始读出指定长度的数据			
///////////////////////////////////////////////////////////////////-=505-Tech=-///				   
#endif
///////////////////////////////////////////////////////////////////-=505-Tech=-///
