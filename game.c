//#include <stdio.h>
#include <gb/gb.h>
#include "game.h"
#include "gamestate.h"

#include "data/shami.h"
#include "data/ground.h"
#include "data/textbox.h"

#include "level.h"

void initGame(){
    disable_interrupts();
    DISPLAY_OFF;
    OBP0_REG = 0xE0U;
    SPRITES_8x16;
    set_bkg_data(0U, ground_tile_count, ground_tile_data);
    set_bkg_tiles(0U, 0U, 32U, 32U, level_data);

    set_win_data(1U, textbox_tile_count, textbox_tile_data);
    set_win_tiles(0U, 0U, textbox_tile_map_width, textbox_tile_map_height, textbox_map_data);
    move_win(7U, 128U);

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
    setSprite(0U, 0U, 4U, 0U);
    setSprite(8U, 0U, 6U, 0U);

    player_x = 0U;
    player_y = 0U;
    player_local_x = 0U;
    player_local_y = 0U;
    
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;
    enable_interrupts();
}

void updatePlayer(){
    if(CLICKED(J_LEFT)){
        player_x -= 1U;
    }
    if(CLICKED(J_RIGHT)){
        player_x += 1U;
    }
    if(CLICKED(J_UP)){
        player_y -= 1U;
    }
    if(CLICKED(J_DOWN)){
        player_y += 1U;
    }

    player_local_x = 4U << 4U;
    player_local_y = 3U << 4U;
    scroll_x = player_x - 4U << 4U;
    scroll_y = player_y - 3U << 4U;

    if(player_x < 5U){
        player_local_x = player_x << 4U;
        scroll_x = 0;
    }
    if(player_x > (LEVEL_WIDTH - 5U)){
        player_local_x = player_x + 8U - LEVEL_WIDTH << 4U;
        scroll_x = LEVEL_WIDTH - 8U << 4U;
    }
    if(player_y < 4U){
        player_local_y = player_y << 4U;
        scroll_y = 0;
    }
    if(player_y > LEVEL_HEIGHT - 3U){
        player_local_y = player_y + 6U - LEVEL_HEIGHT << 4U;
        scroll_y = LEVEL_HEIGHT - 6U << 4U;
    }

    move_bkg(scroll_x, scroll_y);
    setSprite(player_local_x + 16U, player_local_y + 24U, 4U, 0U);
    setSprite(player_local_x + 24U, player_local_y + 24U, 6U, 0U);
}

void updateHUD(){
    if(CLICKED(J_SELECT)){
        move_win(7U, 112U);
    }
    if(RELEASED(J_SELECT)){
        move_win(7U, 128U);
    }
}

void enterGame(){
    initGame();

    while(1U){
        updateJoystate();

        updatePlayer();
        updateHUD();
    }
}
