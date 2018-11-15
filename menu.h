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
#include <allegro5/allegro.h>

typedef struct TPong_menu {
    int selected_item;
} PPong_menu;

void run_menu(ALLEGRO_DISPLAY* display, PPong_menu* menu);

#endif /* menu_h */
