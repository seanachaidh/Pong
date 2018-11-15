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

void run_menu(ALLEGRO_DISPLAY* display, PPong_menu* menu){
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
                            printf("Up pressed\n");
                            menu->selected_item -= 1;
                        case ALLEGRO_KEY_DPAD_DOWN:
                            menu->selected_item += 1;
                            printf("Down pressed\n");
                        default:
                            printf("Unrecognized key pressend\n");
                    }
                    break;
            }
        }
    }
}
