/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   print_player.c                                            :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/02 20:42:53 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/02 21:04:24 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

const char *player_art[] = {
    "    ,sSSs",
    " ,SSSS_/ ,_",
    "sS/`))\\//",
    "S//|_(\\/ ",
    "S\\\\|::\\ ",
    "SS` \\:|",
    "     \\|__",
    "     /:::\\",
    "<<<  \\:`'`"
};

void my_display_player(Player *player) {
    int diff = 1;

    for (int line = 0; line < sizeof(player_art) / sizeof(player_art[0]); line++) {
        printf("%*s%s\n", diff, "", player_art[line]);
    }

  printf("%*sH: %d, A: %d-%d, D: %d, Gold: %d, Mana: %d\n", diff, "",player->health, player->equipped_weapon.weapon_power, player->equipped_weapon.weapon_power,player->gold, player->mana);
}

