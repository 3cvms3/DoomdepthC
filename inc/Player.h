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

#include "Doomdepths.h"

typedef struct Player Player;
struct Player {
    int health;
    int mana;
    int number_of_attacks;
    Position position;
    Weapon *equipped_weapon;
    Armor *equipped_armor;
    Inventory *inventory;
};

Player *init_player(Floor *floor);
void my_display_player(Player *player);
void my_init_player(Player *player);

void equip_weapon(Weapon *weapon, Player *player);
void equip_armor(Armor *armor, Player *player);

void display_player_inventory(Player *player);

void display_equip_weapons(Player *player);
void display_equip_armors(Player *player);

#endif