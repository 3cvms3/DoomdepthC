#include "Doomdepths.h"

/*
 * Ici un exemple de ce que retourne la fonction dans le
 * cas où il y a 4 étages et le joueur se trouve 
 * dans la 2eme salle du 3eme étage
 *
 * FLOOR-1 ===[ 0 ]===[ 2 ]*
 * ||
 * FLOOR-2 ===[ 2 ]===[ 2 ]*
 * ||
 * FLOOR-3 ===[ 3 ]===[ 1 ](P)===[ 4 ]*
 * ||
 * FLOOR-4 ===[ 0 ]===[ 2 ]*
*/

void reverse_display_floors(Floor *last_floor, Position *player_pos) {
    if (last_floor == NULL) {
        return;
    }

    reverse_display_floors(last_floor->previous_floor, player_pos);

    if (last_floor->floor_number != 1) printf("\n||\n");
    printf("FLOOR-%d ", last_floor->floor_number);

    for (int i = 0; i < last_floor->number_of_rooms; i++) {
        printf("===[ %d ]", last_floor->rooms[i]->number_of_monsters);
        if (last_floor == player_pos->current_floor
            && last_floor->rooms[i] == player_pos->current_room) {
            printf("(P)");
        }
        if (last_floor->rooms[i]->has_stairs) printf("*");
    }
}