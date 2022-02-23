#include <stdint.h>
#include <pic32mx.h>
/*
    Return status for the four switches in the 4 LSB
*/
int getsw(void){
    int sw_status;
    sw_status = PORTD >> 8;
    sw_status &= 0x000f;
    return sw_status;
}

/*
    Returns the status for switch 4
    1 = switch set towards display
    0 = switch set away from display
*/
int getsw4(void){
    int sw_status = getsw();
    int sw4 = sw_status & 0x8;
    return sw4;
}


/*
    Returns the status for switch 4
    1 = switch set towards display
    0 = switch set away from display
*/
int getsw3(void){
    int sw_status = getsw();
    int sw3 = sw_status & 0x4;
    return sw3;
}


/*
    Returns the status for switch 4
    1 = switch set towards display
    0 = switch set away from display
*/
int getsw2(void){
    int sw_status = getsw();
    int sw2 = sw_status & 0x2;
    return sw2;
}


/*
    Returns the status for switch 4
    1 = switch set towards display
    0 = switch set away from display
*/
int getsw1(void){
    int sw_status = getsw();
    int sw1 = sw_status & 0x1;
    return sw1;
}

/*
    Returns status for the four pushbuttons in the 4 LSB
*/
int getbtns(void){
    int btns_status;
    btns_status = PORTD >> 4;
    btns_status &= 0x000f;
    return btns_status;
}
/*
    Returns the status for button 4
    1 = button pushed
    0 = button not pushed
*/
int getbtn4(){
    int btns = getbtns();
    int button4 = btns & 0x8;
    return button4;
}

/*
    Returns the status for button 3
    1 = button pushed
    0 = button not pushed
*/
int getbtn3(){
    int btns = getbtns();
    int button4 = btns & 0x4;
    return button4;
}

/*
    Returns the status for button 2
    1 = button pushed
    0 = button not pushed
*/
int getbtn2(){
    int btns = getbtns();
    int button4 = btns & 0x2;
    return button4;
}

/*
    Returns the status for button 1
    1 = button pushed
    0 = button not pushed
*/
int getbtn1(){
    int btns = getbtns();
    int button4 = btns & 0x1;
    return button4;
}

