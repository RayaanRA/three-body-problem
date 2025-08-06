#include "integrator.h"

const float h = 0.005f;

void euler_integration(Body* bodies) {
	for (int i = 0; i < 3; i++) {
		bodies[i].a.x = bodies[i].F.x / bodies[i].mass;
		bodies[i].a.y = bodies[i].F.y / bodies[i].mass;

		bodies[i].v = Vector2Add(bodies[i].v, Vector2Scale(bodies[i].a, h));
		bodies[i].r = Vector2Add(bodies[i].r, Vector2Scale(bodies[i].v, h));
	}
}

void leapfrog_integration(Body *bodies) {
    apply_force(bodies);

    for (int i = 0; i < 3; i++) {
        bodies[i].a.x = bodies[i].F.x / bodies[i].mass;
        bodies[i].a.y = bodies[i].F.y / bodies[i].mass;
    }

    for (int i = 0; i < 3; i++) {
        bodies[i].r.x += bodies[i].v.x * h + 0.5f * bodies[i].a.x * h * h;
        bodies[i].r.y += bodies[i].v.y * h + 0.5f * bodies[i].a.y * h * h;
    }

    apply_force(bodies);

    for (int i = 0; i < 3; i++) {
        float prevAx = bodies[i].a.x;
        float prevAy = bodies[i].a.y;

        bodies[i].a.x = bodies[i].F.x / bodies[i].mass;
        bodies[i].a.y = bodies[i].F.y / bodies[i].mass;

        bodies[i].v.x += 0.5f * (prevAx + bodies[i].a.x) * h;
        bodies[i].v.y += 0.5f * (prevAy + bodies[i].a.y) * h;
    }
}

