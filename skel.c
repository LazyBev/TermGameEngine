#include "engine.h"

void gameLoop() {
    Engine engine;
    initEngine(&engine);

    saveCursor();
    for(;;) {
        display(&engine, ROWS, COLS);
        loadCursor();
        delay(100 * 1000);
    }
}

int main() {
    gameLoop();
    
    return 0;
}
