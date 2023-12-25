#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"

//modifica delle tacche delle batterie associate ai due stati di "felicità" e "sazietà"

/*		SIGNIFICATO PARAMETRI: index-> posizione ultima tacca
														 verse-> 1:aumento di una tacca; -1:diminuizione di una tacca
														 bar-> 1:aumento/diminuzione tacca associata alla stato "sazietà"
																	 2:aumento/diminuzione tacca associata alla stato "felicità"
																	 3:aumento/diminuzione simultaneo di entrambe le tacche;
*/
void battery_updates(int index, int verse, int bar){

	int x=20, y=140;
	
	if(index<0 || index>5){ return;}
		
	x=x+12*index;
	y=y+12*index;
		
	if(verse==1) {
  if(bar==2 || bar==3) LCD_DrawRectangle (x,58,10,15, Red);
	if(bar==1 || bar==3) LCD_DrawRectangle (y,58,10,15, Red);}
	else{
	if(bar==2 || bar==3) LCD_DrawRectangle (x,58,10,15, Blue2);
	if(bar==1 || bar==3) LCD_DrawRectangle (y,58,10,15, Blue2);
}

	return;
}
