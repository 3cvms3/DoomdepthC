/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   level.c                                                   :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 20:32:51 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:11:49 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"


void my_handle_level_up(Player *player, Monster *monsters, int monster_count, int *level) {

    printf("Félicitations! Vous avez tué tous les monstres.\n");
    (*level)++;
    printf("Niveau %d\n", *level);
    for (int i = 0; i < monster_count; i++) {
        monsters[i] = my_generate_monsters(*level); //on genere des monstres plus puissant 
    }
    my_display_monsters(monsters, monster_count);
}