#include <allegro5/allegro.h>



typedef struct{
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;



int main(int argc, char **argv) {
    al_init();
    al_create_display(640, 480);
    al_clear_to_color(al_map_rgb_f(1, 1, 0));
    al_flip_display();
    al_rest(10.0);
    
    
    Spaceship s;
    
    al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
    al_draw_line(0, -11, 8, 9, s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
    al_draw_line(6, 4, 1, 4, s->color, 3.0f);
    
    
    return 0;
}