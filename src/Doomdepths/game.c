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
    int diff = 40;
    const char *game_art[] = {
" ___     ___    ___   ___ ___  ___      ___  ____  ______  __ __  _____",

"|   \\   /   \\  /   \\ |   T   T|   \\    /  _]|    \\|      T|  T  T/ ___/",

"|    \\ Y     YY     Y| _   _ ||    \\  /  [_ |  o  )      ||  l  (   \\_ ",

"|  D  Y|  O  ||  O  ||  \\_/  ||  D  YY    _]|   _/l_j  l_j|  _  |\\__  T",

"|     ||     ||     ||   |   ||     ||   [_ |  |    |  |  |  |  |/  \\ |",

"|     |l     !l     !|   |   ||     ||     T|  |    |  |  |  |  |\\    |",

"l_____j \\___/  \\___/ l___j___jl_____jl_____jl__j    l__j  l__j__j \\___j",

};
    while (player->health > 0) {
        system("clear");
        for (int line = 0; line < sizeof(game_art) / sizeof(game_art[0]); line++) {
            if(line%2==0){
                printf("%*s%s\n", diff, "", game_art[line]);
            }else{
                printf("%*s\x1B[31m%s\033[0m\t\t\n", diff, "", game_art[line]);
            }
        }
                printf("%*s Please select one of the below options\n",diff, "");
                printf("%*s \x1B[31m1.\033[0m Move to next room\n",diff, "");
                printf("%*s \x1B[31m2.\033[0m Open your inventory\n",diff, "");
                printf("%*s \x1B[31m3.\033[0m Open your map\n",diff, "");
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
                printf("\n\x1B[31mPlease choose between available options\033[0m\n");
                break;
        }
    }
}