#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>				//Our primitive header file
#include <stdio.h>

//===Set up ship struct
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;


void draw_ship(Spaceship *s)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    //al_rotate_transform(&transform, DEGREES(s->heading));
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    /*
     al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
     al_draw_line(0, -11, 8, 9, s->color, 3.0f);
     al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
     al_draw_line(6, 4, 1, 4, s->color, 3.0f);
     */
    
    al_draw_line(s->sx - 8, s->sy + 9, s->sx, s->sy - 11,s->color, 3.0f);
    al_draw_line(s->sx, s->sy-11, s->sx+8, s->sy+9,s->color, 3.0f);
    al_draw_line(s->sx-6, s->sy+4, s->sx-1, s->sy+4,s->color, 3.0f);
    al_draw_line(s->sx+6, s->sy+4, s->sx+1, s->sy+4,s->color, 3.0f);
    
    
}

int main(void)
{
    //===Set ship Color=====================================
    ALLEGRO_COLOR shipColor = al_map_rgb(50,50,50);
    
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
    
	int width = 640;
	int height = 480;
	
	bool done = false;
	int pos_x = width / 2;
	int pos_y = height / 2;
    
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    
	if(!al_init())										//initialize Allegro
		return -1;
    
	display = al_create_display(width, height);			//create our display object
    
	if(!display)										//test display object
		return -1;
    
	al_init_primitives_addon();
	al_install_keyboard();
    
	event_queue = al_create_event_queue();
    
	al_register_event_source(event_queue, al_get_keyboard_event_source());
    
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
        
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					//pos_y -= 10;
                    myShip.sy = myShip.sy + 10;
					break;
				case ALLEGRO_KEY_DOWN:
					//pos_y += 10;
                    myShip.sy = myShip.sy - 10;
					break;
				case ALLEGRO_KEY_RIGHT:
					//pos_x += 10;
                    myShip.sx = myShip.sx + 10;
					break;
				case ALLEGRO_KEY_LEFT:
					//pos_x -= 10;
                    myShip.sx = myShip.sx - 10;
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				done = true;
		}
        
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
		al_clear_to_color(al_map_rgb(0,0,0));
	}
    
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object
    
	return 0;
}