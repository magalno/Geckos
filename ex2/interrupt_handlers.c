#include <stdint.h>
#include <stdbool.h>

#include "tunes.h"
#include "efm32gg.h"
#include "interrupt_handlers.h"


volatile uint32_t counter_val = 0;
volatile uint32_t sound0 = 100;
volatile uint32_t sound1 = 0;
volatile uint32_t first = 1;
Song* imperial_march;

/* TIMER1 interrupt handler */
void __attribute__ ((interrupt)) TIMER1_IRQHandler() 
{  
  /*
    TODO feed new samples to the DAC
    remember to clear the pending interrupt by writing 1 to TIMER1_IFC
  */  
	//Clear the overflow interrupt flag
	*TIMER1_IFC |= TIMER1_IFC_OF;

	counter_val++;
	*GPIO_PA_DOUT = counter_val;

	*DAC0_CH0DATA = sound0;
	*DAC0_CH1DATA = sound0;

	*TIMER1_TOP = 20000;
}

/* LETIMER0 interrupt handler */
void __attribute__ ((interrupt)) LETIMER0_IRQHandler() 
{  
  /*
    TODO feed new samples to the DAC
  */  
    if(first) {
      char* letters = "gggebgebg";
      int times[9] = {500,500,500,500,200,500,500,200,500};
      int length = 9;
      int octave = 3;
      
      construct_song(letters, times, imperial_march, length, octave);
        first = 0;
    }
    if(*LETIMER0_IF && 0b01000){
        *LETIMER0_IFC |= LETIMER0_IFC_REP0;
        playCurrentAndSetNextTune(imperial_march);
    }
	//Clear the overflow interrupt flag
	*LETIMER0_IFC |= LETIMER0_IFC_COMP0;

	counter_val++;
	*GPIO_PA_DOUT = counter_val;

    *DAC0_CH0DATA = sound0;
    *DAC0_CH1DATA = sound0;

    int rem = counter_val % 2;
    if (rem == 1) {
        *DAC0_CH0DATA = sound0;
    }
    else {
        *DAC0_CH0DATA = -sound0;
    }


	//*LETIMER0_COMP0 = 5;
}

/* GPIO even pin interrupt handler */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler() 
{
    /* TODO handle button pressed event, remember to clear pending interrupt */
	gpio_handler();
}

/* GPIO odd pin interrupt handler */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler() 
{
    /* TODO handle button pressed event, remember to clear pending interrupt */
	gpio_handler();
}

void gpio_handler(void)
{

    sound0 += 50;
    //Reset GPIO interupts
    *GPIO_IFC = 0xff;

    //Enables coresponding led on button press
    uint32_t input = *GPIO_PC_DIN;
    input = input << 8;

    *GPIO_PA_DOUT = input;
}
