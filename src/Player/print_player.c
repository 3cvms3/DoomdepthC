/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   print_player.c                                            :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/02 20:42:53 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:16:27 by camillia             ########## ########   ######## ###########         */
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
    char* H=malloc(sizeof(char)*10);
    char d='#';
    char t='_';
    int ii=0;
    while(ii<10){
        if(ii<((player->health*10)/100)){
            strncat(H,&d,1);
            ii++;
        }else{
            strncat(H,&t,1);
            ii++;
        }
    }
    printf("\n Health: %s %d \n Mana: %d \n \n",H,player->health,player->mana);  
}

