/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   my_doomdepths.c                                           :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/24 17:47:43 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:11:45 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

int Doomdepths(void) {

    int level = 1;
    char choice;

    do {
        my_random();
        
        Monster monsters[4];
        int monster_count = my_random_monsters();
    
        for (int i = 0; i < monster_count; i++) {
            monsters[i] = my_generate_monsters(level);
        }
        my_display_monsters(monsters, monster_count);

        Player player;
        my_init_player(&player);
        my_display_player(&player);

        game_loop(&player, monsters, monster_count, &level);

        printf("Voulez-vous rejouer? (O/N) ");
        scanf(" %c", &choice);

    } while (choice == 'O' || choice == 'o');

    return 0;
}

int main(void) {
    Doomdepths();
    return 0;
}
