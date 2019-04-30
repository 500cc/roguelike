#ifndef GAMESTATE_H
#define GAMESTATE_H

void clearSprites();
void updateJoystate();
void setSprite(UBYTE x, UBYTE y, UBYTE tile, UBYTE prop);

extern UBYTE gamestate;
extern UBYTE joystate;
extern UBYTE next_sprite, sprites_used;

#define GAMESTATE_INGAME 0U
#define GAMESTATE_TITLE 1U

#endif
