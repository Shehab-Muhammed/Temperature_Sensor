#ifndef STD_MACROS
#define STD_MACROS
#define	DIO_FUNC
#define	REG_SIZE 8
#define SET_BIT(reg,bit)	    reg|=(1<<bit)
#define CLEAR_BIT(reg,bit) 	    reg&=(~(1<<bit))
#define TOGGLE_BIT(reg,bit) 	reg^=(1<<bit)
#define READ_BIT(reg,bit)	    ((reg>>bit)&1) // ((reg & (1<<bit))>>bit)
#define ROTATE_LEFT(reg,bit)	reg=(reg<<bit)|(reg>>(REG_SIZE-bit))
#define ROTATE_RIGHT(reg,bit)	reg=(reg>>bit)|(reg<<(REG_SIZE-bit))
#endif