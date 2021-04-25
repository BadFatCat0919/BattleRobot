///////////////////////////////////////////////////////////////////-=505-Tech=-///
//CAUCȭ��-���ذ�-FLASH��������
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//��д��������
//�й��񺽴�ѧ���ӿƼ����´�ҵʵ������505����ʵ����
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//���������ѧϰ�ο���δ����ɣ��������������κ���;
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "flash.h"
#include "delay.h"
/********************************************************************************
	���ܣ�	��ȡָ����ַ�İ���(16λ����)
	������	faddr  ����ַ(�˵�ַ����Ϊ2�ı���!!)
	���أ�	��Ӧ����
	��ע��	��
*********************************************************************************/
uint16_t STMFLASH_ReadHalfWord( uint32_t faddr)
{
	return *(vu16*)faddr; 
}
/********************************************************************************
	���ܣ�	������д��
	������	WriteAddr  ��ʼ��ַ
            pBuffer    ����ָ��
            NumToWrite ����(16λ)��   
	���أ�	��Ӧ����
	��ע��	��
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
	���ܣ�	��ָ����ַ��ʼд��ָ�����ȵ�����
	������	WriteAddr  ��ʼ��ַ
            pBuffer    ����ָ��
            NumToWrite ����(16λ)��   
	���أ�	��
	��ע��	��
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
	���ܣ�	��ָ����ַ��ʼ����ָ�����ȵ�����
	������	WriteAddr  ��ʼ��ַ
            pBuffer    ����ָ��
            NumToWrite ����(16λ)��   
	���أ�	��
	��ע��	��
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
