/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_player.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:38:39 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:34:36 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"


void my_player_attack(Player *player, Monster *monster) {
    int diff = 40;
    const char *game_art[] = {
};

    int damage = 0;
    const int MANA_COST = 15; //le coût en mana pour utiliser un sort, peut plus etre modifier

    //on verifie si le joueur a un sort d'attack et assez de mana
    if (player->equipped_sort != NULL && player->equipped_sort->type == OFFENSIVE && player->mana >= MANA_COST) {
        damage = player->equipped_sort->power; // Utiliser la puissance du sort comme dégâts
        player->mana -= MANA_COST; // Réduire la mana du joueur
    } else if (player->equipped_weapon != NULL) {
        //si plus de mana ou plus de sorts on utilise l'arme
        damage = rand() % (player->equipped_weapon->max_damage - player->equipped_weapon->min_damage + 1) + player->equipped_weapon->min_damage;
    } else {
        damage = 10;
    }
    
    if (damage < 0) damage = 0;
    monster->health -= damage;

    if (monster->health <= 0) {
        monster->health = 0;
        printf("\n%*sEt hop ! Un monstre en moins, continue comme ça.\n\n", diff, "");
    } else {
        printf("\n%*sSuperbe attaque, tu retires \x1B[31m%d\033[0m points de vie à ce monstre. Plus que \x1B[31m%d\033[0m à lui en retirer encore...\n\n", 30, "", damage, monster->health);
    }
}

