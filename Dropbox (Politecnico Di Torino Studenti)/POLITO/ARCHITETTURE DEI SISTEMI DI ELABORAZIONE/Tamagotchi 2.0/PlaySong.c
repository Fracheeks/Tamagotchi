/* k=1/f'*f/n  k=f/(f'*n) k=25MHz/(f'*45) */

//const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
/* 
131Hz		k=4240 C3
147Hz		k=3779 
165Hz		k=3367
175Hz		k=3175
196Hz		k=2834		
220Hz		k=2525
247Hz		k=2249
262Hz		k=2120 C4
*/

const int song[10]={4240,3779,3367,3367,3367,4240,3367,2834,0,2834};
const int duration[10]={0x004C4B40/2,0x004C4B40,0x004C4B40/2,0x004C4B40/2,0x004C4B40,0x004C4B40/2,0x004C4B40/2,0x004C4B40,0x004C4B40/2,0x004C4B40/2};

int isNotePlaying(void);
void PlayNote(int frequency,int duration);
	
void PlaySong(int firstNote, int lastNote){
	
	int i;
	for(i= firstNote; i<lastNote;i++){
		while(isNotePlaying());
		PlayNote(song[i], duration[i]);
	}
return;
}
