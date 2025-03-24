#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "archive/cute_airlib.h"

// Define the number of jokes
#define NUM_JOKES 150

// Map dimensions
#define MAP_WIDTH 60
#define MAP_HEIGHT 30

// Jokes array
const char* jokes[] = {
    "Why can't a bicycle stand up by itself? It's two tired!",
    "What do you call a bear with no teeth? A gummy bear!",
    "Why do cows wear bells? Their horns don't work!",
    "What do you call a fake noodle? An impasta!",
    "Why did the tomato turn red? Because it saw the sal-ad dressing!",
    "Why don't scientists trust atoms? Because they make up everything!",
    "Why did the scarecrow win an award? Because he was outstanding in his field!",
    "Why can't a nose be 12 inches long? Because then it would be a foot!",
    "Why did the kid throw his clock out the window? Because he wanted to see time fly!",
    "What do you call a boomerang that doesn't come back? A stick!",
    "Why did the math book look sad? Because it had too many problems!",
    "Why did the cookie go to the doctor? Because he was feeling crumby!",
    "Why did the chicken go to the seance? To get to the other side!",
    "Io io io, your mom is so fat, she has her own gravitational field!",
    "I tried to catch some fog earlier. I mist.",
    "I'm reading a book about anti-gravity. It's impossible to put down!",
    "I wondered why the baseball was getting bigger. Then it hit me.",
    "Knock, knock. Who's there? Interrupting cow. Interrupting cow wh-MOOOO!",
    "Skeletons can't play church music, obviously. They got no organs.",
    "Ultimately, Asgore ended up making Papyrus a nice hedge skullpture.",
    "A skeletal ape would be called a babone.",
    "Some of these puns aren't that hilarious, but come on, throw us a bone.",
    "A French Sans would greet you with the ol' bone-jour.",
    "I went to a party, and mettaton of new people.",
    "Sans has a reputation for being lazy. He's almost bone idle.",
    "The skeleton wanted a friend to talk to, he was feeling bonely.",
    "Looks like you had a rough day. But it's going tibia okay.",
    "I'm not a big fan of elevators, but I'll make an exception for you.",
    "A list of Sans' puns would be sans-tastic.",
    "She was Asgoregeous as the first day I'd seen her.",
    "But first, let me take a Skelfie.",
    "TEM AN JERRY s TORITOS",
    "Your spaghetti is impastable to eat",
    "I'm not lion, these puns are unbearable.",
    "I know I can be difficult at times. Hope you don't have a bone to pick with me.",
    "I have got a ton of work done today. A skele-ton.",
    "It's easy to tell when a skeleton is lying. You can see right through them.",
    "Sans' funniest pun is about what instrument he plays. A trom-bone.",
    "Sans is very calm, because nothing gets under his skin.",
    "Sans is quite funny. One could call him... humerus.",
    "Sans gave me a nice culinary presentation. 'Bone appetit', he said.",
    "Sans laughed for quite a while. The joke had really tickled his funny bone.",
    "Graveyards are so noisy. It's mostly all the coffin'.",
    "I knew where you'd go next. I felt it instinctively, I felt it in my bones.",
    "Sans doesn't need a telephone. He'd rather use a telebone.",
    "Papyrus was standing by the fire for too long. It turned him bone-dry.",
    "Sans is not overweight, he is just a little big-boned!",
    "A few days ago, a stray dog came and stole away Papyrus' left leg. You could say Papyrus wasn't left with a leg to stand on.",
    "There was once a very hard-working skeleton. He always worked himself down to the bone.",
    "Skulls are meant to be eternally single. They literally have no body.",
    "Mr Funny Bones' new stand-up set didn't elicit much applause. Most of his jokes were pretty bare-bones.",
    "Papyrus got mixed up with a biker gang. He's bad to the bone now.",
    "This Sans' puns list is getting pretty long, but we got a femur.",
    "Papyrus was oft-misunderstood as a child. The first track in his mixtape was Spooky Scary Skeletons.",
    "The skeleton did not invite his cousins over because he thought they were marrow-minded.",
    "A skewer kabob but with only bones is called kabones.",
    "The skeleton was great at dancing. He was a bone-a-fide opera star.",
    "I mistook the 3D hologram cow as the real deal. It looked Toriel.",
    "Papyrus does not like Sans' cooking. He doesn't have the stomach for it.",
    "Papyrus ran headfast into a windmill... he's such a bonehead.",
    "One could also call him a numbskull.",
    "The aquatic zoo was a bad place to go to. Turns out I hate Alphys.",
    "A skeleton's top restaurant order should be spare ribs.",
    "Me, I'm not lazy, I'm just bone idle.",
    "Papyrus had a dream about his motorcar. He describes it as an auto-body experience."
    "Why did Sans bring a ladder to the Snowdin forest? Because he wanted to see the tall skeleton trees!",
    "What's Sans's favorite kind of music? He's a big fan of 'bone' songs!",
    "How does Sans navigate the underground so well? He follows the 'undertail' signs!",
    "Why did Sans become a stand-up comedian? He wanted to make his audience 'skull'-pt with laughter!",
    "What does Sans do when he's not telling jokes? He's busy 'punsling' around!",
    "Why did Sans refuse to fight in Undertale? Because it was too 'rib-tickling' to be serious!",
    "How does Sans enjoy his spaghetti? He prefers it 'a skele-ton' of sauce!",
    "What's Sans's favorite card game? 'Pokerface-torials'!",
    "Why is Sans so good at avoiding attacks? He's a master of 'dodging responsibility'!",
    "Why did Sans give Papyrus a trombone? Because he wanted to hear some 'bone-chilling' music!",
    "What's Sans's favorite exercise? 'Skele-toning'!",
    "What did Sans say when he found a shortcut in the game? 'This is a real underpath'!",
    "Why did Sans go to Grillby's so often? He couldn't resist the 'cool' drinks!",
    "What's Sans's favorite holiday? Halloween – he gets to 'dress up' as himself!",
    "Why did Sans go to therapy? He wanted to 'bone up' on his mental health!",
    "What's Sans's favorite font? 'Comic Sans,' of course!",
    "Why is Sans a terrible gardener? Because he's always 'rooted' in the same spot!",
    "What do you call a Sans who loves puns? A 'punslinger'!",
    "Why did Sans bring a ladder to the library? Because he wanted to check out some 'skull-ture' books!",
    "What's Sans's favorite movie? 'The Bone Identity'!",
    "Why did Sans bring a plunger to the fight? He wanted to deal with 'spare-ty' issues!",
    "Why did Sans open a hotdog stand? He wanted to 'ketchup' with everyone!",
    "What do you get when you cross Sans with a dog? A 'bone-dog'!",
    "Why did Sans get locked out of his house? He lost his 'housekey-bone'!",
    "What does Sans say when he wins a race? 'I'm the fast-est skeleton around!'",
    "What's Sans's favorite game show? 'Wheel of Misfortune'!",
    "Why did Sans bring a spoon to the fight? He wanted to 'dish out' some justice!",
    "What does Sans use to fix his computer? A 'debug-ger'!",
    "Why did Sans go to the beach? He heard there were 'sandy' shores!",
    "What's Sans's favorite dessert? 'Skeleton pudding'!",
    "Why did Sans become a judge in the monster world? He wanted to give everyone a 'fair trial'!",
    "How did Sans become a comedian? He realized he was 'born' for it!",
    "What's Sans's favorite type of weather? 'Bone-chilling' cold!",
    "Why did Sans wear a winter coat in Hotland? He thought it was 'cool'!",
    "What's Sans's favorite dance move? The 'skele-ton shuffle'!",
    "Why did Sans bring a suitcase to Waterfall? He thought he'd need some 'bag-gage'!",
    "Why did Sans start a band with his brother? They wanted to be the 'bone-afide' music sensation!",
    "What's Sans's favorite place in the Underground? 'Sans'-tuary!",
    "What's Sans's favorite bedtime story? 'Goldi-locks and the Three Bears'!",
    "Why did Sans apply for a job as a lifeguard? He wanted to 'tide' people over during their swim!",
    "Why did Sans start a gardening club? He wanted to 'grow' the community!",
    "What's Sans's favorite type of bread? 'Sans'-wich bread!",
    "Why did Sans bring a guitar to the Mettaton show? He wanted to 'strum up' some excitement!",
    "What's Sans's favorite type of puzzle? A 'crossword'!",
    "Why did Sans challenge Papyrus to a cooking contest? He thought he could 'grill' him!",
    "What's Sans's favorite planet? 'Mars' – he heard it was 'red' hot!",
    "Why did Sans go to the costume party as a ghost? Because it was a 'boo'-last!",
    "What's Sans's favorite day of the week? 'Satur-day' – a day to relax!",
    "Why did Sans bring a plunger to Alphys's lab? He thought he could 'plunge' into science!",
    "What's Sans's favorite sport? 'Bonesketball' – he's a real 'slamdunk'!",
    "Why did Papyrus start a cooking blog? He wanted to share his 'pasta-bilities' with the world!",
    "What's Sans's favorite Shakespeare play? 'Much Ado About No-Bones'!",
    "Why did Sans apply for a job as a librarian? He heard the library had 'well-stacked' shelves!",
    "What's Sans's favorite board game? 'Bones and Ladders'!",
    "Why did Sans become a scientist? He wanted to 'ex-plore-iment' with determination!",
    "Why did Sans try out for the monster band? He wanted to 'rock out' with his 'socks out'!",
    "What's Sans's favorite type of cheese? 'Pun-mesan'!",
    "Why did Sans become a tour guide in Snowdin? He wanted to show visitors the 'skele-ton' of cool spots!",
    "What's Sans's favorite holiday destination? 'Sans Francisco'!",
    "Why did Sans bring a skateboard to the waterfall? He wanted to 'grind' the rails!",
    "What's Sans's favorite shape? The 'sans-gon'!",
    "Why did Sans open a comic book store in the underground? He wanted to 'ink-vite' people to enjoy some good reads!",
    "Why did Sans bring a kite to the windy cliffs of Waterfall? He thought it was the 'high'-point of fun!",
    "What's Sans's favorite season? 'Fall' – he loves the pun potential!",
    "Why did Sans start a pet store in Hotland? He wanted to offer 'hot' pets for sale!",
    "What's Sans's favorite dessert topping? 'Sans'-fudge!",
    "Why did Sans try out for the monster basketball team? He wanted to show his 'ball-titude'!",
    "Why did Sans bring a camera to the ruins? He thought he could 'shoot' for the stars!",
    "What's Sans's favorite video game? 'Boneshock'!",
    "Why did Sans bring a book of jokes to Grillby's? He wanted to 'spice' up the conversation!",
    "Why did Sans start a stand-up comedy night in Snowdin? He knew it was the 'pun'-ultimate experience!",
    "What's Sans's favorite phone app? 'Sans'-chat!",
    "Why did Sans start a magic show in the underground? He wanted to prove he was 'bone'-afide magician!",
    "What's Sans's favorite chess piece? The 'skele-king'!",
    "Why did Sans bring a magnifying glass to the Echo Flowers? He wanted to 'see-crets' in the messages!",
    "Why did Sans get a part-time job as a security guard? He wanted to show that he's the 'bone'-fide protector!",
    "What's Sans's favorite subject in school? 'Skeletonomics'!",
    "Why did Sans bring a map to the Ruins? He thought he could 'chart' a new course!",
    "What's Sans's favorite fruit? 'Cantaloupe-y'!",
    "Why did Sans start a support group for pun enthusiasts? He believed in 'punning' together!",
    "Why did Sans become a barista? He wanted to brew up some 'spooky-lattes'!",
    "What's Sans's favorite type of tea? 'Camomile-bone'!",
    "Why did Sans get a job as a meteorologist? He wanted to predict 'bony'-fide weather!",
    "What's Sans's favorite kind of fish? 'Skele-fish'!",
    "Why did Sans start a charity for lazybones? He knew the importance of 'bone-ating' to a good cause!",
    "What's Sans's favorite musical instrument? The 'skele-tone'!",
    "Why did Sans bring a broom to the MTT Resort? He thought he could 'sweep' the competition!",
    "What's Sans's favorite time of day? 'Sans-set'!",
    "Why did Sans start a band with Papyrus and Mettaton? They wanted to make it a 'trio-tastic' experience!",
    "What's Sans's favorite car? The 'Skeleton Coupe'!",
    "Why did Sans bring a telescope to the underground? He thought he could 'star'-t a new hobby!",
    "What's Sans's favorite board game to play with Papyrus? 'Operation' – they're great at 'bone removal'!",
    "Why did Sans become a detective? He loved 'unearth-ing' mysteries!",
    "What's Sans's favorite type of plant? 'Skele-tonias'!",
    "Why did Sans bring a surfboard to Snowdin? He heard the waves were 'bone-crushing'!",
    "What's Sans's favorite method of transportation? 'Sans-scooter'!",
    "Why did Sans open a comedy club in the underground? He knew that laughter was the 'bone'-afide way to happiness!",
    "What's Sans's favorite style of dancing? 'Skele-tonic'!",
    "Why did Sans bring a notebook to the water's edge in Waterfall? He thought he could 'jot' down some thoughts!",
    "What's Sans's favorite video game console? The 'GameBone'!"
};

