#include "Doomdepths.h"

Armor *create_armor() {
    Armor *armor = malloc(sizeof(Armor));
    armor->name = "Chest plate";
    armor->defense = 3;
    return armor;
}