#include "game.h"

TPongGame* create_game() {
    TPongGame* retval = (TPongGame*) malloc(sizeof(TPongGame));   

}

bool sprite_detect_collision(TPongSprite* spriteA, TPongSprite* spriteB) {
    //We beginnen eerst gewoon met de bouncing box
    // int spriteAX = spriteA->x;
    // int spriteAY = spriteA->y;
    // int spriteBX = spriteB->x;
    // int spriteBY = spriteB->y;

    // int spriteAXX = spriteAX + al_get_bitmap_width(spriteA->bitmap);
    // int spriteAYY = spriteAY + al_get_bitmap_height(spriteA->bitmap);
    // int spriteBXX = spriteBX + al_get_bitmap_width(spriteB->bitmap);
    // int spriteBYY = spriteBY + al_get_bitmap_height(spriteB->bitmap);

    // if((spriteAX - spriteBXX) < 0) {
    //     return false;
    // } else if ((spriteA))

    return false;
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