#include "physics.h"

Vector2 compute_force(Body a, Body b);

Vector2 compute_force(Body a, Body b) {
    Vector2 d = Vector2Subtract(a.r, b.r);
    float r = Vector2Length(d);
    float f_mag = (-G * a.mass * b.mass) / (r * r * r);
    return Vector2Scale(d, f_mag);
}


void apply_force(Body* bodies) {

	for (int i = 0; i < 3; i++) {
		bodies[i].F = (Vector2){0, 0};
		for (int j = 0; j < 3; j++) {
    		if (i == j) continue;
    		bodies[i].F = Vector2Add(bodies[i].F, compute_force(bodies[i], bodies[j]));
		}
	}
}