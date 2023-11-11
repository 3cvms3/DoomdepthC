/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   player_turn.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/07 20:29:25 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:16:17 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void my_player_turn(Player *player, Monster **monsters, int monster_count) {
    system("clear");
    my_display_monsters(monsters, monster_count);
    my_display_player(player);
    
    char prompt_choice;
    int choice;
    // my_display_monsters(monsters, monster_count);
    // my_display_player(player);
    printf("C'est votre tour! Vous avez \x1B[31m%d\033[0m attaques restantes ce tour.\n", player->number_of_attacks);
    printf("\x1B[31m1.\033[0m Attaquer un monstre\n");
    printf("\x1B[31m2.\033[0m Terminer le tour\n");
    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (choice == 1 && player->number_of_attacks > 0) {
        
        char prompt_target;
        int target;
        printf("Quel monstre voulez-vous attaquer (1-%d)? ", monster_count);
        scanf(" %c", &prompt_target);
        target = (int)(prompt_target - '0');
        target--;
        if (target >= 0 && target < monster_count && monsters[target]->health > 0) {
            my_player_attack(player, monsters[target]);
            player->number_of_attacks--;
            // system("clear");
            my_display_monsters(monsters, monster_count);
            printf("\n");
            my_display_player(player);
        } else {
            printf("\x1B[31mMonstre inexistant!\033[0m\n");
        }
    }

    if (choice == 2 || player->number_of_attacks == 0) {
        my_monsters_attack(monsters, monster_count, player);
        // system("clear");
        my_display_monsters(monsters, monster_count);
        printf("\n");
        my_display_player(player);
        player->number_of_attacks = 2; //on init les attackes
    }
}