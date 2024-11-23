#include <string.h>
#include <stdio.h>
#include "include/joke.h"
#include "include/cute_airlib.h"

// Konami Code and wrong commands
int wrong_cmd;
char konami_code[] = "uuddlrlrba";

int time_local(void) {
    float t = getGameTime();
    return t;
}

int main(void) {

    errorLog("To properly understand those joke, you need to play Undertale.\n", 0, 0, 1);

    char output[10];
    while (1) {

        if (wrong_cmd == 20) {
            printf("RTFM!\n");
        } else if (wrong_cmd == 30) {
            printf("Hey, it's 30 wrong commands. There's a help command int the program.\n");
        } else if (wrong_cmd == 30) {
            printf("You're driving a program insane.\n");
        } else if (wrong_cmd == 40) {
            printf("Stop it.\n");
        } else if (wrong_cmd == 50) {
            printf("I'm warning you.\n");
        } else if (wrong_cmd == 60) {
            printf("Okay, make as many errors as you want.\n");
        } else if (wrong_cmd == 100) {
            richText("Where are the Knives ?", KRED, 1, 0, 0);
        }

        placeholder("joke, time, exit", output, sizeof(output));

        if (strcmp(output, "help") == 0) {
            errorLog("joke, time, exit \n", 0, 0, 1);
        } else if (strcmp(output, "joke") == 0) {
            joke();
        } else if (strcmp(output, "name") == 0) {
            richText("Useless info.\n", KRED, 0,0,1);
        } else if (strcmp(output, "exit") == 0) {
            richText("* I'm outta here.\n", KRED, 1, 1, 1);
            break;
        } else if (strcmp(output, "time") == 0) {
            time_local();
        } else if (strcmp(output, konami_code) == 0) {
            printf("https://pastebin.com/v4vtCuC3\n");
            printf("3310\n");
            printf("Unicode\n");
        } else if (strcmp(output, "cpp") == 0) {
            segFault();
        } else {
            wrong_cmd++;
            printf("Unknown command!\n");
        }
    }

    exit(0);
}
