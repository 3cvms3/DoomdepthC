#include "Doomdepths.h"

Room *add_room(Floor *floor, int room_number) {
    Room *new_room = malloc(sizeof(Room));
    
    //Precision du numero de l'etage auquel la piece appartient
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
            //Ici dans la generation des monstres , on implique que leur niveau n'augmante qu'apres trois etages
            int ii=1;
            int stop=0;
            while(stop!=1){
                if(floor->floor_number>3*ii){
                    ii++;
                }else{
                    stop=1;
                    break;
                }
            }
            new_room->monsters[i] = my_generate_monsters(ii);
        }
    }

    return new_room;
}