#include "Doomdepths.h"

void remove_weapon(Weapon *weapon, Inventory *inventory) {
    LinkedWeapon *current_weapon = inventory->linked_weapons;
    LinkedWeapon *next_weapon = NULL;

    while (current_weapon != NULL) {
        if (current_weapon->weapon == weapon) {

            if (next_weapon != NULL) {
                next_weapon->previous_weapon = current_weapon->previous_weapon;
            } else {
                inventory->linked_weapons = current_weapon->previous_weapon;
            }

            free(current_weapon);
            break;
        }

        next_weapon = current_weapon;
        current_weapon = current_weapon->previous_weapon;
    }
}