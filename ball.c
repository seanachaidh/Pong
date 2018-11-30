#include "ball.h"

TPongSprite * create_sprite_ball(int locx, int locy) {
    TPongSprite* retval = (TPongSprite*) malloc(sizeof(TPongSprite));

    retval->x = locx;
    retval->y = locy;
    retval->draw_sprite = NULL;
    retval->update_sprite = &sprite_ball_update;

    retval->extra_data = (TPongBallExtra*) malloc(sizeof(TPongBallExtra));

    TPongBallExtra* myextra = (TPongBallExtra*) retval->extra_data;
    myextra->vel_x = 4.0;
    myextra->vel_y = 4.0;

    myextra->speed = 1;

    return retval;
}

bool sprite_ball_update(void* self, void* ev) {
    TPongSprite *ball = (TPongSprite*) self;
    ALLEGRO_DISPLAY* display = al_get_current_display();
    TPongBallExtra* metadata = (TPongBallExtra*) ball->extra_data;
    TPongSprite* collided_sprite = (TPongSprite*) ev;
    
    int ball_width = al_get_bitmap_width(ball->bitmap);
    int ball_height = al_get_bitmap_height(ball->bitmap);

    int screen_width = al_get_display_width(display);
    int screen_height = al_get_display_height(display);

    if (ball->x < 0 || ball->x > (screen_width - ball_width)) {
        metadata->vel_x = -(metadata->vel_x);
    }

    if (ball->y < 0 || ball->y > (screen_height - ball_height)) {
        metadata->vel_y = -(metadata->vel_y);
    }

    ball->x = ball->x + metadata->vel_x;
    ball->y = ball->y + metadata->vel_y;

    return true;
}
