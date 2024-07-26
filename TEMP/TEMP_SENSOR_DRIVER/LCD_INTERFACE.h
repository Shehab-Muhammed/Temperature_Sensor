#ifndef LCD_INTERFACE
#define LCD_INTERFACE
#include "LCD_CONFIFGURATION.h"
#include "TYPEDEF.h"
#include "DIO_FUNC.h"
#define	  F_CPU 8000000UL
#include <util/delay.h>
/*___________________________________________________________LCD_CONFIGURATION__________________________________________________________________*/
#define	HIGH_NIPPLE			1
#define	LOW_NIPPLE			0
#define LCD_PORT			'A'			//LCD_PORT
#define LCD_CONTROL_PORT	'B'			//--RS-RW-E_PINS
#define RS_PIN				0			//RS_PIN_NUMPER
#define RW_PIN				1			//RW_PIN_NUMPER
#define EN_PIN				2			//E_PIN_NUMPER
#define PIN_OUTPUT			1			//DDR_PIN_INIT
#define PIN_INPUT			0			//DDR_PIN_OUT
#define PORT_OUTPUT			0xff		//PORT_INIT
#define PORT_INPUT			0x00		//PORT_OUT
#define HIGH				1			//PORT_PIN_HIGH
#define LOW					0			//PORT_PIN_LOW
/*_________________________________________________________________ LCD_MACROS__________________________________________________________________*/


#define LCD_ClEAR					0x01          /* replace all characters with ASCII 'space'                       */
#define LCD_HOME					0x02          /* return cursor to first position on first line                   */
#define LCD_ENTRY_MODE				0x06          // shift cursor from left to right on read/write
#define LCD_DISPLAY_OFF				0x08          // turn display off
#define LCD_DSPLAY_ON_CURSOR_ON		0x0C          // display on, cursor ON, don't blink character 0x0C display on, cursor OFF
#define LCD_FUNCTION_RESET			0x30          // reset the LCD
#define LCD_CURSOR_SET				0x80          // set cursor position

/*_________________________________________________________________ LCD_8_BIT_FUNCTION__________________________________________________________________ */

void			LCD_INIT					(void);
void			LCD_SEND_COMMAND			(uint_8 CMD);
void			LCD_SEND_DATA				(uint_8 DATA);
void			LCD_WRITE_STRING			(uint_8* STRING);
void			MOVE_CURSOR					(uint_8 ROW,uint_8 COULMN);

/*_________________________________________________________________ LCD_8_BIT_INTERFACE___________________________________________________________ */

static void		ENABLE_PULSE				(void);

/*_________________________________________________________________ LCD_4_BIT_INTERFACE___________________________________________________________ */

void			LCD_4_BIT_INIT				(uint_8 NIPPLE);
void			LCD_SEND_DATA_FOUR_BIT		(uint_8 DATA,uint_8 NIPPLE);
void			LCD_SEND_CMD_FOUR_BIT		(uint_8 CMD,uint_8 NIPPLE);
void			LCD_WRITE_STRING_4_BIT		(uint_8* STRING);
void			MOVE_CURSOR_4_BIT			(uint_8 ROW,uint_8 COULMN);

#endif
/*_________________________________________________________________ LCD_4_BIT_INTERFACE___________________________________________________________ */
