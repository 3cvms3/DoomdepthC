/* ********************************************************************************************************* */
/*                                                                                                           */
/*                                                              :::::::::: ::::::::   :::::::: :::::::::::   */
/*   Inventory.h                                               :+:       :+:    :+: :+:    :+:    :+:        */
/*                                                            +:+       +:+        +:+           +:+         */
/*   By: camillia <chammou1@myges.fr>                        +#++:++#  +#++:++#++ :#:           +#+          */
/*                                                          +#+              +#+ +#+   +#+#    +#+           */
/*   Created: 2023/11/12 20:46:14 by camillia              #+#       #+#    #+# #+#    #+#    #+#            */
/*   Updated: 2023/11/12 20:46:14 by camillia             ########## ########   ######## ###########         */
/*                                                                                                           */
/* ********************************************************************************************************* */

#ifndef Inventory_H_
#define Inventory_H_

typedef enum {
    OFFENSIVE,
    DEFENSIVE,
    HEALING
} SortType;

typedef struct Weapon Weapon;
struct Weapon {
    char *name;
    int min_damage;
    int max_damage;
    int number_of_attacks;
};

typedef struct Armor Armor;
struct Armor {
    char *name;
    int defense;
};

typedef struct Sort Sort;
struct Sort {
    char *name;
    SortType type;
    int power;
};

typedef struct LinkedWeapon LinkedWeapon;
struct LinkedWeapon {
    Weapon *weapon;
    LinkedWeapon *previous_weapon;
};

typedef struct LinkedArmor LinkedArmor;
struct LinkedArmor {
    Armor *armor;
    LinkedArmor *previous_armor;
};

typedef struct LinkedSort LinkedSort;
struct LinkedSort {
    Sort *sort;
    LinkedSort *previous_sort;
};

typedef struct Inventory Inventory;
struct Inventory {
    int gold_amount;
    int number_of_items;
    int capacity;
    LinkedWeapon *linked_weapons;
    LinkedArmor *linked_armors;
    LinkedSort *linked_sorts;
};


Weapon *create_weapon();
Armor *create_armor();
Sort *create_sort();

Inventory *init_inventory();

void add_weapon(Weapon *weapon, Inventory *inventory);
void add_armor(Armor *armor, Inventory *inventory);
void add_sort(Sort *sort, Inventory *inventory);

void remove_weapon(Weapon *weapon, Inventory *inventory);
void remove_armor(Armor *armor, Inventory *inventory);
void remove_sort(Sort *sort, Inventory *inventory);

void sell_weapon(Weapon *weapon, Inventory *inventory);
void sell_armor(Armor *armor, Inventory *inventory);
void sell_sort(Sort *sort, Inventory *inventory);



#endif