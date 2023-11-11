/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   attack_monster.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 15:42:47 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 21:04:57 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void my_monsters_attack(Monster **monsters, int monster_count, Player *player) {
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
    for (int i = 0; i < monster_count; i++) {
        if (monsters[i]->health > 0) {  //si le joueur est vivant le monstre attacke 
            int damage = (rand() % (monsters[i]->max_attack - monsters[i]->min_attack + 1) + monsters[i]->min_attack) - player->equipped_armor->defense;
            if (damage < 0) damage = 0;
            player->health -= damage;
            system("clear");
            for (int line = 0; line < sizeof(game_art) / sizeof(game_art[0]); line++) {
                if(line%2==0){
                    printf("%*s%s\n", diff, "", game_art[line]);
                }else{
                    printf("%*s\x1B[31m%s\033[0m\t\t\n", diff, "", game_art[line]);
                }
            }
            printf("\n%*sLe monstre \x1B[31m%d\033[0m vous retire \x1B[31m%d\033[0m points de vie . Il vous en reste \x1B[31m%d\033[0m .\n\n",diff-1,"", i+1, damage, player->health);
        }
    }
}

int my_verif_death_monsters(Monster **monsters, int monster_count) {

    for (int i = 0; i < monster_count; i++) {
        if (monsters[i]->health > 0) {
            return 0;
        }
    }
    return 1;
}