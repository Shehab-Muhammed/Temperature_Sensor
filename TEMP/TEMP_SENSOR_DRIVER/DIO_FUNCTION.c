#include "DIO_FUNC.h"
/*______________________________________________________________________________________________________________________*/ //1----> DIO_SET_PIN_DIRECTION
void DIO_SET_PIN_DIRECTION(uint_8 port,uint_8 pin,uint_8 dir)
{
	if((pin>=0)&&(pin<=7))
	{
				switch(port)

				{
					/*________________________________________________*/
					case'A':
					case'a':
					if (dir==1)
					{
						SET_BIT(DDRA,pin);
					}
					else                           //DDRA
					{
						CLEAR_BIT(DDRA,pin);
					}
					break;
					/*________________________________________________*/
					case'B':
					case'b':
					if(dir==1)
					{
						SET_BIT(DDRB,pin);
					}
					else                            //DDRB
					{
						CLEAR_BIT(DDRB,pin);
					}
					break;
					/*________________________________________________*/
					case'C':
					case'c':
					if(dir==1)
					{
						SET_BIT(DDRC,pin);
					}
					else                            //DDRC
					{
						CLEAR_BIT(DDRC,pin);
					}
					break;
					/*________________________________________________*/
					case'D':
					case'd':
					if(dir==1)
					{
						SET_BIT(DDRD,pin);
					}
					else                              //DDRD
					{
						CLEAR_BIT(DDRD,pin);
					}
					break;
					/*________________________________________________*/
					default:
					break;
				}			
		}				
			
}
/*______________________________________________________________________________________________________________________*/ //2----> DIO_PORT_PIN_WRITE
void DIO_PORT_PIN_WRITE(uint_8 port,uint_8 pin,uint_8 val)
{
	
	if((pin>=0)&&(pin<=7))
	
	{		
				switch(port)
		
					{
						/*_____________________________________________*/				
						case 'A':
						case 'a':
						if(val==1)
						{
							SET_BIT(PORTA,pin);
						}												//PORTA
						else
						{
							CLEAR_BIT(PORTA,pin);
						}
						break;
						/*_____________________________________________*/					
						case 'B':
						case 'b':
						if(val==1)
						{
							SET_BIT(PORTB,pin);
						}												//PORTB
						else
						{
							CLEAR_BIT(PORTB,pin);
						}
						break;
						/*_____________________________________________*/				
						case 'C':
						case 'c':
						if(val==1)
						{
							SET_BIT(PORTC,pin);
						}												//PORTC
						else
						{
							CLEAR_BIT(PORTC,pin);
						}
						break;	
						/*_____________________________________________*/
						case 'D':
						case 'd':
						if(val==1)
						{
							SET_BIT(PORTD,pin);
						}												//PORTD
						else
						{
							CLEAR_BIT(PORTD,pin);
						}
						break;
						/*_____________________________________________*/
						default:
						break;
					}
	
	}			
}
/*______________________________________________________________________________________________________________________*/ //3----> DIO_TOGGLE_PORT_PIN
void DIO_TOGGLE_PORT_PIN(uint_8 port,uint_8 pin)
{
		if((pin>=0)&&(pin<=7))
		
		{
				switch(port)
		
				{
					/*_____________________________________________*/
					case 'A':
					case 'a':
					TOGGLE_BIT(PORTA,pin);												//PORTA
					break;
					/*_____________________________________________*/
					case 'B':
					case 'b':
					TOGGLE_BIT(PORTB,pin);												//PORTB
					break;
					/*_____________________________________________*/
					case 'C':
					case 'c':
					TOGGLE_BIT(PORTC,pin);												//PORTC
					break;
					/*_____________________________________________*/
					case 'D':
					case 'd':
					TOGGLE_BIT(PORTD,pin);												//PORTD
					break;
					/*_____________________________________________*/
					default:
					break;
				}
		
		}
}
/*______________________________________________________________________________________________________________________*/ //4----> DIO_READ_PIN
uint_8 DIO_PIN_READ(uint_8 port,uint_8 pin)
{
		uint_8 pin_status=0;
		if((pin>=0)&&(pin<=7))
			
		{
				switch(port)
				
				{
					/*_____________________________________________*/
					case 'A':
					case 'a':
					pin_status=READ_BIT(PINA,pin);													//PORTA
					break;
					/*_____________________________________________*/
					case 'B':
					case 'b':
					pin_status=READ_BIT(PINB,pin);													//PORTB
					break;
					/*_____________________________________________*/
					case 'C':
					case 'c':
					pin_status=READ_BIT(PINC,pin);													//PORTC
					break;
					/*_____________________________________________*/
					case 'D':
					case 'd':
					pin_status=READ_BIT(PIND,pin);													//PORTD
					break;
					/*_____________________________________________*/
					default:
					break;
				}
				
		}
	
	return pin_status;
}
/*______________________________________________________________________________________________________________________*/ //5----> DIO_SET_PORT_DIRECTION
void DIO_SET_PORT_DIRECTION(uint_8 port,uint_8 dir)
	{
				switch(port)

				{
					/*________________________________________________*/
					case'A':
					case'a':	
					DDRA=dir;											//DDRA
					break;
					/*________________________________________________*/
					case'B':
					case'b':
					DDRB=dir;											//DDRB
					break;
					/*________________________________________________*/
					case'C':
					case'c':
					DDRC=dir;											//DDRC
					break;
					/*________________________________________________*/
					case'D':
					case'd':
					DDRD=dir;											//DDRD
					break;
					/*________________________________________________*/
					default:
					break;
				}

	
	}
