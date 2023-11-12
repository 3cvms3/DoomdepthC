/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   create_sort.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 12:48:56 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:37:24 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

Sort *create_sort() {
    
    static const char *sort_names[] = {"BigWeaponn", "MoreBullet", "Lightning Bolt", "Healing otter"};
    static const SortType sort_types[] = {OFFENSIVE, OFFENSIVE, OFFENSIVE, HEALING};
    static const int sort_count = sizeof(sort_names) / sizeof(sort_names[0]);

    srand(time(NULL)); 

    Sort *sort = malloc(sizeof(Sort));
    
    int random_index = rand() % sort_count;
    sort->name = strdup(sort_names[random_index]);
    sort->type = sort_types[random_index];
    sort->power = rand() % 20 + 1;

    return sort;
}
