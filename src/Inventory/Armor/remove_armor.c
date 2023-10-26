#include "Doomdepths.h"

void remove_armor(Armor *armor, Inventory *inventory) {
    LinkedArmor *current_armor = inventory->linked_armors;
    LinkedArmor *next_armor = NULL;

    while (current_armor != NULL) {
        if (current_armor->armor == armor) {

            if (next_armor != NULL) {
                next_armor->previous_armor = current_armor->previous_armor;
            } else {
                inventory->linked_armors = current_armor->previous_armor;
            }

            free(current_armor);
            break;
        }

        next_armor = current_armor;
        current_armor = current_armor->previous_armor;
    }
}