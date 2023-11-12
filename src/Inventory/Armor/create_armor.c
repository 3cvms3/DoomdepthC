#include "Doomdepths.h"

Armor *create_armor() {
    static const char *armor_names[] = {"Chest Plate", "Helmet", "Greaves", "Gauntlets", "Shield"};
    static const int armor_count = sizeof(armor_names) / sizeof(armor_names[0]);

    srand(time(NULL));

    Armor *armor = malloc(sizeof(Armor));

    int random_index = rand() % armor_count;
    armor->name = strdup(armor_names[random_index]);

    armor->defense = rand() % 10 + 1;

    return armor;
}