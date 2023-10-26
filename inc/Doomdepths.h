/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   Doomdepths.h                                              :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/24 17:47:37 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:16:37 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef DOOMDEPTHS_H_
#define DOOMDEPTHS_H_


#include <time.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Inventory.h"
#include "Monster.h"
#include "Cartography.h"
#include "Player.h"
#include <sys/ioctl.h>
#include <unistd.h>

int Doomdepths(void);
void my_random();
void my_player_attack(Player *player, Monster *monster);
void fight_loop(Player *player, Room *room);
void game_loop(Floor *last_floor, Player *player);
void my_monsters_attack(Monster **monsters, int monster_count, Player *player);
void my_player_turn(Player *player, Monster **monsters, int monster_count);
void my_handle_level_up(Player *player, Monster *monsters, int monster_count, int *level);
#endif
