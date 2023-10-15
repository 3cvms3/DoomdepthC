#include "Doomdepths.h"

Room *add_room(Floor *floor, int room_number) {
    Room *new_room = malloc(sizeof(Room));

    new_room->floor_number = floor->floor_number;
    new_room->room_number = room_number;
    
    /* Ici pour la dernière salle, on met des escaliers et */
    /* on rajoute des monstres, pour éviter de créer un étage vide */
    if (room_number == floor->number_of_rooms) {
        new_room->has_stairs = true;
        new_room->number_of_monsters = (rand() % 3) + 1; // 1..3
    } else {
        new_room->has_stairs = false;
        new_room->number_of_monsters = rand() % 4; // 0..3
    }

    /* Ici on vide la première salle du jeu */
    if (floor->floor_number == 1 && room_number == 1) {
        new_room->number_of_monsters = 0;
    }
    
    if (new_room->number_of_monsters > 0) {
        new_room->monsters = malloc(sizeof(Monster *) * new_room->number_of_monsters);

        for (int i = 0; i < new_room->number_of_monsters; i++) {
            new_room->monsters[i] = my_generate_monsters(1);
        }
    }

    return new_room;
}