/*______________________________________________________________________________________________________________________*/ //6----> DIO_PORT_WRITE

void DIO_PORT_WRITE(uint_8 port,uint_8 val)
	{
			switch(port)

			{
				/*________________________________________________*/
				case'A':
				case'a':
				PORTA=val;											//PORTA
				break;
				/*________________________________________________*/
				case'B':
				case'b':
				PORTB=val;											//PORTB
				break;
				/*________________________________________________*/
				case'C':
				case'c':
				PORTC=val;											//PORTC
				break;
				/*________________________________________________*/
				case'D':
				case'd':
				PORTD=val;											//PORTD
				break;
				/*________________________________________________*/
				default:
				break;
			}

	
	}
/*______________________________________________________________________________________________________________________*/ //7----> DIO_READ_PORT
uint_8	DIO_READ_PORT(uint_8 port)
{
			uint_8 port_status;
			switch(port)
			{
				case'A':
				case'a':
				port_status=PINA;									//PORTA
				break;
				/*________________________________________________*/
				case'B':
				case'b':
				port_status=PINB;									//PORTB
				break;
				/*________________________________________________*/
				case'C':
				case'c':
				port_status=PINC;									//PORTC
				break;
				/*________________________________________________*/
				case'D':
				case'd':
				port_status=PIND;									//PORTD
				break;
				/*________________________________________________*/
				default:
				break;
			}
	
	return port_status;	
	
}
/*______________________________________________________________________________________________________________________*/ //8----> DIO_TOGGLE_PORT
void	DIO_TOGGLE_PORT			(uint_8 port)
{
			switch(port)
			{
				case'A':
				case'a':
				PORTA=~PORTA;										//PORTA
				break;
				/*________________________________________________*/
				case'B':
				case'b':
				PORTB^=0xff;										//PORTB
				break;
				/*________________________________________________*/
				case'C':
				case'c':
				PORTC^=0xff;										//PORTC
				break;
				/*________________________________________________*/
				case'D':
				case'd':
				PORTD^=0xff;										//PORTD
				break;
				/*________________________________________________*/
				default:
				break;
			}
			
}
void DIO_WRITE_ON_HIGH_NIPPLE(uint_8 portname,uint_8 val)
{
	val<<=4;
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA&=0x0f;
		PORTA|=val;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0x0f;
		PORTB|=val;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0x0f;
		PORTC|=val;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0x0f;
		PORTD|=val;
		break;
	}
}
void DIO_WRITE_ON_LOW_NIPPLE(uint_8 portname,uint_8 val)
{
	val&=0x0f;
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=val;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0xf0;
		PORTB|=val;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=val;
		break ;
		
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=val;
		break;
	}
}

/*___________________________________________________________________________PULL_UP_____________________________________________________________*/

void DIO_CONNECT_PULL_UP(uint_8 port,uint_8 pin,uint_8 state)
{
	DIO_PORT_PIN_WRITE(port,pin,state);
}

/*___________________________________________________________________END OF FUNCTIONS_______________________________________________________*/