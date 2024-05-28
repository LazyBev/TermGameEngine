#include "engine.h"

void saveCursor() {
    printf("\0337");
}

void loadCursor() {
    printf("\0338");
}

void display(Engine* engine, int Rows, int Cols) {
    if (!isnan(engine->r) && !isnan(engine->c)) {
        for (int y = 0; y < Rows; ++y) {
            for (int x = 0; x < Cols; ++x) {
                if (engine->front[y][x]) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    } else {
        fprintf(stderr, "ERROR: Init engine: initEngine();");
    }
}

int mod(int a, int b) {
    return (a % b + b) % b;
}

int delay(int seconds) {
    return usleep(seconds);
}

void initEngine(Engine* engine) {
    system("clear");
    engine->r = ROWS;
    engine->c = COLS;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            engine->front[i][j] = 0;
            engine->back[i][j] = 0;
        }
    }
}
