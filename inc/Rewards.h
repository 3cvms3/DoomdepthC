#ifndef REWARDS_H
#define REWARDS_H

// Define constants for different types of rewards
#define REWARD_TYPE_GOLD 1
#define REWARD_TYPE_WEAPON 2
#define REWARD_TYPE_ARMOR 3

// Structure to represent a reward
struct Reward {
    int type;     // Type of reward (e.g., gold, weapon, armor)
    int amount;   // Amount of the reward
};

// Function to give rewards to the player
void giveRewardToPlayer(struct Reward reward);

#endif // REWARDS_H
