#include "TEMP_SENSOR_FUNC.h"
#define OFFSET	1000
void main(void)
{
	uint_16 volt;
	uint_16	temp;
	uint_8 indicator;
	SEVEN_SEG_LOW_NIPPLE_INIT('c');
	TEMP_SENSOR_INIT();
	LCD_4_BIT_INIT(HIGH_NIPPLE);
	LCD_WRITE_STRING_4_BIT("TEMPRATURE=");
	while(1)
	{
		volt=ADC_READ()*2.5;
			if(volt>=OFFSET)
			{	
				MOVE_CURSOR_4_BIT(1,12);
				temp=(volt-OFFSET)/10;
						if (temp<10)
						{
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);
							indicator=2;
						}
						else if((temp<26) && (temp>=10))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/10)+48,HIGH_NIPPLE);		/****************/
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);		/****+VE_TEMP****/
							indicator=3;											/****************/
						}
						else if((temp<=40) && (temp>=26))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/10)+48,HIGH_NIPPLE);		/****************/
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);		/****+VE_TEMP****/
							indicator=4;											/****************/
						}
						else if((temp<81) && (temp>=41))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/10)+48,HIGH_NIPPLE);		/****************/
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);		/****+VE_TEMP****/
							indicator=5;											/****************/
						}
						else if((temp<100) && (temp>=81))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/10)+48,HIGH_NIPPLE);		/****************/
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);		/****+VE_TEMP****/
							indicator=6;											/****************/
						}															/****************/
				
						else if((temp>=100) && (temp<=120))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/100)+48,HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT(((temp/10)%10)+48,HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);
							indicator=7;
						}
						else if((temp>120) && (temp<=150))
						{
							LCD_SEND_DATA_FOUR_BIT((temp/100)+48,HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT(((temp/10)%10)+48,HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);
							indicator=8;
						}
			}
			else if(volt<OFFSET)
			{		
					MOVE_CURSOR_4_BIT(1,12);
					temp=(OFFSET-volt)/10;
						if ((temp>=0)&&(temp<10) )
						{
							LCD_SEND_DATA_FOUR_BIT('-',HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);
							indicator=1;
						}
						else if((temp>9) && (temp<=55))
						{
							LCD_SEND_DATA_FOUR_BIT('-',HIGH_NIPPLE);
							LCD_SEND_DATA_FOUR_BIT((temp/10)+48,HIGH_NIPPLE);		/****************/
							LCD_SEND_DATA_FOUR_BIT((temp%10)+48,HIGH_NIPPLE);		/****+VE_TEMP****/
							indicator=0;
						}															

			 }
			LCD_SEND_DATA_FOUR_BIT(0xDF,HIGH_NIPPLE);
			LCD_SEND_DATA_FOUR_BIT('c',HIGH_NIPPLE);		//------->RETURNED_DATA
			LCD_SEND_DATA_FOUR_BIT(0x20,HIGH_NIPPLE);
			switch(indicator)
			{
				case 0:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,0);
				break;
				
				case 1:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,1);
				break;
				
				case 2:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,2);
				break;
				
				case 3:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,3);
				break;
				
				case 4:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,4);
				break;
				
				case 5:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,5);
				break;
				
				case 6:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,6);
				break;
				
				case 7:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,7);
				break;
				
				case 8:
				SEVEN_SEG_WRITE_NIPPLE ('c',LOW_NIPPLE,8);
				break;
			
				
			}
			
	}
	
}