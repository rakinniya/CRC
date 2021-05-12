/*
Preprocessor Defenitions
*/
#define CRC_INIT (0xFFFF)

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
	ui32 dividnd;
	ui8 BYTE,BIT;
	ui32 Polnoml=0x11021; //1 0001 0000 0010 0001
	ui32 CRC_buf=CRC_INIT;//1 1111 1111 1111 111*
	
	for(i=0;i<len;i++)
	{
		BYTE=bitstream[i]; 
		BYTE_Len=8;
		while(BYTE_Len--)
		{
			dividnd=CRC_buf;
			dividnd=(dividnd<<1)&0x1FFFE;
			BIT=( (BYTE>>(BYTE_Len-1)) &0x1 );  
			dividnd=dividnd|BIT;
			/*
			compute 
			*/
			if((dividnd&0x10000)==0x10000) 
			{
				CRC_buf=dividnd^Polnoml;
			}
		}
	}
	for(i=
}
void main()
{
	//CRC
char data={0xab,0xcd,0xef,0xab,0xcd,0xef};
ui32 len;

len=6;
CRC=CRC_16_CCITT(data,len);
printf("CRC=%x",CRC);
}