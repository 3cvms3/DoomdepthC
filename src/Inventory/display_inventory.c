#include "Doomdepths.h"

void display_inventory(Inventory *inventory) {
    printf("Gold : %d\n", inventory->gold_amount);
    LinkedWeapon *current_weapon = inventory->linked_weapons;

    while(current_weapon != NULL) {
        printf("%s : %d - %d - %d\n",
               current_weapon->weapon->name,
               current_weapon->weapon->number_of_attacks,
               current_weapon->weapon->min_damage,
               current_weapon->weapon->max_damage
        );
        current_weapon = current_weapon->previous_weapon;
    }

    LinkedArmor *current_armor = inventory->linked_armors;

    while(current_armor != NULL) {
        printf("%s : %d\n",
               current_armor->armor->name,
               current_armor->armor->defense
        );
        current_armor = current_armor->previous_armor;
    }
}