#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Include the menu
#include "menu.h"


void init_program() {
    al_init();
    al_install_keyboard();
    
    //for the fonts
    al_init_font_addon();
    al_init_ttf_addon();

}

void shutdown_program() {
    al_uninstall_keyboard();
    al_uninstall_system();
}

ALLEGRO_DISPLAY *create_display(void) {
    ALLEGRO_DISPLAY* retval = al_create_display(800, 600);
    return retval;
}

int main(int argc, char **argv)
{
    ALLEGRO_DISPLAY* my_display;
    PPong_menu* menu;
    
    init_program();
    
    my_display = create_display();
    menu = create_menu();

    run_menu(menu, my_display);
    
    shutdown_program();
    printf("program finished\n");
    
    return 0;
}
