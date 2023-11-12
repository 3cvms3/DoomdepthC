/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   player_turn.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 20:29:25 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:36:08 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void my_player_turn(Player *player, Monster **monsters, int monster_count) {

    char prompt_choice;
    int choice;

    // on  clear
    printf("\x1B[2J\x1B[H");

    my_display_monsters(monsters, monster_count);
    my_display_player(player);

    printf("\n\x1B[31mIt's your turn!\033[0m You have \x1B[31m%d\033[0m attacks remaining this turn.\n", player->number_of_attacks);
    printf("\x1B[31m1.\033[0m Attack a monster\n");
    printf("\x1B[31m2.\033[0m End your turn\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0'); //convertis le choix de l'user (caractère) en entier 

    if (choice == 1 && player->number_of_attacks > 0) {

        char prompt_target;
        int target;

        printf("Which monster do you want to attack (1-%d)? ", monster_count);
        scanf(" %c", &prompt_target);
        target = (int)(prompt_target - '0');
        target--;
        
        //on verifie si la cible est valide et le monstre est vivant
        if (target >= 0 && target < monster_count && monsters[target]->health > 0) {

            //on effectue l'attaque du joueur
            my_player_attack(player, monsters[target]);
            player->number_of_attacks--;
            
            printf("\x1B[2J\x1B[H");
            my_display_monsters(monsters, monster_count);
            printf("\n");
            my_display_player(player);
        } else {
            printf("\x1B[31mInvalid monster!\033[0m\n");
        }
    }

    if (choice == 2 || player->number_of_attacks == 0) {
        my_monsters_attack(monsters, monster_count, player);
        printf("\x1B[2J\x1B[H");
        my_display_monsters(monsters, monster_count);
        printf("\n");
        my_display_player(player);
        player->number_of_attacks = 2;
    }
}
