#include "Doomdepths.h"

/* 
 * On passe un { Floor *floor = NULL; } pour
 * initialiser la liste chaînée à l'étage zéro 
 */
Floor *add_floor(Floor *last_floor) {
    Floor *new_floor = malloc(sizeof(Floor));

    new_floor->number_of_rooms = (rand() % 3) + 1; // 1..3
    new_floor->rooms = malloc(sizeof(Room *) * new_floor->number_of_rooms);
    new_floor->previous_floor = last_floor;

    /* Ici on gère le 1er étage dans le else */
    if (last_floor != NULL) {
        new_floor->floor_number = last_floor->floor_number + 1;
    } else {
        new_floor->floor_number = 1;
    }

    for (int i = 0; i < new_floor->number_of_rooms; i++) {
        new_floor->rooms[i] = add_room(new_floor, i + 1);
    }

    return new_floor;
}