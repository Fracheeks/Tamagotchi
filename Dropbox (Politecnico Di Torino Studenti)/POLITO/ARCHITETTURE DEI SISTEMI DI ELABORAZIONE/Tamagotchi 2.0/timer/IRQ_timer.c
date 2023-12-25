/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <string.h>
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h" 
#include <stdio.h>
#include "../RIT/rit.h"

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
volatile int hours=0, minutes=0 ,seconds=-1, pos=0, pos2=0, Index1=5, Index2=5, add=80, fine=0, battery=0, add2=100;
extern int type, amp, cuddle, isEating, isReseted, firstNote, lastNote;
char str[20]="";
void battery_updates(int index, int verse, int bar);
void tamagotchi1(int x,int y, int pos);
void tamagotchi2(int x,int y, int pos);
void tamagotchi3(int x,int y, int pos);
void PlaySong(int firstNote, int lastNote);
void heart(int x, int y, int d, int pos, int color);
uint16_t SinTable[45] =                                                         
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};

void TIMER0_IRQHandler (void)
{
	static int ticks=0;
	/* DAC management */
	LPC_DAC->DACR = (SinTable[ticks]<<6)*amp;
	ticks++;
	if(ticks==45) ticks=0;
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern int isReseted;
void TIMER1_IRQHandler (void) 
{ 
	/*gestione della diminuzione delle tacche degli stati legati all'avanzamento del tempo (ogni 5 secondi)
	  e dell'animazione e tempo di vita del tamagotchi (ogni singolo secondo)
	*/
	
	seconds++;
		
	sprintf(str,"AGE:%02d:%02d:%02d",hours,minutes,seconds);
	GUI_Text(75,0, (uint8_t *) str ,White, Black);
	
	if(seconds==59){
		minutes++;
	  seconds=-1;
	if(minutes==59){		
		hours++;
		minutes=-1;
	}
	
}
	
	battery++;
	if(fine) {LPC_TIM1->IR = 1;return;}
	
	if(battery==6){
		battery=0;
		if (Index1==0 || Index2==0){
			isReseted=1;
			disable_timer(0);
			disable_timer(1);
			disable_RIT();
			battery_updates(Index1,-1,1);
			battery_updates(Index2,-1,2);
	    tamagotchi1(60,80,0);
			firstNote=0, lastNote=11;
			PlaySong(firstNote, lastNote);
			enable_timer(3);
			
			fine=1;
			return;
		}
		else{
		battery_updates(Index2,-1,2);
		Index2--;
		battery_updates(Index1,-1,1);
		Index1--;}
	}
			pos++;
		if(pos==4) pos=0; LCD_DrawRectangle (123,130,5,10, Black);
		if(pos==2) LCD_DrawRectangle (128,151,8,3, Pink);
		if(pos==3){
			LCD_DrawRectangle (123,130,5,10, Pink);
		  LCD_DrawRectangle (123,135,5,1, Black);
			}
		if(pos==1) LCD_DrawRectangle (128,151,8,3, Pink2);
		
		if(cuddle==1){
				heart(-90,-5,5/3,1,Red2);
	      heart(74,40,2,1,Red3);
	      heart(10,10,5/3,1,Red3);
			  cuddle++;
		}
		else if(cuddle==2){
			  heart(-90,-5,5/3,1,Red3);
	      heart(74,40,2,1,Red2);
	      heart(10,10,5/3,1,Red2);
			  cuddle++;
		}
		else if(cuddle==3)
		{cuddle=0;
		 heart(-90,-5,5/3,1,Black);
	   heart(74,40,2,1,Black);
	   heart(10,10,5/3,1,Black);
		 if(Index2<5) Index2++;
		battery_updates(Index2,1,2);}
			
			
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}


void TIMER2_IRQHandler (void)
{	
	disable_timer(0);
	
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}


void TIMER3_IRQHandler (void)
{	
	if(isReseted){
	/*conclusione partita: il tamagotchi lascia lo schermo alternando due posizioni*/
	if(pos2==0){tamagotchi3(add,50,1); pos2++;}
	else if(pos2==1){tamagotchi3(add,50,0); pos2++;add=add+15;}
	else if(pos2==2){tamagotchi1(add,80,1); pos2++;}
	else if(pos2==3){tamagotchi1(add,80,0); pos2=0;add=add+15;}
	
	if(add==155){
		reset_timer(3);
    disable_timer(3);
		pos2=0, add=80;
		disable_timer(1);
		GUI_Text(85,150,(uint8_t *)"GAME OVER",Black,Yellow);
		
	LCD_DrawRectangle(110,226,10,16,Black);LCD_DrawRectangle(120,224,5,20,Black);
	LCD_DrawRectangle(125,222,5,24,Black);LCD_DrawRectangle(130,220,5,28,Black);
	LCD_DrawRectangle(105,244,4,4,Black);LCD_DrawRectangle(109,240,4,4,Black);
  LCD_DrawRectangle(115,236,4,4,Black);LCD_DrawRectangle(119,232,4,4,Black);
	LCD_DrawRectangle(123,228,4,4,Black);LCD_DrawRectangle(127,224,4,4,Black);
	LCD_DrawRectangle(131,220,4,4,Black);LCD_DrawRectangle(135,216,4,4,Black);
		
		GUI_Text(50,267, (uint8_t *) "MEAL" ,Black,Black); GUI_Text(157,267, (uint8_t *) "SNACK" ,Black,Black);
		LCD_DrawRectangle (20,260,90,2, Black);LCD_DrawRectangle (130,260,90,2, Black);
   	LCD_DrawRectangle (20,260,2,30, Yellow);LCD_DrawRectangle (130,260,2,30, Yellow);
	  LCD_DrawRectangle (110,260,2,30, Black);LCD_DrawRectangle (130,260,2,30, Black);
	  LCD_DrawRectangle (20,290,90,2, Yellow);LCD_DrawRectangle (130,290,90,2, Yellow);
		
		LCD_DrawRectangle (20,260,200,2, Yellow);LCD_DrawRectangle (20,290,200,2, Yellow);
		GUI_Text(100,267,(uint8_t *)"RESET",Yellow,Black);
		enable_RIT();
		fine=0; Index1=5; Index2=5;}
	}
	
	if(isEating){
	/*il tamagotchi si sposta verso il centro dello schermo per avvicinarsi al cibo*/
	if(pos2==0){tamagotchi2(add2-80,100,1); pos2++;
	     if(add2==130){LCD_DrawRectangle(135,165,25,25,Black);} /*raggiunta la posizione desiderata,*/
			 }																										/*il cibo viene mangiato e quindi scompare dallo schermo*/
	else if(pos2==1){tamagotchi2(add2-80,100,0); pos2=0;add2=add2+15;}
	
	if(add2==145){
		reset_timer(3);
		disable_timer(3);
		isEating=0;
			if(type==2){
				if(Index2<5) Index2++; //aumenta l'indice se e solamente se lo stato del tamagotchi non ha le tacche al completo 
			  battery_updates(Index2,1,2);
			  LCD_DrawRectangle(132,262,88,28,Black);
			  GUI_Text(157,267, (uint8_t *) "SNACK" ,Blue2,Black);}
			else if(type==1){
			 if(Index1<5) Index1++;
			 battery_updates(Index1,1,1);
			 LCD_DrawRectangle(22,262,88,28,Black);
			 GUI_Text(50,267, (uint8_t *) "MEAL" ,Blue2,Black);}
		type=0;
		tamagotchi1(60,80,1);
   	pos2=0, add2=100;
	  enable_timer(1);
	  enable_RIT();}
	}

  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
