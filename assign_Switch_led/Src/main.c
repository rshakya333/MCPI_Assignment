

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "switch_intr.h"
#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
Orange LED will blink when switch is pressed -- Any Optimization Level
As flag is declared volatile.
*/

int main(void) {
	SystemInit();
	SwitchInit();
	LedInit(LED_ORANGE_PIN);

	while(1) {
		// if switch is pressed blink orange led
		while(SwitchExtiFlag == 0)
			;
		/*// Optimization Level -- any
			LDR r7, =SwitchExtiFlag 	// r7 = &SwitchExtiFlag;
		loop:
			LDR r0, [r7]				// r0 = *r7;
			CMP r0, #0					// r0 == 0 (compare)
			BEQ loop					// if 0, repeat loop
		*/
		LedInit(LED_RED_PIN);
		LedInit(LED_BLUE_PIN);
		LedInit(LED_GREEN_PIN);



		LedBlink(LED_ORANGE_PIN, 1000);
		LedBlink(LED_RED_PIN,1000);
		LedBlink(LED_RED_PIN,1000);
		LedBlink(LED_GREEN_PIN,1000);


		SwitchExtiFlag = 0;
	}
	return 0;
}
























