#ifndef GAMESTATE_H
#define GAMESTATE_H

void clearSprites();
void updateJoystate();
void setSprite(UBYTE x, UBYTE y, UBYTE tile, UBYTE prop);

extern UBYTE gamestate;
extern UBYTE joystate, oldjoystate;
extern UBYTE next_sprite, sprites_used;

extern UBYTE scroll_x, scroll_y;
extern UBYTE player_local_x, player_local_y;
extern UBYTE player_x, player_y;

#define GAMESTATE_INGAME 0U
#define GAMESTATE_TITLE 1U

#define CLICKED(x) ((joystate & x) && (joystate & x) != (oldjoystate & x)) 
#define RELEASED(x) (!(joystate & x) && (joystate & x) != (oldjoystate & x))
#define ISDOWN(x) (joystate & x)

#endif
