#ifndef Inventory_H_
#define Inventory_H_

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

typedef struct Inventory Inventory;
struct Inventory {
    int gold_amount;
    int number_of_items;
    int capacity;
    LinkedWeapon *linked_weapons;
    LinkedArmor *linked_armors;
};

Weapon *create_weapon();
Armor *create_armor();

Inventory *init_inventory();

void add_weapon(Weapon *weapon, Inventory *inventory);
void add_armor(Armor *armor, Inventory *inventory);

void remove_weapon(Weapon *weapon, Inventory *inventory);
void remove_armor(Armor *armor, Inventory *inventory);

void sell_weapon(Weapon *weapon, Inventory *inventory);
void sell_armor(Armor *armor, Inventory *inventory);

void display_inventory(Inventory *inventory);

#endif