#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog_box.h>
#include <stdio.h>

int main()
{
    ALLEGRO_DISPLAY *display = NULL;
    
    if (!al_init())
    {
        fprintf(stderr, "Cannot innit");
        return -1;
    }
    
    display = al__create_display(640, 480);
        
    if(!display)
    {
        fprintf(stderr, "Cannot display");
    }
        
    al_destroy_display(display);
        
    return 0;
}
