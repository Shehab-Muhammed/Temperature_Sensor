#include "SEVEN_SEG.h"
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/


/*_____________________________________________________________________________________________________________________________*/ //1-->SEVEN_SEG_INIT
void SEVEN_SEG_INIT(uint_8 port,uint_8 dir)
{
	DIO_SET_PORT_DIRECTION(port,dir);
}
/*_____________________________________________________________________________________________________________________________*/ //2-->SEVEN_SEG_ON
void SEVEN_SEG_ON(uint_8 port)
{
	DIO_PORT_WRITE(port,0xff);
}
/*_____________________________________________________________________________________________________________________________*/ //3-->SEVEN_SEG_OFF
void SEVEN_SEG_OFF(uint_8 port)
{
	DIO_PORT_WRITE(port,0x00);
}
/*_____________________________________________________________________________________________________________________________*/ //4-->SEVEN_SEG_BLINK
void SEVEN_SEG_BLINK(uint_8 port)
{
	SEVEN_SEG_ON   (port);
	_delay_ms(200);
	SEVEN_SEG_OFF  (port);
	_delay_ms(200);
}
/*_____________________________________________________________________________________________________________________________*/ //5-->SEVEN_SEG_STATE
uint_8 SEVEN_SEG_STATE(uint_8 port)
{
	return DIO_READ_PORT(port);
}
/*_____________________________________________________________________________________________________________________________*/ //6-->SEVEN_SEG_NUM

void SEVEN_SEG_VALUE(uint_8 port,uint_8 num)
{
	#if defined COMMAN_CATHODE
	uint_8 arr[10]={63,6,91,79,102,109,125,7,127,111};
	#elif defined COMMAN_ANODE	
	uint_8 arr[10]={~63,~6,~91,~79,~102,~109,~125,~7,~127,~111};
	#endif		
	switch(port)
	{
		case'A' :
		case'a' :
		PORTA=arr[num];
		break;
		/*___________*/ //PORTA
		case'B' :
		case'b' :
		PORTB=arr[num];
		break;
		/*___________*/	//PORTD
		case'C' :
		case'c' :
		PORTC=arr[num];
		break;
		/*___________*/ //PORTC
		case'D' :
		case'd' :
		PORTD=arr[num];
		break;	
		/*__________*/	//PORTD
		
		
	}
	
}
/*______________________________________________________________________________________________________________________________*/ //7--> SWITCH_STATE

uint_8	SWITCH_STATE		(uint_8 port,uint_8 pin)
{
	return DIO_PIN_READ(port,pin);
}

/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/






/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_INIT
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_INIT
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_INIT
void SEVEN_SEG_HIGH_NIPPLE_INIT(uint_8 port)
{
	DIO_SET_PIN_DIRECTION(port,4,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,5,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,6,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,7,PIN_OUTPUT);
	
}

/*__________________________________________________HIGH_NIPPLE_INIT_____________________________________________*/

