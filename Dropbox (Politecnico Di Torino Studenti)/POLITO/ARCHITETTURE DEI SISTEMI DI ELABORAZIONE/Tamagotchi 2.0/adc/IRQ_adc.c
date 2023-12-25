/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../timer/timer.h"
#include "../GLCD/GLCD.h" 

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;
int amp=1;
unsigned short AD_last = 0xFF;     /* Last converted value               */

void ADC_IRQHandler(void) {
  char num[1];
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */
  if(AD_current != AD_last){
		amp=AD_current*8/0xFFF;
		
		  num[0]= amp + '0';
	if(amp==0){
			  LCD_DrawRectangle(105,244,4,4,Red);LCD_DrawRectangle(109,240,4,4,Red);
				LCD_DrawRectangle(115,236,4,4,Red);LCD_DrawRectangle(119,232,4,4,Red);
				LCD_DrawRectangle(123,228,4,4,Red);LCD_DrawRectangle(127,224,4,4,Red);
				LCD_DrawRectangle(131,220,4,4,Red);LCD_DrawRectangle(135,216,4,4,Red);}
		else{
			  
			  LCD_DrawRectangle(105,244,4,4,Black);LCD_DrawRectangle(109,240,4,4,Black);
			  LCD_DrawRectangle(115,236,4,4,Yellow);LCD_DrawRectangle(119,232,4,4,Yellow);
				LCD_DrawRectangle(123,228,4,4,Yellow);LCD_DrawRectangle(127,224,4,4,Yellow);
				LCD_DrawRectangle(131,220,4,4,Yellow);LCD_DrawRectangle(135,216,4,4,Black);
		    GUI_Text(110,226, (uint8_t *) num ,Black,Yellow);}
		
		AD_last = AD_current;
  }
	
}
