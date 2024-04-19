// Lab13.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// edX Lab 13 
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys

#include "..//tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
																		
// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long msec);

int main(void){
	// Real Lab13 
	// for the real board grader to work 
	// you must connect PD3 to your DAC output
  TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); // activate grader and set system clock to 80 MHz
// PortE used for piano keys, PortB used for DAC        
  Sound_Init(); // initialize SysTick timer and DAC
  Piano_Init();
  EnableInterrupts();  // enable after all initialization are done

  while(1){      
		
// input from keys to select tone
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed

switch (Piano_In()){
		case 0x01:
			Sound_Tone(9556); // C generates a sinusoidal DACOUT at 523.251 Hz	/16 (total number of indexes)
			break;
		case 0x02:
			Sound_Tone(8513); // D generates a sinusoidal DACOUT at 587.330 Hz	/16
			break;
		case 0x04:
			Sound_Tone(7584); // E generates a sinusoidal DACOUT at 659.255 Hz	/16
			break;
		case 0x08:
			Sound_Tone(6378); // G generates a sinusoidal DACOUT at 783.991 Hz	/16
			break;
		default:
			Sound_Off(); // OFF
	}
  }
            
}

// Inputs: Number of msec to delay
// Outputs: None
void delay(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}


