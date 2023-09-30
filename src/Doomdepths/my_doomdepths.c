/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   my_doomdepths.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/24 17:47:43 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/09/30 21:03:08 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

int Doomdepths(void)
{
    my_random();

    Monster monsters[4];
    int monster_count = my_random_monsters();
    
    for (int i = 0; i < monster_count; i++) {
        monsters[i] = my_generate_monsters();
    }
    my_display_monsters(monsters, monster_count);

    return 0;
}

int main(void)
{
    Doomdepths();
    return 0;
}

