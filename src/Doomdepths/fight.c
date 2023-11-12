#include "Doomdepths.h"
int diff=0;
const char* game_over[]={
"   ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████       ▄██████▄   ▄█    █▄     ▄████████    ▄████████",
"  ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███      ███    ███ ███    ███   ███    ███   ███    ███",
"  ███    █▀    ███    ███ ███   ███   ███   ███    █▀       ███    ███ ███    ███   ███    █▀    ███    ███",
" ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄          ███    ███ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀",
"▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀          ███    ███ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀",
"  ███    ███   ███    ███ ███   ███   ███   ███    █▄       ███    ███ ███    ███   ███    █▄  ▀███████████",
"  ███    ███   ███    ███ ███   ███   ███   ███    ███      ███    ███ ███    ███   ███    ███   ███    ███",
"  ████████▀    ███    █▀   ▀█   ███   █▀    ██████████       ▀██████▀   ▀██████▀    ██████████   ███    ███"
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

//combat joueur x player 
void fight_loop(Player *player, Room *room) {

    //si joueur en vie et que il reste des monstres 
    while (player->health > 0 && !my_verif_death_monsters(room->monsters, room->number_of_monsters, player->inventory)) {
        my_player_turn(player, room->monsters, room->number_of_monsters);

        if (player->health <= 0) {
            system("clear");
            for (int line = 0; line < sizeof(game_over) / sizeof(game_over[0]); line++) {
                printf("%*s\x1B[38;5;52m%s\033[0m\t\t\n", 0, "", game_over[line]);
            }
            for (int line = 0; line < sizeof(skull) / sizeof(skull[0]); line++) {
                printf("%*s\x1B[38;5;52m%s\033[0m\t\t\n", diff, "", skull[line]);
            }
            break;
        }
    }
}