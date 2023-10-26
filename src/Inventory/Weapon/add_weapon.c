#include "Doomdepths.h"

void add_weapon(Weapon *weapon, Inventory *inventory) {
    if (inventory->number_of_items < inventory->capacity) {
        LinkedWeapon *linked_weapon = malloc(sizeof(LinkedWeapon));
        linked_weapon->weapon = weapon;
        linked_weapon->previous_weapon = inventory->linked_weapons;

        inventory->linked_weapons = linked_weapon;
        inventory->number_of_items += 1;
    }
}