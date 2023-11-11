/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_player.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:38:39 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 15:38:39 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"


void my_player_attack(Player *player, Monster *monster) {
    int diff = 40;
    const char *game_art[] = {
" ___     ___    ___   ___ ___  ___      ___  ____  ______  __ __  _____",

"|   \\   /   \\  /   \\ |   T   T|   \\    /  _]|    \\|      T|  T  T/ ___/",

"|    \\ Y     YY     Y| _   _ ||    \\  /  [_ |  o  )      ||  l  (   \\_ ",

"|  D  Y|  O  ||  O  ||  \\_/  ||  D  YY    _]|   _/l_j  l_j|  _  |\\__  T",

"|     ||     ||     ||   |   ||     ||   [_ |  |    |  |  |  |  |/  \\ |",

"|     |l     !l     !|   |   ||     ||     T|  |    |  |  |  |  |\\    |",

"l_____j \\___/  \\___/ l___j___jl_____jl_____jl__j    l__j  l__j__j \\___j",

};
    int damage = 10;
    if (damage < 0) damage = 0;
        monster->health -= damage;
        system("clear");
        for (int line = 0; line < sizeof(game_art) / sizeof(game_art[0]); line++) {
        if(line%2==0){
            printf("%*s%s\n", diff, "", game_art[line]);
        }else{
            printf("%*s\x1B[31m%s\033[0m\t\t\n", diff, "", game_art[line]);
        }
    }
    if (monster->health <= 0){
        monster->health = 0;
        printf("\n%*sEt hop ! Un monstre en moins , continue comme ça .\n\n",diff,"");
    }else{
        printf("\n%*sSuperbe attaque , tu retires \x1B[31m%d\033[0m points de vie à ce monstre . Plus que \x1B[31m%d\033[0m à lui en retirer encore. . .\n\n",30,"" ,damage, monster->health);
    }
    }
    
