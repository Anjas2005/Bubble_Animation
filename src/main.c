#include "raylib.h"
#include "resource_dir.h"

// Define the number of balls i want on screen
#define MAX_BALLS 20

// 1.Create a "BluePrint" for what makes a Ball
typedef struct Ball {
  int x, y;
  int speedX, speedY;
  int radius;
  Color color;
} Ball;

int main() {
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

  int screenWidth = 1280;
  int screenHeight = 800;

  // Create the Window
  InitWindow(screenWidth, screenHeight, "Multiple Bouncing Balls");

  SearchAndSetResourceDir("resources");

  // 2. Create an Array to hold all our Balls
  Ball balls[MAX_BALLS];

  // Array of colors to pick from randomly
  Color colors[5] = {RED, ORANGE, PURPLE, GREEN, DARKBLUE};
  // 3. Initialize every ball with random starting values
  for (int i = 0; i < MAX_BALLS; i++) {
    balls[i].radius = GetRandomValue(20, 50);

    // Spawn them randomly inside the screen limits
    balls[i].x = GetRandomValue(balls[i].radius, screenWidth - balls[i].radius);
    balls[i].y =
        GetRandomValue(balls[i].radius, screenHeight - balls[i].radius);

    // Random speed between 3 and 8
    balls[i].speedX = GetRandomValue(3, 8);
    balls[i].speedY = GetRandomValue(3, 8);

    // 50% chance to flip direction so they don't all go the same way
    if (GetRandomValue(0, 1) == 1) balls[i].speedX *= -1;
    if (GetRandomValue(0, 1) == 1) balls[i].speedY *= -1;

    // Assign a color from our array based on the index
    balls[i].color = colors[i % 5];
  }

  // game loop
  while (!WindowShouldClose()) {
    // ==========================================
    // UPDATE: Physics & Logic
    // ==========================================

    // Loop through every single ball and apply physics
    for (int i = 0; i < MAX_BALLS; i++) {
      // Move the ball
      balls[i].x += balls[i].speedX;
      balls[i].y += balls[i].speedY;

      // Bounce of Walls
      if ((balls[i].x + balls[i].radius >= screenWidth) ||
          (balls[i].x - balls[i].radius <= 0)) {
        balls[i].speedX *= -1;
      }
      if ((balls[i].y + balls[i].radius >= screenHeight) ||
          (balls[i].y - balls[i].radius <= 0)) {
        balls[i].speedY *= -1;
      }
    }

    // ==========================================
    // DRAW: Rendering
    // ==========================================
    BeginDrawing();
    ClearBackground(SKYBLUE);

    // Loop thorugh every ball and draw it to the screen
    for (int i = 0; i < MAX_BALLS; i++) {
      DrawCircle(balls[i].x, balls[i].y, balls[i].radius, balls[i].color);
    }

    DrawText("Look at them go!", 20, 20, 20, WHITE);

    EndDrawing();
  }

  // CleanUP
  CloseWindow();
  return 0;
}
