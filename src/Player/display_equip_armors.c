#include "Doomdepths.h"

void display_equip_armors(Player *player) {
    
    Inventory *inventory = player->inventory;

    system("clear");
    printf("\033[1;36m==[ 🎒 INVENTORY ]==\033[0m\n\n");
    printf("\033[1;33m::🛡️ ARMORS::\033[0m\n");

    LinkedArmor *current_armor = inventory->linked_armors;
    int number_of_armors = 1;
    
    if (current_armor == NULL) {
        printf("\033[0;31mNo armors available to equip.\033[0m\n");
    }

    while(current_armor != NULL) {
        printf("\033[0;32m%d.\033[0m %s => \033[0;34mDFS : %d\033[0m\n",
            number_of_armors,
            current_armor->armor->name,
            current_armor->armor->defense
        );
        current_armor = current_armor->previous_armor;
        number_of_armors++;
    }

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\n\033[1;34mEnter the number of the armor you want to equip\033[0m\n");
    printf("\033[1;34mPress any other key than list indexes to go back to inventory\033[0m\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (1 <= choice && choice < number_of_armors) {
        LinkedArmor *linked_armor = inventory->linked_armors;

        for (int i = 1; i < choice; i++) {
            linked_armor = linked_armor->previous_armor;
        }
        equip_armor(linked_armor->armor, player);
        display_player_inventory(player);
    } else {
        display_player_inventory(player);
    }
}
