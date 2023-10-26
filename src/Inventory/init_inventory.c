#include "Doomdepths.h"

Inventory *init_inventory() {
    Inventory *inventory = malloc(sizeof(Inventory));
    inventory->number_of_items = 0;
    inventory->capacity = 8;
    inventory->linked_weapons = NULL;
    inventory->linked_armors = NULL;
    return inventory;
}