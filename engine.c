#include <stdlib.h>
#include "conway.h"

int main() {
    int gameChoices;
    
    for(;;) {
        system("clear");
        printf("Games:\n");
        printf("1) Conway\n\n");
        printf("> ");
        scanf("%d", &gameChoices);

        switch(gameChoices) {
            case 1:
                conway();
            default:
                exit(1);
        }
    }
    return 0;
}
