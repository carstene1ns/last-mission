#ifndef _ENEMIES_H_
#define _ENEMIES_H_

#define SH_DEAD 0
#define SH_ACTIVE 1

#define AI_STATIC			0 // breakable wall or non-moving enemy
#define AI_RANDOM_MOVE			1 // randomly moving enemy
#define AI_KAMIKADZE			2
#define AI_ELECTRIC_SPARKLE_VERTICAL	3 // electric sparkle going up-down
#define AI_CEILING_CANNON		4 // ceiling cannon spawning kamikazes
#define AI_HOMING_MISSLE		5
#define AI_CANNON			6
#define AI_ELECTRIC_SPARKLE_HORIZONTAL	7 // electric sparkle going left-right
#define AI_EXPLOSION			8 // does one animation cycle
#define AI_BRIDGE			9 // appears if bonded ship, disappear otherwise
#define AI_BULLET			10
#define AI_ELEVATOR			11
#define AI_SMOKE			12
#define AI_BONUS			13
#define AI_SHOT				14
#define AI_GARAGE			15
#define AI_SPARE_SHIP			16
#define AI_HOMING_SHOT			17
#define AI_HIDDEN_AREA_ACCESS		18
#define AI_BFG_SHOT			19

#define GARAGE_WIDTH 48
#define GARAGE_HEIGHT 18

#define SHIP_TYPE_LASER			0
#define SHIP_TYPE_MACHINE_GUN		51
#define SHIP_TYPE_ROCKET_LAUNCHER	53
#define SHIP_TYPE_OBSERVER		8
#define SHIP_TYPE_BFG			55

#define BONUS_FACEBOOK			47
#define BONUS_TWITTER			48
#define BONUS_HP			52

typedef struct {
	int regenerate_bonus;
	int bonus_type;
} TEXPLOSION;

typedef struct {
	int x;
	int y;
	int i; // Sprite index
	int state;
	int cur_frame;

	unsigned char anim_speed_cnt;
	unsigned char move_speed_cnt;
	unsigned char ai_update_cnt;

	int dx;
	int dy;

	unsigned char min_frame;
	unsigned char max_frame;
	unsigned char anim_speed;
	unsigned char move_speed;
	unsigned char ai_type;

	// AI-type specific data. Just to make code a bit more readable.
	union {
		int just_created; // used by AI_SHOT, AI_HOMING_SHOT and AI_BFG_SHOT
		int ticks_passed; // used by AI_HOMING_SHOT
		int garage_inactive; // used by AI_GARAGE
		TEXPLOSION explosion; // used by AI_BONUS & AI_EXPLOSION
	};

	void *parent; /* Used by AI_CEILING_CANNON and AI_CANNON */
	void *garage; /* FIXME: recursive TSHIP *garage; */
} TSHIP;

/* FIXME: Make this local to enemies.c in future */
#define SHIPS_NUMBER 32
extern TSHIP Ships[SHIPS_NUMBER];

TSHIP *gObj_Base();
TSHIP *gObj_Ship();

TSHIP *gObj_CreateObject();
void gObj_DestroyObject(TSHIP *i);

#endif /* _ENEMIES_H_ */
