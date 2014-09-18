#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>

#define PI = 3.14159265

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

ALLEGRO_TRANSFORM transform;

//Function Headers=================================================================
void drawShip(Spaceship *s);
void turnShip(Spaceship *s);
void makeStep(Spaceship *s);
void makeBackStep(Spaceship *s);

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
    Spaceship ship = {320, 240, 0, 0, 1, al_map_rgb(50,50,50)};
    
    drawShip(&ship);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    
    //set up display close handling and keyboard handling
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    al_init_primitives_addon();
	al_install_keyboard();
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    
    //run
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
        
        //ship.speed -= keys[UP] * 10;
		//ship.speed += keys[DOWN] * 10;
        if(keys[UP])
            makeStep(&ship);
        if(keys[DOWN])
            makeBackStep(&ship);
		ship.heading -= (keys[LEFT] * 10);
		ship.heading += (keys[RIGHT] * 10);
        
        if (ship.heading < 0)
            ship.heading += 360;
        if (ship.heading > 360)
            ship.heading -= 360;
        
        turnShip(&ship);
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
        
        /*
         while (ship.speed > 0)
         {
         float sRads = ship.heading * 3.14 / 180;
         //add to x and y appropriately from heading.
         
         
         if(sRads <= 3.14 )
         {
         if (sRads <= 1.579)
         {
         ship.sx + ship.speed/2;
         ship.sy + ship.speed/2;
         }
         else
         {
         ship.sx + ship.speed/2;
         ship.sy - ship.speed/2;
         }
         }
         else
         {
         if (sRads >= 4.1723)
         {
         //x--
         //y++
         ship.sx - ship.speed/2;
         ship.sy + ship.speed/2;
         }
         else
         {
         //x--
         //y--
         ship.sx - ship.speed/2;
         ship.sy - ship.speed/2;
         }
         
         }
         
         al_flip_display();
         al_clear_to_color(al_map_rgb(0,0,0));
         ship.speed -= 5;
         }*/
        
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

void turnShip(Spaceship *s)
{
    float sRads = s->heading * 3.14 / 180;
    
    al_identity_transform(&transform);
    al_rotate_transform(&transform, sRads);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    
    al_draw_line(-8, 9, 0, -11,s->color, 3.0f);
    al_draw_line(0, -11, 8, 9,s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4,s->color, 3.0f);
    al_draw_line(6, 4, 1, 4,s->color, 3.0f);
    
}

void makeStep(Spaceship *s)
{
    //determine amount of x and y to increment for some Degrees of heading to travel that direction
    float sRads = s->heading * 3.14 / 180;
    
    s->sx = s->sx + (sin(sRads) * 10);
    s->sy = s->sy - (cos(sRads)*10);
    
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    
    fprintf(stderr, "Ship x: %f\nShip y: %f\nx + %f\ny - %f\n\n", s->sx, s->sy, sin(sRads) * 10, cos(sRads)*10);
    
    al_draw_line(-8, 9, 0, -11,s->color, 3.0f);
    al_draw_line(0, -11, 8, 9,s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4,s->color, 3.0f);
    al_draw_line(6, 4, 1, 4,s->color, 3.0f);
    //al_translate_transform(&transform, s->sx-(sin(sRads) * s->speed), s->sy + s->speed);
    
}

void makeBackStep(Spaceship *s)
{
    float sRads = s->heading * 3.14 / 180;
    
    s->sx = s->sx - (sin(sRads) * 10);
    s->sy = s->sy + (cos(sRads)*10);
    
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    
    fprintf(stderr, "Ship x: %f\nShip y: %f\nx - %f\ny + %f\n\n", s->sx, s->sy, sin(sRads) * 10, cos(sRads)*10);
    
    al_draw_line(-8, 9, 0, -11,s->color, 3.0f);
    al_draw_line(0, -11, 8, 9,s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4,s->color, 3.0f);
    al_draw_line(6, 4, 1, 4,s->color, 3.0f);
    //al_translate_transform(&transform, s->sx-(sin(sRads) * s->speed), s->sy + s->speed);
}