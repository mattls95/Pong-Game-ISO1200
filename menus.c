#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

void display_menu(void){
    display_init();

    display_string(0, "PONG!");
    display_update();

    quicksleep(10000000);

	display_string(0, "Main Menu");
	display_string(1, "1. Game modes");
	display_string(2, "2. High Scores");
    display_update();
}