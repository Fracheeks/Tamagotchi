/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/


/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

#include "LPC17xx.h" 
#include "../GLCD/GLCD.h"
#include "../RIT/rit.h"
#include "../timer/timer.h"
#include "../TouchPanel/TouchPanel.h"
#include "../adc/adc.h"

void reset();
volatile int type=0, /*MEAL = 1 SNACK=2*/ selected=0, isReseted=0, cuddle=0, isEating=0, firstNote=0, lastNote=0;
extern int Index1,Index2;
void battery_updates(int index, int verse, int bar);
void tamagotchi1(int x,int y,int pos);
void PlaySong(int firstNote,int lastNote);

void RIT_IRQHandler (void)
{	
	if(!isReseted) ADC_start_conversion();
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0 && !selected && !type && !isReseted){ //left
	firstNote=3; lastNote=4;
	PlaySong(firstNote, lastNote);
	disable_timer(1);
	LCD_DrawRectangle (20,260,90,30, Yellow);
	GUI_Text(50,267, (uint8_t *) "MEAL" ,Blue2,Yellow);
	type=1;
	selected++;

	}
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0 && !selected && !type && !isReseted){ //right
	firstNote=3; lastNote=4;
	PlaySong(firstNote, lastNote);
	disable_timer(1);
	LCD_DrawRectangle (130,260,90,30, Yellow);
	GUI_Text(157,267, (uint8_t *) "SNACK" ,Blue2,Yellow);
	type=2;
	selected++;
	}
	
	if(type && selected && !isReseted){ //se viene selezionata un'opzione tra "meal" e "snack" (colorazione del punsalte di giallo)
                                      //ma non viene confermata tramite la pressione effettuata sul joystick, il pulsante viene deselezionato 
																			//una volta che il parametro "selected" è stato incrementato fino a 4
		selected++;
		if(selected==4 && (LPC_GPIO1->FIOPIN & (1<<25))){
			enable_timer(1);
			selected=0;
			if(type==2){
			 LCD_DrawRectangle(132,262,88,28,Black);
			  GUI_Text(157,267, (uint8_t *) "SNACK" ,Blue2,Black);}
			else if(type==1){
			 LCD_DrawRectangle(22,262,88,28,Black);
			 GUI_Text(50,267, (uint8_t *) "MEAL" ,Blue2,Black);}
			type=0;
		}
	}
	
	/*selected: controllo delle selezione di uno tra i due pulsanti
	 isReseted:  controllo per effettuare il reset del gioco
	 type: definizione della scelta effettuata tramite joystick */
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0 && type && selected && !isReseted){ //select - EATING
		  firstNote=2, lastNote=11;
		  PlaySong(firstNote, lastNote);
		  isEating=1;
		  disable_timer(1);
		  reset_timer(1);
			disable_RIT(); //disabilita la possibilità di selezionare nuovamente "meal" o "snack" durante l'assunzione di un pasto
		  tamagotchi1(60,80,0);
		  selected=0;
		  if (type==1) {
				LCD_DrawCircle(145,175,10,Yellow);}
			else if (type==2) {
				LCD_DrawRectangle(135,165,20,20,Green);}
			enable_timer(3);
	}
	else if((LPC_GPIO1->FIOPIN & (1<<25)) == 0 && !type && !selected && isReseted){ //select - DYING
		LCD_DrawRectangle (20,260,200,30, Yellow);
		GUI_Text(100,267,(uint8_t *)"RESET",Black,Yellow);
		reset_timer(1);
		reset_RIT();
		
		reset();
	}
	
		
  if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
		if(display.x >95 && display.x<143 && display.y>121 && display.y<195){
			cuddle=1;
		  firstNote=0; lastNote=3;
		  PlaySong(firstNote, lastNote);}
		}
	
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}
/******************************************************************************
**                            End Of File
******************************************************************************/
