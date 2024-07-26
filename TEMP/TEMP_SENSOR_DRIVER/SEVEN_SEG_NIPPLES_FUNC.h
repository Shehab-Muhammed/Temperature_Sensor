#ifndef		SEVEN_SEG_NIPPLES_FUNC
#define		SEVEN_SEG_NIPPLES_FUNC
void		SEVEN_SEG_HIGH_NIPPLE_INIT		(uint_8 port);
void		SEVEN_SEG_LOW_NIPPLE_INIT		(uint_8 port);
void		SEVEN_SEG_WRITE_NIPPLE			(uint_8 port,uint_8 NIPPLE_MODE,uint_8 value);
void		NIPPLE_SEVEN_SEG_ON				(uint_8 port,uint_8 NIPPLE_MODE);
void		NIPPLE_SEVEN_SEG_OFF			(uint_8 port,uint_8 NIPPLE_MODE);
void		NIPPLE_SEVEN_SEG_BLINK			(uint_8 port,uint_8 NIPPLE_MODE);
uint_8		NIPPLE_SEVEN_SEG_STATE			(uint_8 port,uint_8 NIPPLE_MODE);
#endif
/*__________________________________________________________________________________________________________________________________________*/
/*________________________________________________________________NIPPLE_MODE_______________________________________________________________*/