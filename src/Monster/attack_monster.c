/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_monster.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:42:47 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 21:04:57 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void my_monsters_attack(Monster *monsters, int monster_count, Player *player) {
    
    for (int i = 0; i < monster_count; i++) {
        if (monsters[i].health > 0) {  //si le joueur est vivant le monstre attacke 
            int damage = (rand() % (monsters[i].max_attack - monsters[i].min_attack + 1) + monsters[i].min_attack) - player->equipped_weapon.weapon_power;
            if (damage < 0) damage = 0;
            player->health -= damage;
            printf("Le monstre %d inflige %d dégâts au joueur. Il reste %d points de vie au joueur.\n", i, damage, player->health);
        }
    }
}

int my_verif_death_monsters(Monster *monsters, int monster_count) {

    for (int i = 0; i < monster_count; i++) {
        if (monsters[i].health > 0) {
            return 0;
        }
    }
    return 1;
}