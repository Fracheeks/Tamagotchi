#include "GLCD/GLCD.h" 

//posizione base assunta dal tamagotchi in attesa

void tamagotchi1(int x, int y, int pos){ //pos->  1:comparasa tamagotchi   -1:scomparsa tamagotchi
	
if(pos){
	LCD_DrawRectangle (48+x,41+y,23,5, Red);LCD_DrawRectangle (43+x,46+y,40,4, Red);
	LCD_DrawRectangle (83+x,60+y,5,5, Pink);LCD_DrawRectangle (43+x,55+y,40,10, Pink);
	LCD_DrawRectangle (48+x,50+y,25,5, Pink);LCD_DrawRectangle (48+x,55+y,30,20, Pink);
	LCD_DrawRectangle (68+x,60+y,5,5, Black);LCD_DrawRectangle (63+x,65+y,20,5, Black);
	LCD_DrawRectangle (63+x,50+y,5,10, Black);
  LCD_DrawRectangle (78+x,70+y,6,1, White);LCD_DrawRectangle (83+x,65+y,1,5, White);
	LCD_DrawRectangle (43+x,50+y,15,5, Marron);LCD_DrawRectangle (48+x,50+y,5,15, Marron);
	LCD_DrawRectangle (38+x,55+y,5,15, Marron);LCD_DrawRectangle (43+x,65+y,5,5, Marron);
	LCD_DrawRectangle (80+x,85+y,5,5, Red);	LCD_DrawRectangle (70+x,90+y,5,5, Red);
	LCD_DrawRectangle (70+x,90+y,15,15, Pink);LCD_DrawRectangle (37+x,90+y,15,14, Pink);
	LCD_DrawRectangle (68+x,80+y,13,10, Red);LCD_DrawRectangle (37+x,85+y,5,5, Red);
	LCD_DrawRectangle (40+x,80+y,5,10, Red);LCD_DrawRectangle (45+x,75+y,23,20, Red);
	LCD_DrawRectangle (63+x,80+y,5,5, Blue);LCD_DrawRectangle (53+x,75+y,5,10, Blue);
	LCD_DrawRectangle (53+x,85+y,15,5, Blue);LCD_DrawRectangle (50+x,90+y,20,10, Blue);
	LCD_DrawRectangle (53+x,90+y,5,5, Yellow);LCD_DrawRectangle (63+x,90+y,5,5, Yellow);
	LCD_DrawRectangle (45+x,100+y,30,10, Blue);LCD_DrawRectangle (56+x,105+y,8,5, Black);
	LCD_DrawRectangle (64+x,115+y,21,5, Marron);LCD_DrawRectangle (64+x,110+y,16,5, Marron);
	LCD_DrawRectangle (35+x,115+y,21,5, Marron);LCD_DrawRectangle (40+x,110+y,16,5, Marron);
}
else if(!pos){
	LCD_DrawRectangle (48+x,41+y,23,5, Black);LCD_DrawRectangle (43+x,46+y,40,4, Black);
	LCD_DrawRectangle (83+x,60+y,5,5, Black);LCD_DrawRectangle (43+x,55+y,40,10, Black);
	LCD_DrawRectangle (48+x,50+y,25,5, Black);LCD_DrawRectangle (48+x,55+y,30,20, Black);
	LCD_DrawRectangle (68+x,60+y,5,5, Black);LCD_DrawRectangle (63+x,65+y,20,5, Black);
	LCD_DrawRectangle (63+x,50+y,5,10, Black);
  LCD_DrawRectangle (78+x,70+y,6,1, Black);LCD_DrawRectangle (83+x,65+y,1,5, Black);
	LCD_DrawRectangle (43+x,50+y,15,5, Black);LCD_DrawRectangle (48+x,50+y,5,15, Black);
	LCD_DrawRectangle (38+x,55+y,5,15, Black);LCD_DrawRectangle (43+x,65+y,5,5, Black);
	LCD_DrawRectangle (80+x,85+y,5,5, Black);	LCD_DrawRectangle (70+x,90+y,5,5, Black);
	LCD_DrawRectangle (70+x,90+y,15,15, Black);LCD_DrawRectangle (37+x,90+y,15,14, Black);
	LCD_DrawRectangle (68+x,80+y,13,10, Black);LCD_DrawRectangle (37+x,85+y,5,5, Black);
	LCD_DrawRectangle (40+x,80+y,5,10, Black);LCD_DrawRectangle (45+x,75+y,23,20, Black);
	LCD_DrawRectangle (63+x,80+y,5,5, Black);LCD_DrawRectangle (53+x,75+y,5,10, Black);
	LCD_DrawRectangle (53+x,85+y,15,5, Black);LCD_DrawRectangle (50+x,90+y,20,10, Black);
	LCD_DrawRectangle (53+x,90+y,5,5, Black);LCD_DrawRectangle (63+x,90+y,5,5, Black);
	LCD_DrawRectangle (45+x,100+y,30,10, Black);LCD_DrawRectangle (56+x,105+y,8,5, Black);
	LCD_DrawRectangle (64+x,115+y,21,5, Black);LCD_DrawRectangle (64+x,110+y,16,5, Black);
	LCD_DrawRectangle (35+x,115+y,21,5, Black);LCD_DrawRectangle (40+x,110+y,16,5, Black);
}

}

	