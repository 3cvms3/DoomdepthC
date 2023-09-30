/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   random.c                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/30 15:21:57 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/09/30 15:43:15 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

//Génère un nombre entre 1 et 3 inclus
int my_random_monsters() {
    return rand() % 3 + 1; //+ 1 pour que sa soit bien entre 1 et 3 sinon sa serai que de 0 et 3
}


Monster my_generate_monsters() {

    Monster enemies;

    enemies.health = rand() % 100 + 1;
    enemies.min_attack = rand() % 10 + 1;
    enemies.max_attack = rand() % 20 + enemies.min_attack;
    enemies.defense = rand() % 10 + 1;

    return enemies;
}

