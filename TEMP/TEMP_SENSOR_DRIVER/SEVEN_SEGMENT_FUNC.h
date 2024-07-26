#ifndef		SEVEN_SEG_FUNC
#define		SEVEN_SEG_FUNC
#include	"DIO_FUNC.h"
#define		F_CPU 8000000
#include	<util/delay.h>
#include	"SEVEN_SEG_NIPPLES_FUNC.h"
void		SEVEN_SEG_INIT					(uint_8 port,uint_8 dir);
void		SEVEN_SEG_ON					(uint_8 port);
void		SEVEN_SEG_OFF					(uint_8 port);
void		SEVEN_SEG_BLINK					(uint_8 port);
void		SEVEN_SEG_VALUE					(uint_8 port,uint_8 num);
uint_8		SEVEN_SEG_STATE					(uint_8 port);
uint_8		SWITCH_STATE					(uint_8 port,uint_8 pin);
#endif
/*________________________________________________________________BYTE_MODE_________________________________________________________________*/
/*__________________________________________________________________________________________________________________________________________*/
