#include "Doomdepths.h"

void display_player_inventory(Player *player) {

    Inventory *inventory = player->inventory;

    system("clear");
    printf("                                    \033[1;36m========================[ 🎒 INVENTORY ]==========================\033[0m\n\n");

    printf("\033[1;33mCapacity usage : \033[0;32m%d/%d\033[0m\n", inventory->number_of_items, inventory->capacity);
    printf("\033[1;33mGold : \033[0;33m%d coins\033[0m\n", inventory->gold_amount);

    char prompt_choice;
    int choice;
    
   printf("\n\033[1;35m:: Equipped Items ::\033[0m\n\n");
    //Affichage de l'arme ajouté
    if (player->equipped_weapon != NULL) {
        printf("\033[0;32mEquipped weapon\033[0m : %s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
            player->equipped_weapon->name,
            player->equipped_weapon->number_of_attacks,
            player->equipped_weapon->min_damage,
            player->equipped_weapon->max_damage
        );
    } else {
        printf("\033[0;31m{No weapon equipped}\033[0m\n");
    }

    //Affichage de l'armure ajouté
    if (player->equipped_armor != NULL) {
        printf("\033[0;32mEquipped armor\033[0m : %s => DFS : %d\n",
            player->equipped_armor->name,
            player->equipped_armor->defense
        );
    } else {
        printf("\033[0;31m{No armor equipped}\033[0m\n");
    }

    //Affichage du sort ajouté
    if (player->equipped_sort != NULL) {
        printf("\033[0;32mEquipped sort\033[0m : %s => PWR : %d\n",
            player->equipped_sort->name,
            player->equipped_sort->power
        );
    } else {
        printf("\033[0;31m{No sort equipped}\033[0m\n");
    }

    //Affichage des armes dans l'inventaire
    printf("                                    \n\033[1;34m::: WEAPONS :::\033[0m\n\n");
    LinkedWeapon *current_weapon = inventory->linked_weapons;
    if (current_weapon == NULL) {
        printf("\033[0;31mNo weapons in inventory\033[0m\n");
    }
    while(current_weapon != NULL) {
        printf("%s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
            current_weapon->weapon->name,
            current_weapon->weapon->number_of_attacks,
            current_weapon->weapon->min_damage,
            current_weapon->weapon->max_damage
        );
        current_weapon = current_weapon->previous_weapon;
    }

    //Affichage des armures dans l'inventaire
    printf("                                    \n\033[1;34m::: ARMORS :::\033[0m\n\n");
    LinkedArmor *current_armor = inventory->linked_armors;
    if (current_armor == NULL) {
        printf("\033[0;31mNo armors in inventory\033[0m\n");
    }
    while(current_armor != NULL) {
        printf("%s => DFS : %d\n",
            current_armor->armor->name,
            current_armor->armor->defense
        );
        current_armor = current_armor->previous_armor;
    }

    //Affichage des sorts dans l'inventaire
    printf("                                    \n\033[1;34m::: SORTS :::\033[0m\n\n");
    LinkedSort *current_sort = inventory->linked_sorts;
    if (current_sort == NULL) {
        printf("\033[0;31mNo sorts in inventory\033[0m\n");
    }
    while(current_sort != NULL) {
        printf("%s => PWR : %d\n",
            current_sort->sort->name,
            current_sort->sort->power
        );
        current_sort = current_sort->previous_sort;
    }

    //Affichage du menu
    printf("\n\033[1;32m0. Exit inventory\033[0m\n");
    if (inventory->linked_weapons != NULL) {
        printf("\033[1;32m1. Equip WEAPON from inventory\033[0m\n");
    }
    if (inventory->linked_armors != NULL) {
        printf("\033[1;32m2. Equip ARMOR from inventory\033[0m\n");
    }
    if (inventory->linked_sorts != NULL) {
        printf("\033[1;32m3. Equip SORT from inventory\033[0m\n");
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
            }
        case 2:
            if (inventory->linked_armors) {
                display_equip_armors(player);
                break;
            }
        case 3:
            if (inventory->linked_sorts) {
                display_equip_sorts(player);
                break;
            }
        default:
            display_player_inventory(player);
            break;
    }
}

