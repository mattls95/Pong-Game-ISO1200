/*
********************************************************************************
* name    :  menu.c
* authors :  Mattias Lindgren, 2022-02-xx
* brief   :  Contains the code needed to navigate the menu hierarchy
********************************************************************************
*/

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
int menu_cursor = 0; // Represents where the cursor is placed 

void display_game_mode_menu(void);
void display_highscore_menu(void);

void labinit( void )
{
  //volatile uint8_t* trise = (volatile uint8_t*) 0xbf886100; // Initialize trise needs to be volatile to stop compiler from optimizing
  //*trise &= ~ 0xff; // Set bits 0 - 7 to 0 which means that they are set up for output
  //TRISDSET = 0xfe0; //Set up bits 11 - 5 to 1 which means that they are set up for input
  return;
}

void display_main_menu(void){

    for(;;) {
	display_string(0, "   Main Menu   ");

    while (!menu_cursor) {
        display_string(1, "> 1. Game modes");
	    display_string(2, "  2. High Scores");
        display_update();

        if(getbtn4()){ //If button 4 is pushed move cursor to next line
            menu_cursor = 1;
            quicksleep(1000000); // delay to avoid instantly returning to 1
        }

        else if(getbtn3()) { // Move to game mode menu if button 3 is pushed
            menu_cursor = 0;
            quicksleep(1000000);
            clear_display();
            display_game_mode_menu();
        }
            
    }

    while (menu_cursor) {
        display_string(1, "  1. Game modes");
	    display_string(2, "> 2. High Scores");
        display_update();

        if(getbtn4()){ 
            menu_cursor = 0;
            quicksleep(1000000);
        }

        else if(getbtn3()) {
            menu_cursor = 0;
            quicksleep(1000000);
            clear_display();
            display_highscore_menu();
        }
            
    }
	
    }

}

void display_game_mode_menu(void){
        display_string(0, "   Game Modes   ");
    for(;;){
        while(!menu_cursor){
            display_string(1, "> 1. AI mode");
	        display_string(2, "  2. Two player mode");
            display_string(3, "  3. Main menu");
            display_update();

            if(getbtn4()){
                menu_cursor = 1;
                quicksleep(1000000);
            }

           else if(getbtn3()){
                menu_cursor = 0;
                quicksleep(1000000);
            }

        }

        while(menu_cursor){
            display_string(1, "  1. AI mode");
	        display_string(2, "> 2. Two player mode");
            display_string(3, "  3. Main menu");
            display_update();

            if(getbtn4()){
                menu_cursor = 1;
                quicksleep(1000000);
                break;
            }

            else if(getbtn3()){
                menu_cursor = 0;
            }
        }

        while((menu_cursor)){
            display_string(1, "  1. AI mode");
	        display_string(2, "  2. Two player mode");
            display_string(3, "> 3. Main menu");
            display_update();

            if(getbtn4()){
                menu_cursor = 0;
                quicksleep(1000000);
            }

            if(getbtn3()){
                menu_cursor = 0;
                quicksleep(1000000);
                clear_display();
                display_main_menu();
            }
        }
        
    }
}

void display_highscore_menu(void){            
    display_string(0 ,"   HIGH SCORES   ");
    for(;;){
        while(!menu_cursor){
            display_string(1, "  1. ");
            display_string(2, "  2. ");
            display_string(3, "> Main menu");
            display_update();

            if(getbtn3()){
                menu_cursor = 0;
                quicksleep(1000000);
                clear_display();
                display_main_menu();
            }
        }
    }
}