//
//  menu.h
//  Pong
//
//  Created by Pieter Van Keymeulen on 13/11/2018.
//  Copyright © 2018 Pieter Van Keymeulen. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

typedef struct {
    char* title;
    char* value;
} TPong_menu_item;

typedef struct TPong_menu {
    int selected_item;
    int item_amount;
    TPong_menu_item** menu_items;
} PPong_menu;


TPong_menu_item* create_menu_item(char* title, char* value);
ALLEGRO_BITMAP* menu_item_create_bitmap(TPong_menu_item* item, width, int height);
void menu_item_free(TPong_menu_item* menu_item);

PPong_menu* create_menu(void);
void menu_add_item(PPong_menu* menu, TPong_menu_item* item);
void menu_select_item(PPong_menu* menu, int item);

void run_menu(PPong_menu* menu, ALLEGRO_DISPLAY* display);

#endif /* menu_h */
