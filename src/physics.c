#include "physics.h"

Vector2 compute_force(Body a, Body b) {
    Vector2 d = Vector2Subtract(b.r, a.r);
    float eps = 1.0f;
    float r = Vector2Length(d);
    float softened = r*r + eps*eps;
    float f_mag = (G * a.mass * b.mass) / (softened * sqrtf(softened));
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

void recenter_bodies(Body* bodies, int count, Vector2 screen_center) {
    Vector2 com = {0, 0};
    float total_mass = 0.0f;
    for (int i = 0; i < count; i++) {
        com.x += bodies[i].r.x * bodies[i].mass;
        com.y += bodies[i].r.y * bodies[i].mass;
        total_mass += bodies[i].mass;
    }
    com.x /= total_mass;
    com.y /= total_mass;

    Vector2 offset = Vector2Subtract(screen_center, com);
    for (int i = 0; i < count; i++) {
        bodies[i].r = Vector2Add(bodies[i].r, offset);
    }
}
