#include <stdint.h>
#include <pic32mx.h>

int getsw(void){
    int sw_status;
    sw_status = PORTD >> 8;
    sw_status &= 0x000f;
    return sw_status;
}

int getbtns(void){
    int btns_status;
    btns_status = PORTD >> 5;
    btns_status &= 0x0007;
    return btns_status;
}

int getbtn4(){
    int btns = getbtns();
    int button4 = btns & 0x4;
    return button4;
}