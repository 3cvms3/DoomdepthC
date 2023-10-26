#include "Doomdepths.h"

void display_floors(Floor *last_floor, Position *player_pos) {
    printf("\n");
    reverse_display_floors(last_floor, player_pos);
    printf("\n");
}