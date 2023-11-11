#include "Doomdepths.h"

void equip_armor(Armor *armor, Player *player) {
    remove_armor(armor, player->inventory);
    add_armor(player->equipped_armor, player->inventory);
    player->equipped_armor = armor;
}