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
    // char choice;

    my_random();
    
    Floor *last_floor = NULL;
    last_floor = add_floor(last_floor);

    Player *player = init_player(last_floor);

    game_loop(last_floor, player);

    // printf("Voulez-vous rejouer? (O/N) ");
    // scanf(" %c", &choice);

    return 0;
}

int main(void) {
    Doomdepths();
    return 0;
}
