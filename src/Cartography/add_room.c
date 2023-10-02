#include "Doomdepths.h"

Room *add_room(Floor *floor, int room_number) {
    Room *new_room = malloc(sizeof(Room));

    new_room->number_of_monsters = rand() % 5; // 0..4
    new_room->floor_number = floor->floor_number;
    new_room->room_number = room_number;

    /* Ici pour la dernière salle, on met des escaliers et */
    /* on rajoute des monstres, pour éviter de créer un étage vide */
    if (room_number == floor->number_of_rooms) {
        new_room->has_stairs = true;
        new_room->number_of_monsters = (rand() % 4) + 1; // 1..4
    } else {
        new_room->has_stairs = false;
    }

    return new_room;
}