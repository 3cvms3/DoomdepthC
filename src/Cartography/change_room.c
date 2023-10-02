#include "Doomdepths.h"


void change_room(Position *player_pos) {
    for (int i = 0; i < player_pos->current_floor->number_of_rooms; i++) {
        
        /* ici on vérifie si le joueur n'est pas déjà à la dernière salle */
        if ((i + 1) == player_pos->current_floor->number_of_rooms) {
            break;
        }

        if (player_pos->current_floor->rooms[i] == player_pos->current_room) {
            player_pos->current_room = player_pos->current_floor->rooms[i + 1];
            break;
        }
    }
}