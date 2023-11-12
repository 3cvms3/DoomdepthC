/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   display_equip_sorts.c                                     :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 12:48:31 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 20:57:40 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void display_equip_sorts(Player *player) {

    Inventory *inventory = player->inventory;

    system("clear");
    printf("\033[1;36m==[ 🎒 INVENTORY ]==\033[0m\n\n");
    printf("\033[1;33m::✨ SORTS::\033[0m\n");

    LinkedSort *current_sort = inventory->linked_sorts;
    int number_of_sorts = 1;
    
    if (current_sort == NULL) {
        printf("\033[0;31mNo sorts available to equip.\033[0m\n");
    }

    while (current_sort != NULL) {
        printf("\033[0;32m%d.\033[0m %s => \033[0;34mPWR : %d\033[0m\n",
            number_of_sorts,
            current_sort->sort->name,
            current_sort->sort->power
        );
        current_sort = current_sort->previous_sort;
        number_of_sorts++;
    }

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\n\033[1;34mEnter the number of the sort you want to equip\033[0m\n");
    printf("\033[1;34mPress any other key than list indexes to go back to inventory\033[0m\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (1 <= choice && choice < number_of_sorts) {
        LinkedSort *linked_sort = inventory->linked_sorts;

        for (int i = 1; i < choice; i++) {
            linked_sort = linked_sort->previous_sort;
        }
        equip_sort(linked_sort->sort, player);
        display_player_inventory(player);
    } else {
        display_player_inventory(player);
    }
}
