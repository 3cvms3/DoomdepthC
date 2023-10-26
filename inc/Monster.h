/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   Monster.h                                                 :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/09/30 15:16:35 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/10/07 22:16:41 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef Monster_H_
#define Monster_H_

#define ASCII_LINES_M 10
typedef struct {
    int health;
    int min_attack;
    int max_attack;
    int defense;
} Monster;

int my_random_monsters();
Monster *my_generate_monsters(int level);
void my_display_monsters(Monster **enemies, int count);
int my_verif_death_monsters(Monster **monsters, int monster_count);
//void my_monsters_attack(Monster *monsters, int monster_count, Player *player);

#endif