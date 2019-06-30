//#include <stdio.h>
#include <gb/gb.h>
#include "title.h"
#include "gamestate.h"

void initTitle(){
    //printf("PRESS START");
}

void enterTitle(){
    initTitle();
    
    waitpad(J_START);
    gamestate = 0U;
}
