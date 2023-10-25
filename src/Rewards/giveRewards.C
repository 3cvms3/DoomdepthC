#include "Doomdepths.h"

void giveRewardToPlayer(struct Reward reward) {
    switch (reward.type) {
        case REWARD_TYPE_ARMOR:
            printf("You have received %d armor!\n", reward.amount);
                        // Update the player's armor system
            break;
        case REWARD_TYPE_GOLD:
            printf("You earned %d gold!\n", reward.amount);
                        // Add the gold to the player's in-game wallet or account
            break;
        case REWARD_TYPE_WEAPON:
            printf("You found %d weapons!\n", reward.amount);
            // Add weapons to the player's inventory
            break;
        default:
            printf("Invalid reward type\n");
    }
}