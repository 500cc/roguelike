#include <stdio.h>
//#include <gb/gb.h>
#include "main.h"

#include "gamestate.h"
#include "game.h"
#include "title.h"

void main(){
    //init hardware
    disable_interrupts();
    gamestate = GAMESTATE_TITLE;
    joystate = 0U;
    enable_interrupts();
    
    while(1U){
        switch(gamestate){
            case GAMESTATE_INGAME:
                enterGame();
                break;
            case GAMESTATE_TITLE:
                enterTitle();
                break;
        }
    }
}
