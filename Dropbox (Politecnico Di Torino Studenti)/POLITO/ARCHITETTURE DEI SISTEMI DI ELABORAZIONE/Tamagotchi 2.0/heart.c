#include "GLCD/GLCD.h" 

//cuore
/* x : traslazione lungo asse x , y: traslazione lungo asse y
	 d : dimensione , pos : (1) comparsa / (-1) scomparsa 
	 color : colore figura
*/

void heart(int x, int y, int d, int pos, int color){

	if(pos){
LCD_DrawRectangle(168/d+x,141/d+y,10/d,4/d,color);
LCD_DrawRectangle(154/d+x,141/d+y,10/d,4/d,color);
LCD_DrawRectangle(150/d+x,145/d+y,32/d,6/d,color);
LCD_DrawRectangle(150/d+x,151/d+y,32/d,6/d,color);
LCD_DrawRectangle(156/d+x,155/d+y,20/d,6/d,color);
LCD_DrawRectangle(160/d+x,160/d+y,12/d,4/d,color);
LCD_DrawRectangle(162/d+x,163/d+y,8/d,4/d,color);}
	
	
   else if(!pos){
LCD_DrawRectangle(168/d+x,141/d+y,10/d,4/d,Black);
LCD_DrawRectangle(154/d+x,141/d+y,10/d,4/d,Black);
LCD_DrawRectangle(150/d+x,145/d+y,32/d,6/d,Black);
LCD_DrawRectangle(150/d+x,151/d+y,32/d,6/d,Black);
LCD_DrawRectangle(156/d+x,155/d+y,20/d,6/d,Black);
LCD_DrawRectangle(160/d+x,160/d+y,12/d,4/d,Black);
LCD_DrawRectangle(162/d+x,163/d+y,8/d,4/d,Black);}

}