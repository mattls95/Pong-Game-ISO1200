/*
********************************************************************************
* name    :  main.c
* authors :  Mattias Lindgren, 2022-02-xx
*            Original code by Fredrik Lundeval and Axel Isaksson, 2015
* brief   :  Contains driver for interfacing with and initialize the chipkit
*            uno32 basic i/o shield oled display.
********************************************************************************
*/

#include <pic32mx.h>
#include "images.h"

int main() {
	/*
	This will set the peripheral bus clock to the same frequency
	as the sysclock. That means 80 MHz, when the microcontroller
	is running at 80 MHz. Changed 2017, as recommended by Axel.
	*/
	SYSKEY = 0xAA996655;  /* Unlock OSCCON, step 1 */
	SYSKEY = 0x556699AA;  /* Unlock OSCCON, step 2 */
	while(OSCCON & (1 << 21)); /* Wait until PBDIV ready */
	OSCCONCLR = 0x180000; /* clear PBDIV bit <0,1> */
	while(OSCCON & (1 << 21));  /* Wait until PBDIV ready */
	SYSKEY = 0x0;  /* Lock OSCCON */
	
	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;
	
	/* Set up input pins */
	//TRISDSET = (1 << 8);
	//TRISFSET = (1 << 1);
	
	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	/* SPI2STAT bit SPIROV = 0; */
	SPI2STATCLR = 0x40;
	/* SPI2CON bit CKP = 1; */
    SPI2CONSET = 0x40;
	/* SPI2CON bit MSTEN = 1; */
	SPI2CONSET = 0x20;
	/* SPI2CON bit ON = 1; */
	SPI2CONSET = 0x8000;

    display_init();
	uint8_t x = 32;
	uint8_t y = 128;

	clear_display();
	light_up_pixel(x,y);
	//display_string(0, "     PONG!    ");
    //display_update();
	//quicksleep(10000000);
	//display_main_menu();
	return 0;
}
