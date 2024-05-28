#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 18
#define COLS 36

typedef struct Engine {
    double r, c;
    int front[ROWS][COLS];
    int back[ROWS][COLS];
} Engine;

void saveCursor();
void loadCursor();
void display(Engine* engine, int Rows, int Cols);
int mod(int a, int b);
int delay(int seconds);
void initEngine(Engine* engine);

#endif // ENGINE_H
