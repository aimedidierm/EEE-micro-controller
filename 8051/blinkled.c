#include <reg51.h>
#define LED P1
void delay(unsigned int time){
    for(i=0;i<1000;i++);
    for(j=0;j<time;j++);
}
void main(){
    LED = 0x00;
    delay(2000);
    LED=oxff;
    delay(1000);
}