#include "Doomdepths.h"

void display_equip_weapons(Player *player) {

    Inventory *inventory = player->inventory;

    system("clear");
    printf("\033[1;36m==[ 🎒 INVENTORY ]==\033[0m\n\n");
    printf("\033[1;33m::🗡️ WEAPONS::\033[0m\n");

    LinkedWeapon *current_weapon = inventory->linked_weapons;
    int number_of_weapons = 1;
    
    while(current_weapon != NULL) {
        printf("\033[0;32m%d. %s\033[0m => \033[0;34m%d Attacks\033[0m | \033[0;31mATKMIN : %d\033[0m | \033[0;31mATKMAX : %d\033[0m\n",
            number_of_weapons,
            current_weapon->weapon->name,
            current_weapon->weapon->number_of_attacks,
            current_weapon->weapon->min_damage,
            current_weapon->weapon->max_damage
        );
        current_weapon = current_weapon->previous_weapon;
        number_of_weapons++;
    }

    if (number_of_weapons == 1) {
        printf("\033[0;31mNo weapons available to equip.\033[0m\n");
    }

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\n\033[1;34mEnter the number of the weapon you want to equip\n");
    printf("Press any other key than list indexes to go back to inventory\033[0m\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (1 <= choice && choice <= number_of_weapons - 1) {
        LinkedWeapon *linked_weapon = inventory->linked_weapons;

        for (int i = 1; i < choice; i++) {
            linked_weapon = linked_weapon->previous_weapon;
        }
        equip_weapon(linked_weapon->weapon, player);
        display_player_inventory(player);
    } else {
        display_player_inventory(player);
    }
}
