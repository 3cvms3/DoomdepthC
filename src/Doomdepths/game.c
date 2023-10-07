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

void game_loop(Player *player, Monster *monsters, int monster_count, int *level) {

    while (player->health > 0) {
        printf("Player");
        my_player_turn(player, monsters, monster_count);
        if (player->health <= 0) {
            printf("Vous avez été tué par les monstres. Fin du jeu!\n");
            break;
        }
        if (my_verif_death_monsters(monsters, monster_count)) {
            my_handle_level_up(player, monsters, monster_count, level);
        }
    }
}