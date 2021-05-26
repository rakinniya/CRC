/*
 * CRC_new.c
 *
 *  Created on: May 14, 2021
 *      Author: raki
 */

/*
Preprocessor Defenitions
*/
#define CRC_INIT (0xFFFF)
#include <stdio.h>
/*
Type defenitions
*/
typedef unsigned int ui32;
typedef unsigned short int ui16;
typedef unsigned char ui8;

ui32 CRC_16_CCITT(ui8* bitstream,ui32 len)
{
	/*
	Local Variables
	*/
	ui32 Polnoml=0x11021;//1 0001 0000 0010 0001
	ui32 CRC_buf=CRC_INIT;//1111 1111 1111 1111
	ui32 BYTE=0,dividnd=0;
	ui8 BYTE_Len=0,BIT=0,index;
	
	if(bitstream==NULL)
		return 0;
	
	for(index=0;index<len;index++)
	{
		printf("index=%d   ",index);//DEBUG
		BYTE=bitstream[index];
		printf("BYTE=%x   \n",0x0FF&BYTE);//DEBUG
		BYTE_Len=8;
		while(BYTE_Len--)
		{
			printf("CRC_buf=%x   ",0x1FFFF&CRC_buf);//DEBUG
			dividnd=(CRC_buf<<1)&0x1FFFF;
			BIT=( (BYTE>>(BYTE_Len)) &0x1 );
			printf("BIT=%d   ",BIT);//DEBUG
			dividnd=dividnd|BIT;
			printf("dividnd=%x  ",0x01FFFF&dividnd);//DEBUG
			/*
			compute
			*/
			if((dividnd>>16)==1)
			{
				CRC_buf=dividnd^Polnoml;
				printf("XORed CRC_buf=%x   ",0x1FFFF&CRC_buf);//DEBUG
			}
			else
			{
				CRC_buf=dividnd;//CRC_buf=(dividnd<<1)&0x1FFFF;
				printf("CRC_buf left shift=%x   ",0x1FFFF&CRC_buf);//DEBUG
			}
			printf(" \n");
		}
		printf("\n");//DEBUG
	}
	for(index=0;index<16;index++)
	{
		printf("CRC_buf=%x   ",0x1FFFF&CRC_buf);//DEBUG
		dividnd=CRC_buf<<1;
		printf("BIT=%d   ",0);//DEBUG
		printf("dividnd=%x  ",0x01FFFF&dividnd);//DEBUG
		if((dividnd>>16)==1)
			{
				CRC_buf=dividnd^Polnoml;
				printf("XORed CRC_buf=%x   ",0x1FFFF&CRC_buf);//DEBUG
			}
			else
			{
				CRC_buf=(CRC_buf<<1)&0x1FFFF;
			}
		printf(" \n");
	}
	return CRC_buf;
}
int main()
{
	testcode1();
	testcode2();
	testcode3();
	testcode4();
	return 0;
}
// Normal Case :
void testcode1()
{
	unsigned char data[10]={0x41}; //0100 0001	
	ui32 len,CRC=0;
	
	printf("\nTestcode1 \n");

	len=1;
	CRC=CRC_16_CCITT(data,len);
	if(CRC==0x9479)
	{
		printf("\nTestcode1 PASSED\n\n");
	}
	else
	{
		printf("\nTestcode1 FAILED\n\n");
	}
}

void testcode2()
{
	unsigned char data[10]={0x41}; //0100 0001
	ui32 len,CRC=0;
	
	printf("\nTestcode2 \n");
	
	len=0;
	CRC=CRC_16_CCITT(data,len);
	printf("CRC=%x",CRC);
}

void testcode3()
{
	unsigned char data[1234]={0}; //0100 0001
	ui32 len,CRC=0;
	
	printf("\nTestcode3 \n");
	
	len=1;
	CRC=CRC_16_CCITT(data,len);
	if(CRC==0xCC9C)
	{
		printf("\nTestcode3 PASSED\n\n");
	}
	else
	{
		printf("\nTestcode3 FAILED\n\n");
	}
}

void testcode4()
{
	unsigned char data[1234]={0}; //0100 0001
	ui32 len,CRC=0;
	len=1234;
	
	printf("\nTestcode4 \n");
	CRC=CRC_16_CCITT(NULL,len);
	if(CRC==0)
	{
		printf("Testcode4 PASSED\n\n");
	}
	else
	{
		printf("Testcode4 FAILED\n\n");
	}
}
