#include "Doomdepths.h"

void display_player_inventory(Player *player) {

    Inventory *inventory = player->inventory;

    system("clear");
    printf("==[ INVENTORY ]==\n\n");

    printf("Capacity usage : %d/%d\n", inventory->number_of_items, inventory->capacity);
    printf("Gold : %d coins\n", inventory->gold_amount);

    printf("Equipped weapon : %s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
        player->equipped_weapon->name,
        player->equipped_weapon->number_of_attacks,
        player->equipped_weapon->min_damage,
        player->equipped_weapon->max_damage
    );

    printf("Equipped armor : %s => DFS : %d\n",
        player->equipped_armor->name,
        player->equipped_armor->defense
    );

    printf("\n::: WEAPONS :::\n");
    LinkedWeapon *current_weapon = inventory->linked_weapons;

    while(current_weapon != NULL) {
        printf("%s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
            current_weapon->weapon->name,
            current_weapon->weapon->number_of_attacks,
            current_weapon->weapon->min_damage,
            current_weapon->weapon->max_damage
        );
        current_weapon = current_weapon->previous_weapon;
    }

    printf("\n::: ARMORS :::\n");
    LinkedArmor *current_armor = inventory->linked_armors;

    while(current_armor != NULL) {
        printf("%s => DFS : %d\n",
            current_armor->armor->name,
            current_armor->armor->defense
        );
        current_armor = current_armor->previous_armor;
    }

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\n0. Exit inventory\n");
    if (inventory->linked_weapons != NULL) {
        printf("1. Equip WEAPON from inventory\n");
    }
    if (inventory->linked_armors != NULL) {
        printf("2. Equip ARMOR from inventory\n");
    }

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    switch(choice) {
        case 0:
            break;
        case 1:
            if (inventory->linked_weapons) {
                display_equip_weapons(player);
                break;
            } else {
                display_player_inventory(player);
                break;
            }
        case 2:
            if (inventory->linked_armors) {
                display_equip_armors(player);
                break;
            } else {
                display_player_inventory(player);
                break;
            }
        default:
            display_player_inventory(player);
            break;
    }
}