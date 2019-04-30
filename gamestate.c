#include <stdio.h>
#include <gb/gb.h>
#include "gamestate.h"

UBYTE gamestate;
UBYTE joystate;
UBYTE sprites_used, next_sprite;

void clearSprites(){
    UBYTE i;
    for(i = 0U; i < 40U; ++i) move_sprite(i, 0U, 0U);
    sprites_used = 0U;
    next_sprite = 0U;
}

void updateJoystate(){
    joystate = joypad();
}

void setSprite(UBYTE x, UBYTE y, UBYTE tile, UBYTE prop){
    move_sprite(next_sprite, x, y);
    set_sprite_tile(next_sprite, tile);
    set_sprite_prop(next_sprite, prop);

    sprites_used++;
    next_sprite++;
    if(next_sprite == 40U) next_sprite = 0U;
}
