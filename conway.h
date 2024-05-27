#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define ROWS 16
#define COLS 32

int front[ROWS][COLS] = {0};
int back[ROWS][COLS] = {0};

void conwayDisplay() {
	for(int y = 0; y < ROWS; ++y) {
		for(int x = 0; x < COLS; ++x) {
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
	return (a%b + b)%b;
}

int count_nbors(int cx, int cy) {
	int nbors = 0;
	for(int dx = -1; dx <= 1; ++dx) {
		for(int dy = -1; dy <= 1; ++dy) {
			if(!(dx == 0 && dy == 0)) {
				int x = mod(cx + dx, COLS);
				int y = mod(cy + dy, ROWS);
				if (front[y][x]) nbors += 1;
			}
		}
	}
	return nbors;
}

void conwayNext(void) {
	for(int y = 0; y < ROWS; ++y) {
		for(int x = 0; x < COLS; ++x) {
			int nbors = count_nbors(x, y);
			back[y][x] = front[y][x] ? (nbors == 2 || nbors == 3) : nbors == 3;
		}
	}

}

int conway() {
	front[0][1] = 1;
	front[1][2] = 1;
	front[2][0] = 1;
	front[2][1] = 1;
	front[2][2] = 1;
	for(;;) {
		conwayDisplay();
		conwayNext();
		memcpy(front, back, sizeof(front));
		printf("\033[%dA\033[%dD", ROWS, COLS);
		usleep(100*1000);
	}
	return 0;
}