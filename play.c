#include <stdio.h>
#include <math.h>
#include <stdint.h>

void pulse(int f, int t_ms){
	int t=t_ms*8;
	for(int i=0; i<t; i++){
		uint8_t c = i*f*256/8000;
		putchar(c/6);
	}
}

typedef struct note{
	uint8_t p;
   	uint16_t dur;
	uint16_t wait;
} note;

note notes[]={
#include "mus.inc"
};

int main(){
	while(1){
		for(unsigned i=0; i<sizeof(notes)/sizeof(note); i++){
			pulse(440 * pow(1.05946, notes[i].p - 69), notes[i].dur);
			pulse(0, notes[i].wait);
		}
		pulse(0, 3000);
	}
}
