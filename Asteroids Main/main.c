#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>
#include "movement"

#define PI = 3.14159265

//Globals==========================================================================
bool isAlive = 1;

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



int main()
{
    while (isAlive)
    {
        //run movement thread
        //run controls thread
        //run collision check thread
        //run gui thread
    }
    
    //cleanup and shutdown. 
}