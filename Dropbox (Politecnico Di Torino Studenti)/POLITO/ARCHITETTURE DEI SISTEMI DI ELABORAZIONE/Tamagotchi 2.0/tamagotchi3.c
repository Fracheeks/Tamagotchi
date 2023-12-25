#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"

//posizione assunta dal tamagotchi a gioco concluso

void tamagotchi3(int x,int y, int pos){
	
if(pos){
	LCD_DrawRectangle (78+x,40+y,15,10, Pink);LCD_DrawRectangle (78+x,50+y,15,15, Red);
	LCD_DrawRectangle (78+x,65+y,10,10, Red);LCD_DrawRectangle (48+x,41+y,23,5, Red);
	LCD_DrawRectangle (43+x,46+y,40,4, Red);LCD_DrawRectangle (83+x,60+y,5,5, Pink);
	LCD_DrawRectangle (43+x,55+y,40,10, Pink);LCD_DrawRectangle (48+x,50+y,25,5, Pink);
	LCD_DrawRectangle (48+x,55+y,30,20, Pink);LCD_DrawRectangle (68+x,60+y,5,5, Black);
	LCD_DrawRectangle (63+x,65+y,20,5, Black);LCD_DrawRectangle (63+x,50+y,5,10, Black);
	LCD_DrawRectangle (78+x,70+y,6,1, White);LCD_DrawRectangle (83+x,65+y,1,5, White);
	LCD_DrawRectangle (43+x,50+y,15,5, Marron);LCD_DrawRectangle (48+x,50+y,5,15, Marron);
	LCD_DrawRectangle (38+x,55+y,5,15, Marron);LCD_DrawRectangle (43+x,65+y,5,5, Marron);
	LCD_DrawRectangle (43+x,55+y,5,10, Pink);LCD_DrawRectangle (48+x,85+y,40,15, Blue);
	LCD_DrawRectangle (48+x,100+y,25,5, Blue);LCD_DrawRectangle (33+x,75+y,50,10, Red);
	LCD_DrawRectangle (43+x,85+y,15,5, Red);LCD_DrawRectangle (78+x,80+y,5,5, Black);
	LCD_DrawRectangle (18+x,75+y,15,10, Pink);LCD_DrawRectangle (23+x,85+y,5,5, Pink);
	LCD_DrawRectangle (38+x,100+y,10,10, Marron);LCD_DrawRectangle (33+x,105+y,10,10, Marron);
	LCD_DrawRectangle (88+x,80+y,5,20, Marron);LCD_DrawRectangle (93+x,75+y,5,25, Marron);
	LCD_DrawRectangle (78+x,50+y,5,1, White);LCD_DrawRectangle (63+x,90+y,5,5, Yellow);
	LCD_DrawRectangle (73+x,85+y,5,5, Yellow);LCD_DrawRectangle (73+x,80+y,5,5, Blue);
	LCD_DrawRectangle (68+x,75+y,5,5, Blue);LCD_DrawRectangle (58+x,80+y,5,5, Blue);
	LCD_DrawRectangle (53+x,75+y,5,5, Blue);}
if(!pos){
	LCD_DrawRectangle (78+x,40+y,15,10, Black);LCD_DrawRectangle (78+x,50+y,15,15, Black);
	LCD_DrawRectangle (78+x,65+y,10,10, Black);LCD_DrawRectangle (48+x,41+y,23,5, Black);
	LCD_DrawRectangle (43+x,46+y,40,4, Black);LCD_DrawRectangle (83+x,60+y,5,5, Black);
	LCD_DrawRectangle (43+x,55+y,40,10, Black);LCD_DrawRectangle (48+x,50+y,25,5, Black);
	LCD_DrawRectangle (48+x,55+y,30,20, Black);LCD_DrawRectangle (68+x,60+y,5,5, Black);
	LCD_DrawRectangle (63+x,65+y,20,5, Black);LCD_DrawRectangle (63+x,50+y,5,10, Black);
	LCD_DrawRectangle (78+x,70+y,6,1, Black);LCD_DrawRectangle (83+x,65+y,1,5, Black);
	LCD_DrawRectangle (43+x,50+y,15,5, Black);LCD_DrawRectangle (48+x,50+y,5,15, Black);
	LCD_DrawRectangle (38+x,55+y,5,15, Black);LCD_DrawRectangle (43+x,65+y,5,5, Black);
	LCD_DrawRectangle (43+x,55+y,5,10, Black);LCD_DrawRectangle (48+x,85+y,40,15, Black);
	LCD_DrawRectangle (48+x,100+y,25,5, Black);LCD_DrawRectangle (33+x,75+y,50,10, Black);
	LCD_DrawRectangle (43+x,85+y,15,5, Black);LCD_DrawRectangle (78+x,80+y,5,5, Black);
	LCD_DrawRectangle (18+x,75+y,15,10, Black);LCD_DrawRectangle (23+x,85+y,5,5, Black);
	LCD_DrawRectangle (38+x,100+y,10,10, Black);LCD_DrawRectangle (33+x,105+y,10,10, Black);
	LCD_DrawRectangle (88+x,80+y,5,20, Black);LCD_DrawRectangle (93+x,75+y,5,25, Black);
	LCD_DrawRectangle (78+x,50+y,5,1, Black);LCD_DrawRectangle (63+x,90+y,5,5, Black);
	LCD_DrawRectangle (73+x,85+y,5,5, Black);LCD_DrawRectangle (73+x,80+y,5,5, Black);
	LCD_DrawRectangle (68+x,75+y,5,5, Black);LCD_DrawRectangle (58+x,80+y,5,5, Black);
	LCD_DrawRectangle (53+x,75+y,5,5, Black);}
	
}