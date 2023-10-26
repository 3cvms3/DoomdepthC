/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_player.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:38:39 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 15:38:39 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"


void my_player_attack(Player *player, Monster *monster) {

    int damage = 10;

    if (damage < 0) damage = 0;
        monster->health -= damage;

    if (monster->health < 0) monster->health = 0;
        printf("Le joueur inflige %d dégâts au monstre. Il reste %d points de vie au monstre.\n", damage, monster->health);
}
