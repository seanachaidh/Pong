#include "game.h"

TPongGame* create_game() {
    TPongGame* retval = (TPongGame*) malloc(sizeof(TPongGame));  

    return retval; 
}

bool sprite_detect_collision(TPongSprite* spriteA, TPongSprite* spriteB) {
    int spriteA_width = al_get_bitmap_width(spriteA->bitmap);
    int spriteA_height = al_get_bitmap_height(spriteA->bitmap);
    int spriteB_width = al_get_bitmap_width(spriteB->bitmap);
    int spriteB_height = al_get_bitmap_height(spriteB->bitmap);

    if(
        spriteA->x < spriteB->x + spriteB_width &&
        spriteA->x + spriteA_width > spriteB->x &&
        spriteA->y < spriteB->y + spriteB_height &&
        spriteA->y + spriteA_height > spriteB->y) {
            return true;
        } else {
            return false;
        }
}

TPongVec sprite_calculate_gap(TPongSprite* spriteA, TPongSprite* spriteB) {
    TPongVec retval;
    TPongPoint centerA = sprite_get_center_point(spriteA);
    TPongPoint centerB = sprite_get_center_point(spriteB);
    
}

TPongPoint sprite_get_center_point(TPongSprite* sprite) {
    TPongPoint retval;
    retval.x = sprite->x + round(al_get_bitmap_width(sprite->bitmap) / 2);
    retval.y = sprite->y + round(al_get_bitmap_height(sprite->bitmap) / 2);

    return retval;
}

void run_game(TPongGame* game) {
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(60/FPS);
    bool inloop = true;

    //REGISTER ALL OUR SOURCES
    al_register_event_source(queue, al_get_display_event_source(al_get_current_display()));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    while(inloop) {
        ALLEGRO_EVENT ev;
        if(al_get_next_event(queue, &ev)) {
            if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                // Shakel tussen de verschillende keyboard events
                switch(ev.keyboard.keycode) {
                    case ALLEGRO_KEY_RIGHT:
                        printf("Key right pressed\n");
                        break;
                    case ALLEGRO_KEY_LEFT:
                        printf("Left key pressed\n");
                        break;
                    default:
                        printf("Unknown key pressed: %d\n", ev.keyboard.keycode);
                }
            } else if(ev.type == ALLEGRO_EVENT_TIMER) {
                //TODO draw game here
            }
        }
    }
}

void game_draw(TPongGame* game) {

    //TODO: Draw possible score

    game->enemy->draw_sprite(game->enemy);
    game->you->draw_sprite(game->you);
    game->ball->draw_sprite(game->ball);
}
