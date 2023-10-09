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

void my_player_turn(Player *player, Monster *monsters, int monster_count) {

    int choice;
    
    printf("C'est votre tour! Vous avez %d attaques restantes ce tour.\n", player->attacks_turn);
    printf("1. Attaquer un monstre\n");
    printf("2. Terminer le tour\n");
    scanf("%d", &choice);

    if (choice == 1 && player->attacks_turn > 0) {
        
        int target;
        printf("Quel monstre voulez-vous attaquer (0-%d)? ", monster_count-1);
        scanf("%d", &target);
        if (target >= 0 && target < monster_count && monsters[target].health > 0) {
            my_player_attack(player, &monsters[target]);
            player->attacks_turn--;
            my_display_monsters(monsters, monster_count);
            my_display_player(player);
        } else {
            printf("Monstre invalide!\n");
        }
    }

    if (choice == 2 || player->attacks_turn == 0) {
        my_monsters_attack(monsters, monster_count, player);
        my_display_monsters(monsters, monster_count);
        my_display_player(player);
        player->attacks_turn = 2; //on init les attackes
    }
}