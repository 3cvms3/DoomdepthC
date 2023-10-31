#include "Doomdepths.h"

void display_equip_weapons(Player *player) {
    Inventory *inventory = player->inventory;

    system("clear");
    printf("==[ INVENTORY ]==\n\n");
    printf("::WEAPONS::\n");


    LinkedWeapon *current_weapon = inventory->linked_weapons;
    int number_of_weapons = 1;
    
    while(current_weapon != NULL) {
        printf("%d. %s => %d Attacks | ATKMIN : %d | ATKMAX : %d\n",
            number_of_weapons,
            current_weapon->weapon->name,
            current_weapon->weapon->number_of_attacks,
            current_weapon->weapon->min_damage,
            current_weapon->weapon->max_damage
        );
        current_weapon = current_weapon->previous_weapon;
        number_of_weapons++;
    }

    /* Affichage du menu */
    char prompt_choice;
    int choice;

    printf("\n\nEnter the number of the weapon you want to equip\n");
    printf("Press any other key than list indexes to go back to inventory\n");

    scanf(" %c", &prompt_choice);
    choice = (int)(prompt_choice - '0');

    if (1 <= choice && choice <= number_of_weapons) {
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