#include "physics.h"
#include "integrator.h"
#include <stdio.h>

int main() {

	int screenWidth = 800;
	int screenHeight = 700;

	Body body_one = { 
	    .r = {450.0f, 300.0f}, 
	    .v = {0.0f, 0.3f}, 
	    .a = {0.0f, 0.0f}, 
	    .F = {0.0f, 0.0f}, 
	    .mass = 10.0f 
	};

	Body body_two = { 
	    .r = {500.0f, 350.0f}, 
	    .v = {0.0f, -0.3f}, 
	    .a = {0.0f, 0.0f}, 
	    .F = {0.0f, 0.0f}, 
	    .mass = 10.0f 
	};

	Body body_three = { 
	    .r = {720.0f, 420.0f}, 
	    .v = {-0.3f, 0.0f}, 
	    .a = {0.0f, 0.0f}, 
	    .F = {0.0f, 0.0f}, 
	    .mass = 10.0f 
	};


	Body bodies[3] = { body_one, body_two, body_three };

	InitWindow(screenWidth, screenHeight, "Three Body Problem Simulation");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		DrawCircleV(bodies[0].r, 5, RED);
		DrawCircleV(bodies[1].r, 5, GREEN);
		DrawCircleV(bodies[2].r, 5, BLUE);

		apply_force(bodies);
		euler_integration(bodies);

		EndDrawing();
	}

	CloseWindow();





	return 0;
}