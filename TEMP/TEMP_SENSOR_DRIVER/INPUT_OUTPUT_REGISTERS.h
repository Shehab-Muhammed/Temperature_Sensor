#ifndef INPUT_OUTPUT_REGISTERS
#define	INPUT_OUTPUT_REGISTERS
#include "TYPEDEF.h"
#define PORTA	*((volatile uint_8* )(0x003B))  //ACCESS PORTA
#define DDRA	*((volatile uint_8* )(0x003A))	//ACCESS DDRA
#define PINA	*((volatile uint_8* )(0x0039))	//ACCESS PINA
/*_______________________________________________________________________*/
#define PORTB	*((volatile uint_8* )(0x0038))	//ACCESS PORTB
#define DDRB	*((volatile uint_8* )(0x0037))	//ACCESS DDRB
#define PINB	*((volatile uint_8* )(0x0036))	//ACCESS PINB
/*_______________________________________________________________________*/
#define PORTC	*((volatile uint_8* )(0x0035))	//ACCESS PORTC
#define DDRC	*((volatile uint_8* )(0x0034))	//ACCESS DDRC
#define PINC	*((volatile uint_8* )(0x0033))	//ACCESS PINC
/*_______________________________________________________________________*/
#define PORTD	*((volatile uint_8* )(0x0032))	//ACCESS PORTD
#define DDRD	*((volatile uint_8* )(0x0031))	//ACCESS DDRD
#define PIND	*((volatile uint_8* )(0x0030))	//ACCESS PIND
/*_______________________________________________________________________*/
#endif