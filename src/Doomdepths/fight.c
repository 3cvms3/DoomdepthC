#include "Doomdepths.h"

void fight_loop(Player *player, Room *room) {
    while (player->health > 0 && !my_verif_death_monsters(room->monsters, room->number_of_monsters)) {
        my_player_turn(player, room->monsters, room->number_of_monsters);

        if (player->health <= 0) {
            printf("Vous avez été tué par les monstres. Fin du jeu!\n");
            break;
        }
    }
}