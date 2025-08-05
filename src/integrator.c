	#include "integrator.h"

	const float h = 0.01f;

	void euler_integration(Body* bodies) {
		for (int i = 0; i < 3; i++) {
			bodies[i].a.x = bodies[i].F.x / bodies[i].mass;
			bodies[i].a.y = bodies[i].F.y / bodies[i].mass;

			bodies[i].v = Vector2Add(bodies[i].v, Vector2Scale(bodies[i].a, h));
			bodies[i].r = Vector2Add(bodies[i].r, Vector2Scale(bodies[i].v, h));
		}
	}