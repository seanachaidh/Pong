//
//  menu.c
//  Pong
//
//  Created by Pieter Van Keymeulen on 13/11/2018.
//  Copyright © 2018 Pieter Van Keymeulen. All rights reserved.
//

#include "menu.h"
#include "mainheader.h"

ALLEGRO_EVENT_QUEUE* create_event_queue(ALLEGRO_DISPLAY* display) {
    ALLEGRO_EVENT_QUEUE* retval;
    retval = al_create_event_queue();
    
    //Voorlopig zijn we enkel geïnteresseerd in de display en toetsenbord
    al_register_event_source(retval, al_get_display_event_source(display));
    al_register_event_source(retval, al_get_keyboard_event_source());
    
    return retval;
}

ALLEGRO_BITMAP* menu_item_create_bitmap(TPong_menu_item* item, ALLEGRO_FONT* used_font, int width, int height) {
    ALLEGRO_STATE prevstate;
    al_store_state(&prevstate, ALLEGRO_STATE_ALL);

    //prepare transformation
    ALLEGRO_TRANSFORM t;
    al_identity_transform(&t);
    al_scale_transform(&t, width, height);
    al_use_transform(&t);

    size_t final_string_size = strlen(item->value) + strlen(item->title) + 3;
    char* final_string = (char*) malloc(final_string_size * sizeof(char));
    sprintf(final_string, "%s: %s", item->title, item->value);
    
    ALLEGRO_BITMAP *retval = al_create_bitmap(width, height);
    al_set_target_bitmap(retval);
    al_draw_text(used_font, al_map_rgb(255, 255, 255), 0, 0, ALLEGRO_ALIGN_CENTER, final_string);

    al_restore_state(&prevstate);
    return retval;
}

TPong_menu_item* create_menu_item(char* title, char* value) {
    TPong_menu_item* retval = (TPong_menu_item*) malloc(sizeof(TPong_menu_item));
    retval->title = (char*) malloc((strlen(title) + 1) * sizeof(char));
    retval->value = (char*)  malloc((strlen(value) + 1) * sizeof(char));

    //Kopiëren geheugen
    strcpy(retval->title, title);
    strcpy(retval->value, value);

    return retval;
}

void menu_item_free(TPong_menu_item* menu_item) {
    free(menu_item->title);
    free(menu_item->value);

    free(menu_item);
}

PPong_menu* create_menu(int width, int height, ALLEGRO_FONT *font){
    PPong_menu* retval = (PPong_menu*) malloc(sizeof(PPong_menu));

    retval->selected_item = 0;
    retval->item_amount = 0;
    retval->menu_items = NULL;

    // Moet ik dit verwijderen bij vernietiging object?
    retval->used_font = font;

    retval->width = width;
    retval->height = height;

    return retval;
}

void menu_add_item(PPong_menu* menu, TPong_menu_item* item) {
    menu->item_amount += 1;
    if(!menu->menu_items) {
        menu->menu_items = (TPong_menu_item**) malloc(menu->item_amount * sizeof(TPong_menu_item*));
        menu->menu_items[0] = item;
    } else {
        TPong_menu_item** newpointer = (TPong_menu_item**) malloc(menu->item_amount * sizeof(TPong_menu_item*));
        //coppy all
        int i;
        for(i = 0; i < (menu->item_amount - 1); i++)
        {
            newpointer[i] = menu->menu_items[i];
        }
        newpointer[menu->item_amount - 1] = item;

        free(menu->menu_items);
        menu->menu_items = newpointer;
    }
}

void menu_select_item(PPong_menu* menu, int item) {
    menu->selected_item = item;
    //bind the value to its limits
    if (menu->selected_item < 0) {
        menu->selected_item = 0;
    } else if (menu->selected_item >= menu->item_amount) {
        menu->selected_item = (menu->item_amount - 1);
    }
}

void menu_draw(PPong_menu* menu) {
    //TODO make the 10 pixel margin a variable
    int item_height = round(menu->height / menu->item_amount) - 10;
    ALLEGRO_BITMAP* item_bitmaps[menu->item_amount];
    size_t i;

    for(i = 0; i < menu->item_amount; i++){
        item_bitmaps[i] = menu_item_create_bitmap(menu->menu_items[i], menu->used_font, menu->width, item_height);
        //now....? We draw!!!
        al_draw_bitmap(item_bitmaps[i], item_height*(i+1), menu->width, 0);
    }
}

void run_menu(PPong_menu* menu, ALLEGRO_DISPLAY* display){
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* my_queue = create_event_queue(display);
    int inloop = 1;
    while(inloop) {
        bool event_val;
        
        event_val = al_get_next_event(my_queue, &event);
        if(event_val) {
            //process events
            switch (event.type) {
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    inloop = 0;
                    break;
                case ALLEGRO_EVENT_KEY_DOWN:
                    switch (event.keyboard.keycode) {
                        case ALLEGRO_KEY_ESCAPE:
                            inloop = 0;
                            break;
                        
                        //DPAD controls
                        case ALLEGRO_KEY_DPAD_UP:
                            menu_select_item(menu, menu->selected_item - 1);
                            printf("Up pressed\n");
                        case ALLEGRO_KEY_DPAD_DOWN:
                            menu_select_item(menu, menu->selected_item + 1);
                            printf("Down pressed\n");
                        default:
                            printf("Unrecognized key pressend\n");
                    }
                    break;
            }
        }
        menu_draw(menu);
        al_flip_display();
    }
}
