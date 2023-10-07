/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   Player.h                                                  :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/10/02 18:55:05 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:16:44 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef Player_H_
#define Player_H_

typedef struct {
    int weapon_power;
} Weapon;

typedef struct {
    int health;
    int mana;
    int gold;
    int attacks_turn;
    Weapon equipped_weapon;
} Player;

/*typedef struct Position Position;
struct Position {
    Floor *currentFloor;
    Room *currentRoom;
};*/

void my_display_player(Player *player);
void my_init_player(Player *player);

#endif