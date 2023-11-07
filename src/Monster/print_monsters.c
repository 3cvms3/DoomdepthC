/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   print_monsters.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/30 16:07:12 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 17:16:12 by camillia             ########## ########   ######## ###########         */
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

void my_display_monsters(Monster **enemies, int count) {
    
    int diff = 25;

    for (int i = 0; i < count; i++) {
        if (enemies[i]->health > 0) {  //on affiche que les monstres qui sont en vie 
            for (int line = 0; line < ASCII_LINES_M; line++) {
                printf("%*s%s\n", (int)(diff + i * (strlen(monster_art[0]) + 1)), "", monster_art[line]);
            }
            char* H=malloc(sizeof(char)*10);
            char d='#';
            char t='_';
            int ii=0;
            while(ii<10){
                if(ii<((enemies[i]->health*10)/enemies[i]->health_deb)){
                    strncat(H,&d,1);
                    ii++;
                }else{
                    strncat(H,&t,1);
                    ii++;
                }
            }
            
            printf("\n %*sHealth: %d %s \n %*sAttack: %d(Min)-%d(Max) \n %*sProtection: %d \n", (int)(diff + i * (strlen(monster_art[0]) + 1)), "", enemies[i]->health,H, (int)(diff + i * (strlen(monster_art[0]) + 1)), "",enemies[i]->min_attack, enemies[i]->max_attack, (int)(diff + i * (strlen(monster_art[0]) + 1)), "", enemies[i]->defense);
        }
    }
}

