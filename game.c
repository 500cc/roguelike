#include <stdio.h>
#include <gb/gb.h>
#include "game.h"
#include "gamestate.h"

#include "shami.h"

void initGame(){
    disable_interrupts();
    DISPLAY_OFF;
    OBP0_REG = 0xE0U;
    SPRITES_8x16;

    set_sprite_data(0U, 1U, shami_tile_data);
    set_sprite_data(1U, 1U, shami_tile_data + 192U);
    set_sprite_data(2U, 1U, shami_tile_data + 16U);
    set_sprite_data(3U, 1U, shami_tile_data + 208U);

    clearSprites();
    setSprite(32U, 32U, 0U, 0U);
    setSprite(40U, 32U, 2U, 0U);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    enable_interrupts();
}


void enterGame(){
    initGame();

    while(1U){
        updateJoystate();
    }
}
