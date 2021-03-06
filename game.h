#ifndef game_h
#define game_h

#include "mainheader.h"
#include <allegro5/allegro.h>
#include <math.h>


typedef struct {
    ALLEGRO_BITMAP* bitmap;
    int x, y;
    //TODO: Zoek een manier om ervoor te zorgen dat de void pointer hier niet nodig is
    bool (*draw_sprite) (void* self);
    bool (*update_sprite) (void* self, void* data);

    //An extra data structure encapsulated in the sprite for extra specific info
    void* extra_data;

} TPongSprite;

typedef struct {
    int x, y;
} TPongPoint;

typedef struct {
    double x, y;
} TPongVec;

typedef struct {
    unsigned int your_score;
    unsigned int enemy_score;
    
    TPongSprite *you;
    TPongSprite *enemy;
    TPongSprite *ball;
} TPongGame;


bool sprite_draw(TPongSprite* sprite);
bool sprite_update(TPongSprite* sprite, ALLEGRO_EVENT ev);
TPongPoint sprite_get_center_point(TPongSprite* sprite);
TPongVec sprite_calculate_gap(TPongSprite* spriteA, TPongSprite* spriteB);

bool sprite_detect_collision(TPongSprite* spriteA, TPongSprite* spriteB);

TPongGame* create_game();

//The main game
void run_game(TPongGame* game);
void game_draw(TPongGame* game);


#endif