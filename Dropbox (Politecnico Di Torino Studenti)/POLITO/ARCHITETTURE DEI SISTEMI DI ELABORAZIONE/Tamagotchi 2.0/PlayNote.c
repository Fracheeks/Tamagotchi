#include "timer/timer.h"
#include "lpc17xx.h"

int isNotePlaying(void)
{
	return ((LPC_TIM0->TCR != 0) || (LPC_TIM2->TCR != 0));
}

void PlayNote(int frequency, int duration){
	if(frequency != 0)
	{
		reset_timer(0);
		init_timer(0, frequency);
		enable_timer(0);
	}

	reset_timer(2);
	init_timer(2, duration);
	enable_timer(2);
}