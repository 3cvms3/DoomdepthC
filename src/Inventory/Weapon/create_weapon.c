/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   create_weapon.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 10:46:22 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 10:46:22 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

Weapon *create_weapon() {
    static const char *weapon_names[] = {"Sword", "Axe", "Spear", "Bow", "Dagger"};
    static const int weapon_count = sizeof(weapon_names) / sizeof(weapon_names[0]);
    
    srand(time(NULL));

    Weapon *weapon = malloc(sizeof(Weapon));

    int random_index = rand() % weapon_count;
    weapon->name = strdup(weapon_names[random_index]);

    weapon->min_damage = rand() % 10 + 1;
    weapon->max_damage = rand() % 15 + 5;
    weapon->number_of_attacks = rand() % 4 + 1;

    return weapon;
}