#include "Doomdepths.h"

void sell_armor(Armor *armor, Inventory *inventory) {
    remove_armor(armor, inventory);
    free(armor);
    inventory->gold_amount += 20;
}