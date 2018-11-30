#ifndef BALL_H
#define BALL_H

#include "game.h"

typedef struct {
    int vel_x;
    int vel_y;
    int speed;
} TPongBallExtra;

TPongSprite * create_sprite_ball(int locx, int locy);
bool sprite_ball_update(TPongSprite* ball, void* ev);

#endif