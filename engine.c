#include <stdlib.h>
#include "conway.h"

int main() {
    int gameChoice;

    for(;;) {
        system("clear");
        printf("Games:\n");
        printf("1) Conway\n\n");
        printf("> ");
        scanf("%d", gameChoice);

        switch(gameChoice) {
            case 1:
                conway();
            default:
                exit(1);
        }
    }
    return 0;
}