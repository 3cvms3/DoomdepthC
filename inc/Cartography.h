/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   Cartography.h                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 20:46:02 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:43:40 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef Cartography_H_
#define Cartography_H_

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"

#define EMOJI_MAP       "🗺️"
#define EMOJI_EXIT      "❌"

#include "Doomdepths.h"
#include <stdbool.h>

typedef struct Room Room;
struct Room {
    int room_number;
    int floor_number;
    int number_of_monsters;
    Monster **monsters;
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
void change_room(Position *player_pos);
void change_floor(Floor *last_floor, Position *player_pos, int floor_choice);
void reverse_display_floors(Floor *last_floor, Position *player_pos);
void display_floors(Floor *last_floor, Position *player_pos);

#endif
