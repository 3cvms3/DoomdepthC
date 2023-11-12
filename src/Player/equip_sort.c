/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   equip_sort.c                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 12:48:26 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 20:58:47 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void equip_sort(Sort *sort, Player *player) {
    remove_sort(sort, player->inventory);
    if (player->equipped_sort != NULL) {
        add_sort(player->equipped_sort, player->inventory);
    }
    player->equipped_sort = sort;
}
