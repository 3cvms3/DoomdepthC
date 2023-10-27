#include "Doomdepths.h"

void display_inventory(Inventory *inventory) {
    char prompt_choice;
    int choice;

    do {
        system("clear");
        printf("==[ INVENTORY ]==\n\n");

        printf("Capacity usage : %d/%d\n", inventory->number_of_items, inventory->capacity);
        printf("Gold : %d coins\n", inventory->gold_amount);

        printf("\n::: WEAPONS :::\n\n");
        LinkedWeapon *current_weapon = inventory->linked_weapons;

        while(current_weapon != NULL) {
            printf("%s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
                current_weapon->weapon->name,
                current_weapon->weapon->number_of_attacks,
                current_weapon->weapon->min_damage,
                current_weapon->weapon->max_damage
            );
            current_weapon = current_weapon->previous_weapon;
        }

        printf("\n::: ARMORS :::\n\n");
        LinkedArmor *current_armor = inventory->linked_armors;

        while(current_armor != NULL) {
            printf("%s => DFS : %d\n",
                current_armor->armor->name,
                current_armor->armor->defense
            );
            current_armor = current_armor->previous_armor;
        }

        printf("\n\n0. Exit inventory\n");
        scanf(" %c", &prompt_choice);
        choice = (int)(prompt_choice - '0');
    } while (choice != 0);
}