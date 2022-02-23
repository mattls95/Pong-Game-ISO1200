/*
********************************************************************************
* name    :  pong.c
* authors :  Mattias Lindgren, 2022-02-xx
* brief   :  Contains the code for the game logic for pong
********************************************************************************
*/

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

// display = a matrix for the pixel dimensions is 32 pixels in height (y) and 128 pixels in width (x)
uint8_t display[32][128];
// oled_display = a matrix that can be interpreted by the hardware
uint8_t oled_display[512];

/* This array is the off-screen frame buffer used for rendering.
** It isn't possible to read back from the OLED display device,
** so display data is rendered into this off-screen buffer and then
** copied to the display.
*/
char rgbOledBmp[512];

void light_up_pixel(uint8_t x, uint8_t y){
    return;
}