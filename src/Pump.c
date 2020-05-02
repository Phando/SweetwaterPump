#include "rui.h"
#include "board.h"
#include "bsp.h"

//#define PUMP_PIN	5  // PA_8 - 5.0v
#define PUMP_PIN	15 // PB_3 - 3.3v

RUI_GPIO_ST pump;
bool pumpState = false;

void pumpInit(void)
{	
    pumpState = false;
    pump.pin_num = PUMP_PIN;
    pump.dir = RUI_GPIO_PIN_DIR_OUTPUT;
    pump.pull = RUI_GPIO_PIN_NOPULL;
    rui_gpio_init(&pump);

    pumpStart();
    rui_delay_ms(1000);
    pumpStop();
}

void pumpStart(void){
	pumpState = true;
	rui_gpio_rw(RUI_IF_WRITE,&pump,high);
}

void pumpStop(void){
	pumpState = false;
    rui_gpio_rw(RUI_IF_WRITE,&pump,low);
}

unsigned char getPumpState()
{
	RUI_LOG_PRINTF("\r\nPump: %s\r\n",pumpState ? "running":"idle");
	return pumpState ? 0xFF : 0x00;
}