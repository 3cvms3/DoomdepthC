#include "Doomdepths.h"

void display_floors(Floor *last_floor, Position *player_pos) {
    system("clear");
    printf("==[ MAP ]==\n\n");

    reverse_display_floors(last_floor, player_pos);

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\n0. Exit map\n");
    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    switch(choice) {
        case 0:
            break;
        default:
            display_floors(last_floor, player_pos);
            break;
    }
}