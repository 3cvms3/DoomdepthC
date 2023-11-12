#ifndef REWARDS_H

#define REWARDS_H


// Structure to represent a reward

struct rewardWeapon {

    char[] name;     //name of weapon

    int numberOfAttacks;  
        int min_damage;
        int max_damage;   // minimum and maximum damage
};

struct rewardArmor {

    char[] name;     // name of armor

    int defense;   // Amount of the defense

};

#endif // REWARDS_H