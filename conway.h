#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define ROWS 18
#define COLS 36

int front[ROWS][COLS] = {0};
int back[ROWS][COLS] = {0};

void conwayDisplay() {
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            if (front[y][x]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int mod(int a, int b) {
    return (a % b + b) % b;
}

int count_nbors(int cx, int cy) {
    int nbors = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (!(dx == 0 && dy == 0)) {
                int x = mod(cx + dx, COLS);
                int y = mod(cy + dy, ROWS);
                if (front[y][x]) nbors += 1;
            }
        }
    }
    return nbors;
}

void conwayNext(void) {
    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            int nbors = count_nbors(x, y);
            back[y][x] = front[y][x] ? (nbors == 2 || nbors == 3) : nbors == 3;
        }
    }
}

int conway() {
    int sRows, sCols, pix;
	int glider = 000;

    printf("How many pixels: ");
    scanf("%d", &pix);
	if (pix == glider) {
		front[0][1] = 1;
		front[1][2] = 1;
		front[2][0] = 1;
		front[2][1] = 1;
		front[2][2] = 1;
	} else {
		for (int i = 0; i < pix; ++i) {
			printf("Enter [Row] [Col]: ");
			scanf("%d %d", &sRows, &sCols);
			if (sRows >= 0 && sRows < ROWS && sCols >= 0 && sCols < COLS) {
				front[sRows][sCols] = 1;
			} else {
				printf("Invalid coordinates. Try again.\n");
				--i;
			}
		}
	}

    for (;;) {
        conwayDisplay();
        conwayNext();
        memcpy(front, back, sizeof(front));
		printf("\033[%dA\033[%dD", ROWS, COLS);
        usleep(100 * 1000);
    }
    return 0;
}
