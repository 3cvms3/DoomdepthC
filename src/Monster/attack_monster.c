/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_monster.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:42:47 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 20:52:31 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void my_monsters_attack(Monster **monsters, int monster_count, Player *player) {
    int diff = 40;
    const char *game_art[] = {
};
    for (int i = 0; i < monster_count; i++) {
            if (monsters[i]->health > 0) {
                int damage = rand() % (monsters[i]->max_attack - monsters[i]->min_attack + 1) + monsters[i]->min_attack;

                // On utilise le sort de soin pour réduire les dégâts, sinon l'armure
                if (player->equipped_sort != NULL && player->equipped_sort->type == HEALING) {
                    damage -= player->equipped_sort->power; // Réduit les dégâts en fonction de la puissance du sort
                } else if (player->equipped_armor != NULL) {
                    damage -= player->equipped_armor->defense; // Réduit les dégâts par la défense de l'armure
                }
                if (damage < 0) damage = 0;
                player->health -= damage;
                system("clear");
                printf("\n%*sLe monstre \x1B[31m%d\033[0m vous retire \x1B[31m%d\033[0m points de vie. Il vous en reste \x1B[31m%d\033[0m.\n\n", diff-1, "", i+1, damage, player->health);
            }
        }
}

int my_verif_death_monsters(Monster **monsters, int monster_count, Inventory *player_inventory) {

    int all_monsters_dead = 1;
    
    for (int i = 0; i < monster_count; i++) {
        if (monsters[i]->health > 0) {
            all_monsters_dead = 0;
        } else {
            int reward_choice = rand() % 4;
            switch (reward_choice) {
                case 0: {
                    Weapon *new_weapon = create_weapon();
                    add_weapon(new_weapon, player_inventory);
                    break;
                }
                case 1: {
                    Weapon *weapon_to_sell = create_weapon();
                    sell_weapon(weapon_to_sell, player_inventory);
                    break;
                }
                case 2: {
                    Armor *new_armor = create_armor();
                    add_armor(new_armor, player_inventory);
                    break;
                }
                case 3: {
                    Sort *new_sort = create_sort();
                    add_sort(new_sort, player_inventory);
                    break;
                }
            }
        }
    }
    return all_monsters_dead;
}


