#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#include "dino.h"
#include "logic.h"
#include "platform.h"
#include "obstacle.h"
#include "collectable.h"
#include "background.h"

#define FPS 60
#define WIDTH 800
#define HEIGHT 456
#define TITLE "Speedy Dino"
#define GRAVITY 50
#define PLATFORM_HEIGHT 456 - 64 + 4
#define SIZE_MULTIPLIER 4
#define SPEED_INCREASER 0.01f

extern float score;
extern bool lose;
extern bool begin;

void start(); // funcs
void update();
void late_update();
void finish();

void replay();

#endif