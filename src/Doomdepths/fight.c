#include "Doomdepths.h"
int diff=60;
const char* game_over[]={
"   ____   ____  ___ ___    ___       ___   __ __    ___  ____ ", 
" /    T /    T|   T   T  /  _]     /   \\ |  T  |  /  _]|    \\ ",
"Y   __jY  o  || _   _ | /  [_     Y     Y|  |  | /  [_ |  D  )",
"|  T  ||     ||  \\_/  |Y    _]    |  O  ||  |  |Y    _]|    / ",
"|  l_ ||  _  ||   |   ||   [_     |     |l  :  !|   [_ |    \\ ",
"|     ||  |  ||   |   ||     T    l     ! \\   / |     T|  .  Y",
"l___,_jl__j__jl___j___jl_____j     \\___/   \\_/  l_____jl__j\\_j"   
};
const char* skull[]={
"                               ,--.",
"                          {    }",
"                          K,   }",
"                         /  `Y`",
"                    _   /   /",
"                   {_'-K.__/",
"                     `/-.__L._",
"                     /  ' /`\\_}",
"                    /  ' /",
"            ____   /  ' /",
"     ,-'~~~~    ~~/  ' /_",
"   ,'             ``~~~%%',",
"  (                     %%  Y",
" {                      %% I",
"{      -                 %%  `.",
"|       ',                %%  )",
"|        |   ,..__      __. Y",
"|    .,_./  Y ' / ^Y   J   )|",
"\\           |' /   |   |   ||",
" \\          L_/    . _ (_,.'(",
"  \\,   ,      ^^""' / |      )",
"    \\_  \\          /,L]     /",
"      '-_`-,       ` `   ./`",
"         `-(_            )",
"             ^^\\..___,.--`"
};
void fight_loop(Player *player, Room *room) {

//INITIATE REWARDS FOR LEVEL

Weapon weapons_list[] = {
        {"Axe", 5, 10, 20},
        {"Longbow", 10, 4, 40},
        {"Lance", 5, 3, 35},
        {"Glaive", 3, 30, 80},
        {"Hammer", 8, 16, 45},
        {"Knife", 30, 5, 10},
    };

Armor armor_list[] = {
        {"Shield", 70},
        {"Helmet", 80},
        {"Gauntlets", 30},
        {"Pauldron", 50},
        {"Cuirass", 100},
        {"Sabatons", 20},
    };

struct Armor armorReward = {armor_list[rand() % 5 + 0]};

struct Weapon weaponReward = {weapons_list[rand() % 5 + 0]};

Weapon weapon=create_weapon(armorReward);
Armor armor = create_armor(weaponReward);

Int goldReward;


    while (player->health > 0 && !my_verif_death_monsters(room->monsters, room->number_of_monsters)) {

        my_player_turn(player, room->monsters, room->number_of_monsters);

 

        if (player->health <= 0) {
            system("clear");
            for (int line = 0; line < sizeof(game_over) / sizeof(game_over[0]); line++) {
                if(line%2==0){
                    printf("%*s%s\n", 50, "", game_over[line]);
                }else{
                    printf("%*s\x1B[31m%s\033[0m\t\t\n", 50, "", game_over[line]);
                }
            }
            for (int line = 0; line < sizeof(skull) / sizeof(skull[0]); line++) {
                if(line%2==0){
                    printf("%*s%s\n", diff, "", skull[line]);
                }else{
                    printf("%*s\x1B[31m%s\033[0m\t\t\n", diff, "", skull[line]);
                }
            }
            break;

        }else{

 

                              for (int i = 0; i < monster_count; i++) {

        if (monsters[i]->health <= 0) {

            printf("Vous avez tué les monstres.\n");

           
//initiate number of gold
            goldReward=(rand()%10+2)*room->number_of_monsters+player->health;

 

 

    // giving rewards to the player

    addArmor(armor);

    addWeapon(weapon);

    Inventory->gold_amount+=goldReward ;

        }

 

               }

       

    }

    }

}