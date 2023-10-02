#ifndef Cartography_H_
#define Cartography_H_

#include <stdbool.h>

typedef struct Room Room;
struct Room {
    int room_number;
    int number_of_monsters;
    int floor_number;
    bool has_stairs;
};

typedef struct Floor Floor;
struct Floor {
    int floor_number;
    Floor *previous_floor;
    int number_of_rooms;
    Room **rooms;
};

typedef struct Position Position;
struct Position {
    Floor *current_floor;
    Room *current_room;
};

Room *add_room(Floor *floor, int room_number);
Floor *add_floor(Floor *last_floor);
void display_floors(Floor *last_floor, Position *player_pos);
void change_floor(Floor *last_floor, Position *player_pos, int floor_choice);
void change_room(Position *player_pos);

#endif
