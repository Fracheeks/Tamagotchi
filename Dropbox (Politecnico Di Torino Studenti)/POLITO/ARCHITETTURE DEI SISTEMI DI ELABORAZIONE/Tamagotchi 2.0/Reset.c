#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "timer/timer.h"
#include "joystick/joystick.h"
#include "RIT/rit.h"

void battery_updates(int index, int verse, int bar);
void tamagotchi1(int x,int y, int pos);
extern int hours, minutes,seconds;
extern int isReseted;

void reset(){
	
	LCD_Clear(Black);
	tamagotchi1(60,80,1);
	isReseted=0;
	LCD_DrawRectangle (15,55,83,20, Blue2);LCD_DrawRectangle (135,55,83,20, Blue2);
  LCD_DrawRectangle (98,60,5,10, Blue2);LCD_DrawRectangle (218,60,5,10, Blue2);
	
	battery_updates(0,1,3);battery_updates(1,1,3); battery_updates(2,1,3);
	battery_updates(3,1,3);battery_updates(4,1,3);battery_updates(5,1,3);
	
	GUI_Text(20,35, (uint8_t *) "Happiness" ,Red,Black);GUI_Text(148,35, (uint8_t *) "Satiety" ,Red,Black);
	
	LCD_DrawRectangle (20,260,90,2, Yellow);LCD_DrawRectangle (130,260,90,2, Yellow);
	LCD_DrawRectangle (20,260,2,30, Yellow);LCD_DrawRectangle (130,260,2,30, Yellow);
	LCD_DrawRectangle (110,260,2,30, Yellow);LCD_DrawRectangle (220,260,2,30, Yellow);
	LCD_DrawRectangle (20,290,90,2, Yellow);LCD_DrawRectangle (130,290,90,2, Yellow);
	
	GUI_Text(50,267, (uint8_t *) "MEAL" ,Blue2,Black); GUI_Text(157,267, (uint8_t *) "SNACK" ,Blue2,Black);
	
	LCD_DrawRectangle(110,226,10,16,Yellow);LCD_DrawRectangle(120,224,5,20,Yellow);
	LCD_DrawRectangle(125,222,5,24,Yellow);LCD_DrawRectangle(130,220,5,28,Yellow);
	LCD_DrawRectangle(105,244,4,4,Red);LCD_DrawRectangle(109,240,4,4,Red);
  LCD_DrawRectangle(115,236,4,4,Red);LCD_DrawRectangle(119,232,4,4,Red);
	LCD_DrawRectangle(123,228,4,4,Red);LCD_DrawRectangle(127,224,4,4,Red);
	LCD_DrawRectangle(131,220,4,4,Red);LCD_DrawRectangle(135,216,4,4,Red);
	
	hours=0; minutes=0; seconds=-1; isReseted=0;
	enable_timer(1);
	enable_RIT();
	
}