#include <stdio.h>
#include <gb/gb.h>
#include "game.h"
#include "gamestate.h"

#include "data/shami.h"
#include "data/ground.h"

void initGame(){
    disable_interrupts();
    DISPLAY_OFF;
    OBP0_REG = 0xE0U;
    SPRITES_8x16;
    set_bkg_data(0U, ground_tile_data_size, ground_tile_data);

    set_sprite_data(0U, 1U, shami_tile_data);
    set_sprite_data(1U, 1U, shami_tile_data + 192U);
    set_sprite_data(2U, 1U, shami_tile_data + 16U);
    set_sprite_data(3U, 1U, shami_tile_data + 208U);
    set_sprite_data(4U, 1U, shami_tile_data);
    set_sprite_data(5U, 1U, shami_tile_data + 160U);
    set_sprite_data(6U, 1U, shami_tile_data + 16U);
    set_sprite_data(7U, 1U, shami_tile_data + 176U);
    set_sprite_data(4U, 1U, shami_tile_data);
    set_sprite_data(5U, 1U, shami_tile_data + 224U);
    set_sprite_data(6U, 1U, shami_tile_data + 16U);
    set_sprite_data(7U, 1U, shami_tile_data + 240U);

    clearSprites();
    setSprite(32U, 32U, 4U, 0U);
    setSprite(40U, 32U, 6U, 0U);

    player_x = 0U;
    player_y = 0U;
    
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    enable_interrupts();
}

void updatePlayer(){
    
    if(CLICKED(J_LEFT)){
        player_x -= 1;
    }
    if(CLICKED(J_RIGHT)){
        player_x += 1;
    }
    if(CLICKED(J_UP)){
        player_y -= 1;
    }
    if(CLICKED(J_DOWN)){
        player_y += 1;
    }

    scroll_x = player_x << 4;
    scroll_y = player_y << 4;

    move_bkg(scroll_x, scroll_y);
}


void enterGame(){
    initGame();

    while(1U){
        updateJoystate();

        updatePlayer();
    }
}
