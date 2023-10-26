#include "Doomdepths.h"

void sell_weapon(Weapon *weapon, Inventory *inventory) {
    remove_weapon(weapon, inventory);
    free(weapon);
    inventory->gold_amount += 20;
}