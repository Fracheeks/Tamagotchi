#include "GLCD/GLCD.h" 

//posizione assunta dal tamagotchi durante l'assunzione di un pasto

void tamagotchi2(int x,int y,int pos){ 
	
if(!pos){
	LCD_DrawRectangle (48+x,41+y,23,5, Black);
	LCD_DrawRectangle (43+x,46+y,40,4, Black);
	LCD_DrawRectangle (83+x,60+y,5,5, Black);
	LCD_DrawRectangle (43+x,55+y,40,10, Black);
	LCD_DrawRectangle (48+x,50+y,25,5, Black);
	LCD_DrawRectangle (48+x,55+y,30,20, Black);
	LCD_DrawRectangle (68+x,60+y,5,5, Black);
	LCD_DrawRectangle (63+x,65+y,20,5, Black);
	LCD_DrawRectangle (63+x,50+y,5,10, Black);
	LCD_DrawRectangle (78+x,70+y,6,1, Black);
	LCD_DrawRectangle (83+x,65+y,1,5, Black);
	LCD_DrawRectangle (43+x,50+y,15,5, Black);
	LCD_DrawRectangle (48+x,50+y,5,15, Black);
	LCD_DrawRectangle (38+x,55+y,5,15, Black);
	LCD_DrawRectangle (43+x,65+y,5,5, Black);}
if(pos){  
	LCD_DrawRectangle (48+x,41+y,23,5, Red);
	LCD_DrawRectangle (43+x,46+y,40,4, Red);
	LCD_DrawRectangle (83+x,60+y,5,5, Pink);
	LCD_DrawRectangle (43+x,55+y,40,10, Pink);
	LCD_DrawRectangle (48+x,50+y,25,5, Pink);
	LCD_DrawRectangle (48+x,55+y,30,20, Pink);
	LCD_DrawRectangle (68+x,60+y,5,5, Black);
	LCD_DrawRectangle (63+x,65+y,20,5, Black);
	LCD_DrawRectangle (63+x,50+y,5,10, Black);
	LCD_DrawRectangle (78+x,70+y,6,1, White);
	LCD_DrawRectangle (83+x,65+y,1,5, White);
	LCD_DrawRectangle (68+x,71+y,8,3, Pink2);
	LCD_DrawRectangle (43+x,50+y,15,5, Marron);
	LCD_DrawRectangle (48+x,50+y,5,15, Marron);
	LCD_DrawRectangle (38+x,55+y,5,15, Marron);
	LCD_DrawRectangle (43+x,65+y,5,5, Marron);}
}