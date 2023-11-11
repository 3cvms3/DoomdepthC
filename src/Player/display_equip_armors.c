#include "Doomdepths.h"

void display_equip_armors(Player *player) {
    Inventory *inventory = player->inventory;

    system("clear");
    printf("==[ INVENTORY ]==\n\n");
    printf("::ARMORS::\n");


    LinkedArmor *current_armor = inventory->linked_armors;
    int number_of_armors = 1;
    
    while(current_armor != NULL) {
        printf("%d. %s => DFS : %d\n",
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

    printf("\n\nEnter the number of the armor you want to equip\n");
    printf("Press any other key than list indexes to go back to inventory\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (1 <= choice && choice <= number_of_armors) {
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