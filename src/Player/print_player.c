/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   print_player.c                                            :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 8:45:12 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:03:20 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */


#include "Doomdepths.h"

const char *player_art[] = {
    "\x1B[32m    ,sSSs\033[0m",
    "\x1B[32m ,SSSS_/ ,_\033[0m",
    "\x1B[32msS/`))\\//\033[0m",
    "\x1B[32mS//|_(\\/ \033[0m",
    "\x1B[32mS\\\\|::\\ \033[0m",
    "\x1B[32mSS` \\:|\033[0m",
    "\x1B[32m     \\|__\033[0m",
    "\x1B[32m     /:::\\\033[0m",
    "\x1B[32m<<<  \\:`'`\033[0m"
};


void my_display_player(Player *player) {
    int diff = 10;

    printf("\n");
    for (int line = 0; line < sizeof(player_art) / sizeof(player_art[0]); line++) {
        printf("\t%s\n", player_art[line]);
    }
    
    printf("\n");

    char H[11];
    char d = '#';
    char t = '_';

    for (int ii = 0; ii < 10; ii++) {
        if (ii < ((player->health * 10) / 100)) {
            H[ii] = d;
        } else {
            H[ii] = t;
        }
    }

    H[10] = '\0';

    printf("\x1B[1m\x1B[31mHealth:\033[0m %s %d\n\x1B[1m\x1B[31mMana:\033[0m %d\n", H, player->health, player->mana);
    printf("\n\x1B[32m\x1B[1mEquipped:\033[0m\n");

    if (player->equipped_weapon) {
        printf("\x1B[32m\x1B[33m\x1B[1mWeapon:\033[0m %s\n", player->equipped_weapon->name);
    }

    if (player->equipped_armor) {
        printf("\x1B[32m\x1B[33m\x1B[1mArmor:\033[0m %s\n", player->equipped_armor->name);
    }

    if (player->equipped_sort) {
        printf("\x1B[32m\x1B[33m\x1B[1mSort:\033[0m %s\n", player->equipped_sort->name);
    }
}
