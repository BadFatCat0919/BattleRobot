///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUC拳皇-主控板-FLASH操作代码
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "flash.h"
#include "delay.h"
/********************************************************************************
	功能：	读取指定地址的半字(16位数据)
	参数：	faddr  读地址(此地址必须为2的倍数!!)
	返回：	对应数据
	备注：	无
*********************************************************************************/
uint16_t STMFLASH_ReadHalfWord( uint32_t faddr)
{
	return *(vu16*)faddr; 
}
/********************************************************************************
	功能：	不检查的写入
	参数：	WriteAddr  起始地址
            pBuffer    数据指针
            NumToWrite 半字(16位)数   
	返回：	对应数据
	备注：	无
*********************************************************************************/
void STMFLASH_Write_NoCheck( uint32_t WriteAddr, uint16_t *pBuffer, uint16_t NumToWrite)   
{ 			 		 
	uint16_t i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;
	}  
} 
/********************************************************************************
	功能：	从指定地址开始写入指定长度的数据
	参数：	WriteAddr  起始地址
            pBuffer    数据指针
            NumToWrite 半字(16位)数   
	返回：	无
	备注：	无
*********************************************************************************/
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
uint16_t STMFLASH_BUF[STM_SECTOR_SIZE/2];
void STMFLASH_Write( uint32_t WriteAddr, uint16_t *pBuffer, uint16_t NumToWrite)	
{
	 uint32_t secpos;
	 uint16_t secoff;
	 uint16_t secremain;   
 	 uint16_t i;    
	 uint32_t offaddr;
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))
		return;
	FLASH_Unlock();	
	offaddr=WriteAddr-STM32_FLASH_BASE;
	secpos=offaddr/STM_SECTOR_SIZE;	
	secoff=(offaddr%STM_SECTOR_SIZE)/2;
	secremain=STM_SECTOR_SIZE/2-secoff;	
	if(NumToWrite<=secremain)secremain=NumToWrite;
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);
		for(i=0;i<secremain;i++)
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;
		}
		if(i<secremain)
		{
			FLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);
			for(i=0;i<secremain;i++)
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);			   
		if(NumToWrite==secremain)break;
		else
		{
			secpos++;
			secoff=0; 
		   	pBuffer+=secremain;
			WriteAddr+=secremain;   
		   	NumToWrite-=secremain;
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;
			else secremain=NumToWrite;
		}	 
	};	
	FLASH_Lock();
}
/********************************************************************************
	功能：	从指定地址开始读出指定长度的数据
	参数：	WriteAddr  起始地址
            pBuffer    数据指针
            NumToWrite 半字(16位)数   
	返回：	无
	备注：	无
*********************************************************************************/
void STMFLASH_Read( uint32_t ReadAddr, uint16_t *pBuffer, uint16_t NumToRead)   	
{
	uint16_t i;

	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);
		ReadAddr+=2;
	}
}
///////////////////////////////////////////////////////////////////-=505-Tech=-///
