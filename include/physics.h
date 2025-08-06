#ifndef __PHYSICS__
#define __PHYSICS__

#define G 10000.0f

#include "raylib.h"
#include "raymath.h"
#include <math.h>
#include <stdio.h>

typedef struct {
	Vector2 r;
	Vector2 v;
	Vector2 a;
	Vector2 F;
	float mass;

} Body;

void apply_force(Body* bodies);
void recenter_bodies(Body* bodies, int count, Vector2 screen_center);



#endif