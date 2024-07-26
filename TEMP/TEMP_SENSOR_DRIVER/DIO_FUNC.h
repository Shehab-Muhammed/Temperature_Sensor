#ifndef DIO_FUNC
#define	DIO_FUNC
#include "TYPEDEF.h"
#include "STD_MACROS.h"
#include "INPUT_OUTPUT_REGISTERS.h"
#define LOW_NIPPLE 0
#define HIGH_NIPPLE 1
void	DIO_SET_PIN_DIRECTION	(uint_8 port,uint_8 pin,uint_8 dir);
void	DIO_PORT_PIN_WRITE		(uint_8 port,uint_8 pin,uint_8 val);
																				//PINS
void	DIO_TOGGLE_PORT_PIN		(uint_8 port,uint_8 pin);
uint_8	DIO_PIN_READ			(uint_8 port,uint_8 pin);
/*________________________________________________________________________*/
void	DIO_SET_PORT_DIRECTION	(uint_8 port,uint_8 dir);
void	DIO_PORT_WRITE			(uint_8 port,uint_8 val);
																				//PORT
void	DIO_TOGGLE_PORT			(uint_8 port);
uint_8	DIO_READ_PORT			(uint_8 port);

void DIO_WRITE_ON_HIGH_NIPPLE	(uint_8 portname,uint_8 val);
void DIO_WRITE_ON_LOW_NIPPLE	(uint_8 portname,uint_8 val);
/*________________________________________________________________________*/
void DIO_CONNECT_PULL_UP		(uint_8 port,uint_8 pin,uint_8 state);
#define	PULL_UP_ENABLE		1
#define PULL_UP_DISABLE		0
/*________________________________________________________________________*/
#define PIN_OUTPUT	1
#define PIN_INPUT	0
/*________________________________________________________________________*/
#define PIN_HIGH	1
#define PIN_LOW		0


//1-->	void	DIO_SET_PIN_DIRECTION	('PORT',PIN,DIRECTION);									DIO_SETPIN_DIRECTION('A',0,1);
//2-->	void	DIO_PORT_PIN_WRITE		(PORT,PIN,VAL)											DIO_PORT_PIN_WRITE('A',0,0);
//3-->	void	DIO_TOGGLE_PORT_PIN		(PORT,PIN)												DIO_TOGGLE_PORT_PIN('A',1);
//4-->	uint_8	DIO_PIN_READ			(uint_8 port,uint_8 pin);								DIO_PIN_READ('A',1);
//5-->	void	DIO_SET_PORT_DIRECTION	(uint_8 port,uint_8 dir)								DIO_SET_PORT_DIRECTION('A',0xff);
//6-->	void	DIO_PORT_WRITE			(uint_8 port,uint_8 val);								DIO_PORT_WRITE('A',0xff);
//7-->	void	DIO_TOGGLE_PORT			(uint_8 port);											DIO_TOGGLE_PORT('A');
//8-->	uint_8	DIO_READ_PORT			(uint_8 port);											DIO_READ_PORT('A);
//9-->	void	DIO_WRITE_NIPPLE		(uint_8 port,uint_8 NIPPLE_MODE,uint_8 val);			DIO_WRITE_NIPPLE('a'HIGH_NIPPLE,0xff);
#endif