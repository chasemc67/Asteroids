#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

int main()
{
    //===Set ship Color=====================================
    ALLEGRO_COLOR shipColor = al_map_rgb(50,50,50);
    
    //===Set up Display=====================================
    al_init();
    al_create_display(640, 480);
    al_clear_to_color(al_map_rgb(84,151,252));
    al_set_new_display_refresh_rate(1);
    
    //===Set up ship struct
    typedef struct {
        float sx;
        float sy;
        float heading;
        float speed;
        int gone;
        ALLEGRO_COLOR color;
    } Spaceship;
    
    Spaceship myShip = {320, 240, 0, 0, 1, al_map_rgb(50,50,50)};
    
    //===Draw ship==========================================
    //al_draw_line(42, 59, 50, 39,al_map_rgb(50,50,50) , 3.0f);
    //al_draw_line(50, 39, 58, 59,al_map_rgb(50,50,50), 3.0f);
    //al_draw_line(44, 54, 49, 54, al_map_rgb(50,50,50), 3.0f);
    //al_draw_line(56, 54, 51, 54, al_map_rgb(50,50,50), 3.0f);
    
    al_draw_line(myShip.sx-8, myShip.sy+9, myShip.sx, myShip.sy-11,myShip.color, 3.0f);
    al_draw_line(myShip.sx, myShip.sy-11, myShip.sx+8, myShip.sy+9,myShip.color, 3.0f);
    al_draw_line(myShip.sx-6, myShip.sy+4, myShip.sx-1, myShip.sy+4,myShip.color, 3.0f);
    al_draw_line(myShip.sx+6, myShip.sy+4, myShip.sx+1, myShip.sy+4,myShip.color, 3.0f);
    
    al_flip_display();
    al_rest(1.0);
    
    //===Wait for event from event queue=====================
    ALLEGRO_EVENT_QUEUE *queue;
    queue = al_create_event_queue();
    
    ALLEGRO_EVENT event;
    al_wait_for_event(queue, &event);
    
    //while(1);
    /*/{
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                    myShip.sx = myShip.sx-10;
                    break;
                    
                case ALLEGRO_KEY_RIGHT:
                    myShip.sx = myShip.sx+10;
                    break;
                    
                case ALLEGRO_KEY_SPACE:
                    //fire
                    break;
            }
        }
     
     al_flip_display();
     al_rest(1.0);

    }
    /*/

}