#include "Doomdepths.h"

Armor *create_armor() {
    Armor *armor = malloc(sizeof(Armor));
    armor->name = "Sword";
    armor->number_of_attack = 3;
    armor->min_damage = 3;
    armor->max_damage = 9;
    return armor;
}