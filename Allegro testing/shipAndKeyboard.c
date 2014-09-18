#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

//Globals==========================================================================
typedef struct{
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;

enum KEYS{UP, DOWN, LEFT, RIGHT};
bool keys[4] = {false, false, false, false};
bool done = 0;


//Function Headers=================================================================
void drawShip(Spaceship *s);

//Main=============================================================================
int main()
{
    //create display
    if(!al_init())
		return -1;
    ALLEGRO_DISPLAY *display = NULL;
    display = al_create_display(640, 480);
    if(!display)
		return -1;
    
    //create ship
    fprintf(stderr, "create ship");
    Spaceship ship = {320, 240, 0, 0, 1, al_map_rgb(50,50,50)};
    
    drawShip(&ship);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    
    //set up display close handling and keyboard handling
    fprintf(stderr, "setup display");
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    al_init_primitives_addon();
	al_install_keyboard();
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    
    //run
    fprintf(stderr, "run");
    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        
        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    keys[UP] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    keys[RIGHT] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    keys[LEFT] = true;
                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
        
        ship.sy -= keys[UP] * 10;
		ship.sy += keys[DOWN] * 10;
		ship.sx -= keys[LEFT] * 10;
		ship.sx += keys[RIGHT] * 10;
        
        drawShip(&ship);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        
    }
    
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    
    return 0;
}

//Functions========================================================================
void drawShip(Spaceship *s)
{
    al_draw_line(s->sx - 8, s->sy + 9, s->sx, s->sy - 11,s->color, 3.0f);
    al_draw_line(s->sx, s->sy-11, s->sx+8, s->sy+9,s->color, 3.0f);
    al_draw_line(s->sx-6, s->sy+4, s->sx-1, s->sy+4,s->color, 3.0f);
    al_draw_line(s->sx+6, s->sy+4, s->sx+1, s->sy+4,s->color, 3.0f);
    
}