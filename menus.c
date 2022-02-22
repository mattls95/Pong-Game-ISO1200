#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
int btns;
int menu_cursor = 0;


void labinit( void )
{
  volatile uint8_t* trise = (volatile uint8_t*) 0xbf886100; // Initialize trise needs to be volatile to stop compiler from optimizing
  *trise &= ~ 0xff; // Set bits 0 - 7 to 0 which means that they are set up for output
  TRISD |= 0xfe0; //Set up bits 11 - 5 to 1 which means that they are set up for input
  //TRISDSET = 0xfe0;
  return;
}

void display_menu(void){
    display_init();

    display_string(0, "     PONG!    ");
    display_update();

    quicksleep(10000000);

    for(;;) {
	display_string(0, "   Main Menu   ");

    while (!menu_cursor) {
        display_string(1, " > 1. Game modes");
	    display_string(2, "   2. High Scores");
        display_update();

        if(getbtn4()){
            menu_cursor = 1;
            quicksleep(1000000);

        }
    }

    while (menu_cursor) {
        display_string(1, "   1. Game modes");
	    display_string(2, " > 2. High Scores");
        display_update();

        if(getbtn4()){
            menu_cursor = 0;
            quicksleep(1000000);
        }
    }
	
    }
}