void SEVEN_SEG_LOW_NIPPLE_INIT(uint_8 port)
{
	DIO_SET_PIN_DIRECTION(port,0,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,1,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,2,PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(port,3,PIN_OUTPUT);
	
}
/*__________________________________________________LOW_NIPPLE_INIT_____________________________________________*/



//--------------------------------------------------------------------------------->SEVEN_NIPPLE_WRITE
//--------------------------------------------------------------------------------->SEVEN_NIPPLE_WRITE
//--------------------------------------------------------------------------------->SEVEN_NIPPLE_WRITE
void SEVEN_SEG_WRITE_NIPPLE(uint_8 port,uint_8 NIPPLE_MODE,uint_8 val)
{
	switch(NIPPLE_MODE)
	{
		case NIPPLE_HIGH:
			if((val>=0)&&(val<=9))
			{
				switch (port)
				{
					case 'a':
					case 'A':
					PORTA=PORTA&0x0f;
					val=((val<<4)& 0xf0);
					PORTA=PORTA|val;
					break;
					case 'b':
					case 'B':
					PORTB=PORTB&0x0f;
					val=((val<<4)& 0xf0);
					PORTB=PORTB|val;
					break;
					case 'c':
					case 'C':
					PORTC=PORTC&0x0f;
					val=((val<<4)& 0xf0);
					PORTC=PORTC|val;
					break;
					case 'd':
					case 'D':
					PORTD=PORTD&0x0f;
					val=((val<<4)& 0xf0);
					PORTD=PORTD|val;
					break;
				}
				
			}
			break;
/*_________________________________________________HIGH_NIPPLE_WRITE_____________________________________________*/
			case NIPPLE_LOW:
			if((val>=0)&&(val<=9))
			{
				switch (port)
				{
					case 'a':
					case 'A':
					PORTA=PORTA&0xf0;
					val=(val & 0x0f);
					PORTA=PORTA|val;
					break;
					case 'b':
					case 'B':
					PORTB=PORTB&0xf0;
					val=(val & 0x0f);
					PORTB=PORTB|val;
					break;
					case 'c':
					case 'C':
					PORTC=PORTC&0xf0;
					val=(val & 0x0f);
					PORTC=PORTC|val;
					break;
					case 'd':
					case 'D':
					PORTD=PORTD&0xf0;
					val=(val & 0x0f);
					PORTD=PORTD|val;
					break;
				}
		
			}
			break;
/*__________________________________________________LOW_NIPPLE_WRITE_____________________________________________*/
	}
	
}

//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_ON
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_ON
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_ON
void NIPPLE_SEVEN_SEG_ON(uint_8 port,uint_8 NIPPLE_MODE)
{
	switch(NIPPLE_MODE)
	{
			case 1:
			SEVEN_SEG_WRITE_NIPPLE(port,NIPPLE_MODE,8);
			break;
/*__________________________________________________HIGH_NIPPLE_ON_____________________________________________*/
			case 0:
			SEVEN_SEG_WRITE_NIPPLE(port,NIPPLE_MODE,8);
			break;
		
/*__________________________________________________LOW_NIPPLE_ON_____________________________________________*/
	}
}

//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_OFF
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_OFF
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_OFF
void NIPPLE_SEVEN_SEG_OFF(uint_8 port,uint_8 NIPPLE_MODE)
{
	switch(NIPPLE_MODE)
	{
		case 1:
		DIO_SET_PIN_DIRECTION(port,4,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,5,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,6,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,7,PIN_INPUT);
		break;
		/*__________________________________________________HIGH_NIPPLE_OFF_____________________________________________*/
		case 0:
		DIO_SET_PIN_DIRECTION(port,0,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,1,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,2,PIN_INPUT);
		DIO_SET_PIN_DIRECTION(port,3,PIN_INPUT);
		break;
		
		/*__________________________________________________LOW_NIPPLE_OFF_____________________________________________*/
	}
}

//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_BLINK
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_BLINK
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_BLINK
void NIPPLE_SEVEN_SEG_BLINK(uint_8 port,uint_8 NIPPLE_MODE)
{
	switch(NIPPLE_MODE)
	{
		case 1:
		NIPPLE_SEVEN_SEG_ON(port,NIPPLE_MODE);
		_delay_ms(200);
		NIPPLE_SEVEN_SEG_OFF(port,NIPPLE_MODE);
		_delay_ms(200);
		DIO_SET_PIN_DIRECTION(port,4,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,5,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,6,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,7,PIN_OUTPUT);
		break;
/*___________________________________________SEVEN_SEG_HIGH_NIPPLE_BLINK_______________________________________*/
		case 0:
		NIPPLE_SEVEN_SEG_ON(port,NIPPLE_MODE);
		_delay_ms(200);
		NIPPLE_SEVEN_SEG_OFF(port,NIPPLE_MODE);
		_delay_ms(200);
		DIO_SET_PIN_DIRECTION(port,0,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,1,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,2,PIN_OUTPUT);
		DIO_SET_PIN_DIRECTION(port,3,PIN_OUTPUT);
		break;
/*___________________________________________SEVEN_SEG_LOW_NIPPLE_BLINK_______________________________________*/
	}

}

//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_STATE
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_STATE
//--------------------------------------------------------------------------------->SEVEN_SEG_NIPPLE_STATE
uint_8 NIPPLE_SEVEN_SEG_STATE(uint_8 port,uint_8 NIPPLE_MODE)
{
	uint_8 NIPPLE_STATE=0;
	switch(NIPPLE_MODE)
	{
			case 1:
				switch(port)
				{
					case 'a':
					case 'A':
					NIPPLE_STATE=((PORTA>>4) & 0x0F);
					break;
					case 'b':
					case 'B':
					NIPPLE_STATE=((PORTB>>4) & 0x0F);
					break;
					case 'c':
					case 'C':
					NIPPLE_STATE=((PORTC>>4) & 0x0F);
					break;
					case 'd':
					case 'D':
					NIPPLE_STATE=((PORTD>>4) & 0x0F);
					break;
				}
			break;
/*________________________________________________________________HIGH_NIPPLE_STATE_________________________________________________________________*/
				case 0:
				switch(port)
				{
					case 'a':
					case 'A':
					NIPPLE_STATE=(PORTA & 0x0F);
					break;
					case 'b':
					case 'B':
					NIPPLE_STATE=(PORTB & 0x0F);
					break;
					case 'c':
					case 'C':
					NIPPLE_STATE=(PORTC>>4 & 0x0F);
					break;
					case 'd':
					case 'D':
					NIPPLE_STATE=(PORTD>>4 & 0x0F);
					break;
				}
			break;
			return NIPPLE_STATE;
	}
/*________________________________________________________________LOW_NIPPLE_STATE____________________________________________________________*/

}

/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_________________________________________________________________*/