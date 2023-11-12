/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   add_sort.c                                                :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 12:48:53 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 21:37:17 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#include "Doomdepths.h"

void add_sort(Sort *sort, Inventory *inventory) {
    
    if (inventory->number_of_items < inventory->capacity) {
        LinkedSort *linked_sort = malloc(sizeof(LinkedSort));
        linked_sort->sort = sort;
        linked_sort->previous_sort = inventory->linked_sorts;

        inventory->linked_sorts = linked_sort;
        inventory->number_of_items += 1;
    }
}
