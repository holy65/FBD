#include <stdio.h>
#include <stdlib.h>

// Define the number of orbs
#define NUM_ORBS 11

// Map dimensions
#define MAP_WIDTH 10
#define MAP_HEIGHT 5

// Aura names
const char* orb_names[NUM_ORBS] = {
    "Common Aura",       // 50% chance
    "Uncommon Aura",     // 20% chance
    "Rare Aura",         // 15% chance
    "Epic Aura",         // 10% chance
    "Legendary Aura",    // 3% chance
    "Mythic Aura",       // 1% chance
    "Exotic Aura",       // 0.5% chance
    "Celestial Aura",    // 0.3% chance
    "Divine Aura",       // 0.15% chance
    "Ethereal Aura",     // 0.05% chance
    "Ultimate Aura"      // 0.01% chance
};

// Aura probabilities (as fixed-point integers, scaled by 10000)
const int orb_probabilities[NUM_ORBS] = {
    5000,  // Common Aura (50%)
    2000,  // Uncommon Aura (20%)
    1500,  // Rare Aura (15%)
    1000,  // Epic Aura (10%)
    300,   // Legendary Aura (3%)
    100,   // Mythic Aura (1%)
    50,    // Exotic Aura (0.5%)
    30,    // Celestial Aura (0.3%)
    15,    // Divine Aura (0.15%)
    5,     // Ethereal Aura (0.05%)
    1      // Ultimate Aura (0.01%)
};

// Player position and luck
int player_x = 0;
int player_y = 0;
int player_luck = 0;

// NPC position and dialogue
int npc_x = 7;
int npc_y = 2;
const char* npc_dialogue = "Hello, traveler! Collect potions to increase your luck!";

// Map symbols
const char EMPTY = '.';
const char PLAYER = 'P';
const char POTION = 'L';
const char NPC_CHAR = 'N';

// Function to roll for an orb
int roll_orb(int luck) {
    int roll;
    int cumulative_probability;
    int i;

    // Adjust probabilities based on luck
    int adjusted_probabilities[NUM_ORBS];
    for (i = 0; i < NUM_ORBS; i++) {
        adjusted_probabilities[i] = orb_probabilities[i] * (1 + luck / 10);
    }

    // Generate a random integer between 0 and 9999
    roll = rand() % 10000;
    cumulative_probability = 0;

    for (i = 0; i < NUM_ORBS; i++) {
        cumulative_probability += adjusted_probabilities[i];
        if (roll < cumulative_probability) {
            return i; // Return the index of the rolled orb
        }
    }

    return NUM_ORBS - 1; // Default to the rarest orb if no match
}

// Function to draw the map
void draw_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int y, x;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("%c ", PLAYER);
            } else if (x == npc_x && y == npc_y) {
                printf("%c ", NPC_CHAR);
            } else {
                printf("%c ", map[y][x]);
            }
        }
        printf("\n");
    }
}

// Function to simulate input (placeholder for sim65c02)
char get_input() {
    char input;
    printf("Enter a command (WASD to move, R to roll, T to talk, Q to quit): ");
    scanf(" %c", &input); // Use scanf for input in sim65c02
    return input;
}

int main() {
    // Initialize the map
    char map[MAP_HEIGHT][MAP_WIDTH];
    int y, x;
    char input; // Declare 'input' at the beginning of the function

    // Initialize the map with empty spaces
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = EMPTY;
        }
    }

    // Place potions on the map
    map[1][2] = POTION;
    map[3][7] = POTION;
    map[4][4] = POTION;

    // Seed the random number generator
    srand(1234);

    printf("Welcome to the Aura Roller!\n");
    printf("Use WASD to move, 'R' to roll for an orb, 'T' to talk to the NPC, and 'Q' to quit.\n");

    while (1) {
        // Draw the map
        draw_map(map);

        // Get user input
        input = get_input(); // Use the placeholder input function

        // Handle input
        switch (input) {
            case 'w': // Move up
                if (player_y > 0) player_y--;
                break;
            case 'a': // Move left
                if (player_x > 0) player_x--;
                break;
            case 's': // Move down
                if (player_y < MAP_HEIGHT - 1) player_y++;
                break;
            case 'd': // Move right
                if (player_x < MAP_WIDTH - 1) player_x++;
                break;
            case 'r': // Roll for an orb
                {
                    int orb_index = roll_orb(player_luck);
                    printf("You rolled: %s, with a chance of 1 in %d!\n", orb_names[orb_index], 10000 / orb_probabilities[orb_index]);
                }
                break;
            case 't': // Talk to NPC
                if (player_x == npc_x && player_y == npc_y) {
                    printf("NPC: %s\n", npc_dialogue);
                } else {
                    printf("You are not near the NPC.\n");
                }
                break;
            case 'q': // Quit
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid input. Use WASD to move, 'R' to roll, 'T' to talk, and 'Q' to quit.\n");
                break;
        }

        // Check for potion collection
        if (map[player_y][player_x] == POTION) {
            player_luck += 1;
            map[player_y][player_x] = EMPTY;
            printf("You found a potion! Your luck is now %d.\n", player_luck);
        }
    }

    return 0;
}