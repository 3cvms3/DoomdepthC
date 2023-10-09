#include "Doomdepths.h"

Weapon *create_weapon() {
    Weapon *weapon = malloc(sizeof(Weapon));
    weapon->name = "Sword";
    weapon->number_of_attack = 3;
    weapon->min_damage = 3;
    weapon->max_damage = 9;
    return weapon;
}