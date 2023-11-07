#include "Doomdepths.h"

void equip_weapon(Weapon *weapon, Player *player) {
    remove_weapon(weapon, player->inventory);
    add_weapon(player->equipped_weapon, player->inventory);
    player->equipped_weapon = weapon;
}