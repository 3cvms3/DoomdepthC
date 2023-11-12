/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   game.c                                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:44:05 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:38:00 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */


#include "Doomdepths.h"

void printMenu() {
    
    printf("\n");

    printf("\n\n\x1B[33m****************** MAIN MENU ******************\033[0m\n");
    printf("------------------------------------------------\n");

    printf("\x1B[32m1. Move to next room\033[0m\n");
    printf("\x1B[34m2. Open your inventory\033[0m\n");
    printf("\x1B[35m3. Open your map\033[0m\n");

    printf("------------------------------------------------\n\n");
}

void game_loop(Floor *last_floor, Player *player) {
    int diff = 0;
    const char *game_art[] = {
    "████████▄   ▄██████▄   ▄██████▄    ▄▄▄▄███▄▄▄▄   ████████▄     ▄████████    ▄███████▄     ███        ▄█    █▄       ▄████████",
    "███   ▀███ ███    ███ ███    ███ ▄██▀▀▀███▀▀▀██▄ ███   ▀███   ███    ███   ███    ███ ▀█████████▄   ███    ███     ███    ███",
    "███    ███ ███    ███ ███    ███ ███   ███   ███ ███    ███   ███    █▀    ███    ███    ▀███▀▀██   ███    ███     ███    █▀",
    "███    ███ ███    ███ ███    ███ ███   ███   ███ ███    ███  ▄███▄▄▄       ███    ███     ███   ▀  ▄███▄▄▄▄███▄▄   ███",
    "███    ███ ███    ███ ███    ███ ███   ███   ███ ███    ███ ▀▀███▀▀▀     ▀█████████▀      ███     ▀▀███▀▀▀▀███▀  ▀███████████",
    "███    ███ ███    ███ ███    ███ ███   ███   ███ ███    ███   ███    █▄    ███            ███       ███    ███            ███",
    "███   ▄███ ███    ███ ███    ███ ███   ███   ███ ███   ▄███   ███    ███   ███            ███       ███    ███      ▄█    ███",
    "████████▀   ▀██████▀   ▀██████▀   ▀█   ███   █▀  ████████▀    ██████████  ▄████▀         ▄████▀     ███    █▀     ▄████████▀"

    };
    while (player->health > 0) {
        system("clear");
        for (int line = 0; line < sizeof(game_art) / sizeof(game_art[0]); line++) {
            printf("%*s\x1B[38;5;52m%s\033[0m\t\t\n", diff, "", game_art[line]);
        }
        printMenu(0);
        char prompt_choice;
        int choice;

        scanf(" %c", &prompt_choice);
        choice = (int)(prompt_choice - '0');

        switch (choice) {
            case 1:
                if (player->position.current_room->has_stairs) {
                    last_floor = add_floor(last_floor);
                    change_floor(last_floor, &player->position, last_floor->floor_number);
                } else {
                    change_room(&player->position);
                }
                /* On lance le combat si la salle suivante n'est pas vide */
                if (player->position.current_room->number_of_monsters > 0) {
                    system("clear");
                    fight_loop(player, player->position.current_room);
                }
                break;
            case 2:
                display_player_inventory(player);
                break;
            case 3:
                display_floors(last_floor, &player->position);
                break;
            default:
                printf("\n\x1B[31mPlease choose between available options\033[0m\n");
                break;
        }
    }
}