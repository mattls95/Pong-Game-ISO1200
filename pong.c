/*
********************************************************************************
* name    :  pong.c
* authors :  Modified by Mattias Lindgren, 2022-02-xx
             Orignal code dy Digilent corp   
* brief   :  Contains the code for the game logic for pong
********************************************************************************
*/
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

/* ------------------------------------------------------------ */
/* Pin definitions for access to OLED control signals on chipKIT Uno32
*/
#define prtVddCtrl PORTF
#define prtVbatCtrl PORTF
#define prtDataCmd PORTF
#define prtReset PORTG

#define DISPLAY_CHANGE_TO_COMMAND_MODE (PORTFCLR = 0x10)
#define DISPLAY_CHANGE_TO_DATA_MODE (PORTFSET = 0x10)
#define bitVddCtrl 1 << 5   // bit 6
#define bitVbatCtrl 1 << 4 // bit 5
#define bitDataCmd 1 << 3  // bit 4
#define bitReset 1 << 8    // bit 9
/* ------------------------------------------------------------ */
/* Symbols describing the geometry of the display.*/

#define cbOledDispMax 512 //max number of bytes in display buffer
#define ccolOledMax 128 //number of display columns
#define crowOledMax 32 //number of display rows
#define cpagOledMax 4 //number of display memory pages

/* ------------------------------------------------------------ */
/* This array is the off-screen frame buffer used for rendering.
** It isn't possible to read back from the OLED display device,
** so display data is rendered into this off-screen buffer and then
** copied to the display.
*/
char rgbOledBmp[cbOledDispMax];

void OledUpdate();
char Spi2PutByte(char bVal);

void light_up_pixel(uint8_t x, uint8_t y){
    spi_send_recv(x);
    spi_send_recv(y);
    display_update();
    return;
}

void OledUpdate() {
    int ipag;
    int icol;
    char * pb;
    pb = rgbOledBmp;
    for (ipag = 0; ipag < cpagOledMax; ipag++) {
        DISPLAY_CHANGE_TO_COMMAND_MODE;
        /* Set the page address */
        Spi2PutByte(0x22); //Set page command
        Spi2PutByte(ipag); //page number
        /* Start at the left column */
        Spi2PutByte(0x00); //set low nybble of column
        Spi2PutByte(0x10); //set high nybble of column
        DISPLAY_CHANGE_TO_DATA_MODE;
        /* Copy this memory page of display data. */
        //OledPutBuffer(ccolOledMax, pb);
        //pb += ccolOledMax;
    }
}

char Spi2PutByte(char bVal) {
    char bRx;
    /* Wait for transmitter to be ready*/
    while (SPI2STAT == 0);
    /* Write the next transmit byte.*/
    SPI2BUF = bVal;
    /* Wait for receive byte.*/
    while (SPI2STAT == 0);
    /* Put the received byte in the buffer.*/
    bRx = SPI2BUF;
    return bRx;
}

void OledPutBuffer(int cb, char * rgbTx) {
    int ib;
    char bTmp;
    /* Write/Read the data */
    for (ib = 0; ib < cb; ib++) {
    /* Wait for transmitter to be ready */
    while (SPI2STAT == 0);
    /* Write the next transmit byte. */
    SPI2BUF = *rgbTx++;
    /* Wait for receive byte.*/
    while (SPI2STAT == 0);
    bTmp = SPI2BUF;
    }
}