// Inventory

typedef struct {
    int browniz, eggs, milk, ketchup, fries;
} Inventory;

Inventory inv = {0, 0, 0, 0, 0};

// Player position
int player_x = 30;
int player_y = 15;

// NPCs position and dialogue
int sans_x = 6;
int sans_y = 9;

int holy65_x = 59;
int holy65_y = 29;

int will_x = 58;
int will_y = 29;

const char* sans_dialogue = "Hello, I'm Sans. If ever you see ketchup, please bring it to me.";
const char* will_dialogue = "Miaw. Mow.";
const char* holy65_dialogue = "I am the creator. This is my cat *shows cat*. You can pet it.";

// Map symbols
const char EMPTY = '.';
const char PLAYER = 'P';
const char KETCHUP = 'k';

const char SANS = 'S';
const char WILL = 'C';
const char HOLY65 = 'H';

// Function to roll a random joke
const char* roll_joke() {
    int index = rand() % NUM_JOKES; // Randomly select a joke index
    return jokes[index];
}

// Function to draw the map
void draw_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int y, x;
    for (y = 0; y < MAP_HEIGHT; y++) {
        for (x = 0; x < MAP_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                printf("%c ", PLAYER);
            } else if (x == sans_x && y == sans_y) {
                printf("%c ", SANS);
            } else if (x == will_x && y == will_y) {
                printf("%c", WILL);
            } else if (x == holy65_x && y == holy65_y) {
                printf("%c", HOLY65);
            } else {
                printf("%c ", map[y][x]);
            }
        }
        printf("\n");
        
    }
}

