//Object IDS
enum IDS{PLAYER, BULLET, ENEMY};

//Our Player
typedef struct
{
	int ID;
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
} SpaceShip;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
}Bullet;

typedef struct
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;
}Comet;