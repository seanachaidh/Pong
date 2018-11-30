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
