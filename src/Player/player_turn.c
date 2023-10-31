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
    
    printf("C'est votre tour! Vous avez %d attaques restantes ce tour.\n", player->number_of_attacks);
    printf("1. Attaquer un monstre\n");
    printf("2. Terminer le tour\n");
    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (choice == 1 && player->number_of_attacks > 0) {
        
        char prompt_target;
        int target;
        printf("Quel monstre voulez-vous attaquer (0-%d)? ", monster_count-1);
        scanf(" %c", &prompt_target);
        target = (int)(prompt_target - '0');
        if (target >= 0 && target < monster_count && monsters[target]->health > 0) {
            my_player_attack(player, monsters[target]);
            player->number_of_attacks--;
        } else {
            printf("Monstre invalide!\n");
        }
    }

    if (choice == 2 || player->number_of_attacks == 0) {
        my_monsters_attack(monsters, monster_count, player);
        player->number_of_attacks = 2; //on init les attackes
    }
}