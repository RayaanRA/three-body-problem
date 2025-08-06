#include "physics.h"
#include "integrator.h"
#include <stdio.h>

int main() {
    int screenWidth = 1200;
    int screenHeight = 800;
    Vector2 screen_center = { screenWidth / 2.0f, screenHeight / 2.0f };

    Body body_one = {
        .r = { -0.97000436f * 140.0f + screen_center.x,  0.24308753f * 140.0f + screen_center.y },
        .v = {  0.466203685f * 140.0f,  0.43236573f * 140.0f },
        .a = { 0.0f, 0.0f },
        .F = { 0.0f, 0.0f },
        .mass = 200.0f
    };

    Body body_two = {
        .r = { screen_center.x, screen_center.y },
        .v = { -0.93240737f * 140.0f, -0.86473146f * 140.0f },
        .a = { 0.0f, 0.0f },
        .F = { 0.0f, 0.0f },
        .mass = 200.0f
    };

    Body body_three = {
        .r = { 0.97000436f * 140.0f + screen_center.x, -0.24308753f * 140.0f + screen_center.y },
        .v = { 0.466203685f * 140.0f, 0.43236573f * 140.0f },
        .a = { 0.0f, 0.0f },
        .F = { 0.0f, 0.0f },
        .mass = 200.0f
    };

    Body bodies[3] = { body_one, body_two, body_three };

    InitWindow(screenWidth, screenHeight, "Three Body Problem Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        leapfrog_integration(bodies);

        recenter_bodies(bodies, 3, screen_center);

        DrawCircleV(bodies[0].r, 5, RED);
        DrawCircleV(bodies[1].r, 5, GREEN);
        DrawCircleV(bodies[2].r, 5, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
