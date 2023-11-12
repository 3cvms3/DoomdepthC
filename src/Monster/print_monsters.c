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
    "    \\/ ||    ||     "};
struct inf_en
{
    int Health;
    int Health_deb;
    int Attackmin;
    int Attackmax;
    int Defense;
};
void my_display_monsters(Monster **enemies, int count)
{
    int diff = 40;
    struct inf_en tabn[count];
    int cnt = 0;
    if(count>0){
    for (int i = 0; i < count; i++)
    {
        if (enemies[i]->health > 0)
        {
            tabn[cnt].Health = enemies[i]->health;
            tabn[cnt].Attackmin = enemies[i]->min_attack;
            tabn[cnt].Attackmax = enemies[i]->max_attack;
            tabn[cnt].Defense = enemies[i]->defense;
            tabn[cnt].Health_deb = enemies[i]->health_deb;
            cnt++;
        }
    }
    // SYSTEME D'AFFICHAGE HORIZONTAL
    for (int line = 0; line < ASCII_LINES_M; line++)
    {
        printf("%*s", (int)(diff + (strlen(monster_art[0]) + 1)), "");
        for (int g = 0; g < cnt; g++)
        {
            if (tabn[g].Health > 0)
            {
                printf("%s        ", monster_art[line]);
            }
        }
        printf("\n");
        if (line == ASCII_LINES_M - 1)
        {
            printf("%*s", (int)(diff + (strlen(monster_art[0]) + 1)), "");
            for (int g = 0; g < cnt; g++)
            {
                char *H = malloc(sizeof(char) * 10);
                char d = '#';
                char t = '_';
                int ii = 0;
                while (ii < 10)
                {
                    if (ii < ((tabn[g].Health * 10) / tabn[g].Health_deb))
                    {
                        strncat(H, &d, 1);
                        ii++;
                    }
                    else
                    {
                        strncat(H, &t, 1);
                        ii++;
                    }
                }
                printf("\x1B[31mHealth: \033[0m%d %s", tabn[g].Health, H);
                printf("%*s", (int)(9), "");
            }
            printf("\n");
            printf("%*s", (int)(diff + (strlen(monster_art[0]) + 1)), "");
            for (int g = 0; g < cnt; g++)
            {
                printf("\x1B[31mAttack: \033[0m%d(Min)-%d(Max)", tabn[g].Attackmin, tabn[g].Attackmax);
                printf("%*s", (int)(9), "");
            }
            printf("\n");
            printf("%*s", (int)(diff + (strlen(monster_art[0]) + 1)), "");
            for (int g = 0; g < cnt; g++)
            {
                printf("\x1B[31mProtection: \033[0m%d ", tabn[g].Defense);
                printf("%*s", (int)(17), "");
            }
        }
    }
}else{
    printf("Bravo , nouvelle chambre debloquee ");
}
}