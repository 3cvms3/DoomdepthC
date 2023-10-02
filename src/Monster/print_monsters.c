/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   print_monsters.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/30 16:07:12 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/02 18:52:11 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

const char *monster_art[] = {
    " <=======]}======   ",
    "    --.   /|        ",
    "   _\"/_.'|         ",
    " .'._._,.|          ",
    " :/ \\{}/           ",
    "(L  /--',----._     ",
    "    |          \\    ",
    "   : /-\\ .'-'| |   ",
    "   \\, ||    \\|     ",
    "    \\/ ||    ||     "
};

void my_display_monsters(Monster *enemies, int count) {
    int diff = 25;

    for (int i = 0; i < count; i++) {
        for (int line = 0; line < ASCII_LINES_M; line++) {
            printf("%*s%s\n", (int)(diff + i * (strlen(monster_art[0]) + 1)), "", monster_art[line]);
        }
        printf("%*sH: %d, A: %d-%d, D: %d\n", (int)(diff + i * (strlen(monster_art[0]) + 1)), "", enemies[i].health, enemies[i].min_attack, enemies[i].max_attack, enemies[i].defense);
    }
}
