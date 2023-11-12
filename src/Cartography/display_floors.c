/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   display_floors.c                                          :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 21:51:06 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:51:09 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void display_floors(Floor *last_floor, Position *player_pos) {
    system("clear");
    printf(ANSI_COLOR_GREEN "╔═══════════════════════════[" EMOJI_MAP " MAP ]═══════════════════════════╗\n" ANSI_COLOR_RESET);
    printf("\n");

    reverse_display_floors(last_floor, player_pos);

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf(ANSI_COLOR_YELLOW "\n");
    printf(ANSI_COLOR_YELLOW "\n");
    printf("║ %d. Exit map " ANSI_COLOR_RED EMOJI_EXIT ANSI_COLOR_YELLOW "\n", 0);
    printf(ANSI_COLOR_YELLOW "║\n");
    printf("║ Enter your choice: ");
    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    switch(choice) {
        case 0:
            break;
        default:
            display_floors(last_floor, player_pos);
            break;
    }

    printf(ANSI_COLOR_GREEN "╚═══════════════════════════════════════════════════════════╝\n" ANSI_COLOR_RESET);
}
