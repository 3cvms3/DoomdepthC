/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   random_monsters.c                                         :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/30 15:21:57 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 17:23:44 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

Monster my_generate_monsters(int level) {

    Monster enemy;
    
    enemy.health = (rand() % 100 + 1) * level;
    enemy.min_attack = (rand() % 10 + 1) * level;
    enemy.max_attack = (rand() % 20 + enemy.min_attack) * level;
    enemy.defense = (rand() % 10 + 1) * level;

    return enemy;
}


