/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   game.c                                                    :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:44:05 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:22:56 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */


#include "Doomdepths.h"

void game_loop(Floor *last_floor, Player *player) {
    while (player->health > 0) {
        system("clear");

        printf("Please select one of the below options\n");
        printf("1. Move to next room\n");
        printf("2. Open your inventory\n");
        printf("3. Open your map\n");

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
                    fight_loop(player, player->position.current_room);
                }
                break;
            case 2:
                display_inventory(player->inventory);
                break;
            case 3:
                display_floors(last_floor, &player->position);
                break;
            default:
                printf("\nPlease choose between available options\n");
                break;
        }
    }
}