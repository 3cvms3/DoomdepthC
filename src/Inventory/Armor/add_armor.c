#include "Doomdepths.h"

void add_armor(Armor *armor, Inventory *inventory) {
    if (inventory->number_of_items < inventory->capacity) {
        LinkedArmor *linked_armor = malloc(sizeof(LinkedArmor));
        linked_armor->armor = armor;
        linked_armor->previous_armor = inventory->linked_armors;

        inventory->linked_armors = linked_armor;
        inventory->number_of_items += 1;
    }
}