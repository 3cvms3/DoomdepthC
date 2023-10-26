#include "Doomdepths.h"

/*
 * On boucle dans la liste d'étages pour trouver l'étage choisi
 */
void change_floor(Floor *last_floor, Position *player_pos, int floor_choice) {
    while(last_floor != NULL) {
        if (last_floor->floor_number == floor_choice) {
            player_pos->current_floor = last_floor;
            player_pos->current_room = last_floor->rooms[0];
            break;
        }
        last_floor = last_floor->previous_floor;
    }
}