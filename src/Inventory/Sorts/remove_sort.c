/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   remove_sort.c                                             :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 12:48:59 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 12:48:59 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void remove_sort(Sort *sort, Inventory *inventory) {

    LinkedSort *current_sort = inventory->linked_sorts;
    LinkedSort *next_sort = NULL;

    while (current_sort != NULL) {
        if (current_sort->sort == sort) {

            if (next_sort != NULL) {
                next_sort->previous_sort = current_sort->previous_sort;
            } else {
                inventory->linked_sorts = current_sort->previous_sort;
            }
            inventory->number_of_items--;
            free(current_sort);
            break;
        }
        next_sort = current_sort;
        current_sort = current_sort->previous_sort;
    }
}
