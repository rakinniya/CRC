/*
Preprocessor Defenitions
#define CRC_INIT 0xFFFF
*/
/*
Type defenitions
*/
typedef int ui32;
typedef short int ui16;
typedef char ui8;

ui16 CRC_16_CCITT(ui8* bitstream,ui32 len)
{
	/*
	Local Variables
	*/
	ui32 Polnoml=0x11021;//1 0001 0000 0010 0001
	ui32 CRC_buf=CRC_INIT;//1 1111 1111 1111 111*
	
	for(i=0;i<len;i++)
	{
		BYTE=bitstream[i]; 
		BYTE_Len=8;
		while(BYTE_Len--)
		{
			dividnd=CRC_buf;
			BIT=( (BYTE>>8) &0x1 );
			dividnd=dividnd|BIT;
			/*
			compute 
			*/
			if(BIT==1) 
			{
				CRC_buf=dividnd^CRC_buf;
			}
			BYTE=(BYTE<<1)&0X8;
		}
	}
}
	
	
	
	
}

void main()
{
	//CRC
}