char get_input() {
    char input;
    printf(">>> ");
    scanf(" %c", &input);
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

    // Place potions on the map (8)
    map[1][2] = KETCHUP;
    map[3][7] = KETCHUP;
    map[4][4] = KETCHUP;
    map[19][14] = KETCHUP;
    map[27][15] = KETCHUP;
    map[16][29] = KETCHUP;
    map[12][7] = KETCHUP;
    map[20][12] = KETCHUP;

    // Seed the random number generator with a fixed value
    srand(1534);

    richText("Welcome to FBD, the Joke Roller™! Featuring Creator, Cat and a skeleton.\n", KWHT, 1, 1, 1);
    richText("Use WASD to move, 'r' to roll for a joke, 't' to talk to the NPC, 'i' for inventory, c' for credits and 'q' to quit.\n", KWHT, 1, 1, 1);

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

            case 'r': // Roll for a joke
                {
                    const char* joke = roll_joke();
                    printf("> %s\n", joke);
                }
                break;

            case 't': // Talk to NPC 
                int determine;
                if (player_x == sans_x && player_y == sans_y) {
                    determine = 1;

                    // Give items
                    inv.fries++;
                    inv.ketchup--;
                } else if (player_x == will_x && player_y == will_y) {
                    determine = 2;
                } else if (player_x == holy65_x && player_y == holy65_y) {
                    determine = 3;
                } if (determine == 1) {
                    richText("Sans: ", KBLU, 1, 0, 0);
                    printf("%s\n", sans_dialogue);
                } else if (determine == 2) {
                    richText("Cat: ", KMAG, 1, 0, 0);
                    printf("%s\n", will_dialogue);
                    
                    // Give items
                    inv.browniz++;
                    inv.milk++;
                    inv.eggs++;
                    richText("*Zelda chest music* You got a browniz, milk and an egg !", KMAG, 1, 1, 0);

                } else if (determine == 3) {
                    richText("Creator: ", KRED, 1, 0, 0);
                    printf("%s\n", holy65_dialogue);

                } else {
                    printf("You are not near an NPC.\n");
                }
                break;

            case 'i':
                if (inv.browniz) printf("Brownies x %d\n", inv.browniz);
                if (inv.fries) printf("Fries x %d\n", inv.fries);
                if (inv.eggs) printf("Eggs x %d\n", inv.eggs);
                if (inv.ketchup) printf("Ketchup Bottles x %d\n", inv.browniz);
                if (inv.milk) printf("Milk Bricks x %d\n", inv.milk);

                break;

            case 'q': // Quit
                richText("", KCLS, 0, 0, 0);
                richText("* I'm outta here.\n", KRED, 1, 1, 0);
                return 0;
                break;

            case 'c':
                richText("Developer : Holy65; Ideas : Holy65 and Maram Arouay.\n", KWHT, 1, 0, 0);
                break;

            case 'kampf':
                printf("https://dn790000.ca.archive.org/0/items/mein-kampf-by-adolf-hitler-ralph-manheim-translation/Mein%20Kampf%20by%20Adolf%20Hitler%20-%20Ralph%20Manheim%20Translation.pdf\n");
                break;
            case 'manifesto':
                printf("https://www.marxists.org/admin/books/manifesto/Manifesto.pdf\n");
                break;
            case 'pastebin':
                printf("https://pastebin.com/fzhnL6yf");
            default:
                printf("Invalid input. Use WASD to move, 'r' to roll, 't' to talk, and 'q' to quit.\n");
                break;
        }

        // Check for ketchup collection
        if (map[player_y][player_x] == KETCHUP) {
            map[player_y][player_x] = EMPTY;
            printf("You found ketchup.\n");
            inv.ketchup++;
            if (inv.ketchup == 2) {
                richText("Sans : *heavy, fat american breathing* I SAID GIMMEEEE\n", KBLU, 0, 0, 0);
            } else if (inv.ketchup == 7) {
                richText("Sans : At this point I'm concerned for your health.\n", KBLU, 0, 0, 0);
            } else if (inv.ketchup == 8) {
                richText("Sans : Alright. Step back and givbe me a straw.\n", KBLU, 0, 0, 0);
            } else if (inv.ketchup == 100) {
                printf("Creator : CHEATER\n", KGRN, 1, 1, 1);
            }
        }

    }

    return 0;
}
