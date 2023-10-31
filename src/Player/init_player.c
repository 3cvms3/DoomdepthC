/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   init_player.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/02 19:06:45 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 15:24:26 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

Player *init_player(Floor *floor) {
    Player *player = malloc(sizeof(Player));
    player->health_deb=100;
    player->health = 100;
    player->mana = 100;

    player->position.current_floor = floor;
    player->position.current_room = floor->rooms[0];

    player->equipped_weapon = create_weapon();
    player->number_of_attacks = player->equipped_weapon->number_of_attacks;
    player->equipped_armor = create_armor();
    player->inventory = init_inventory();

    return player;
}