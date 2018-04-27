#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PROGRAM "craps"
#define VERSION "0.1.0"

#define PASS     1
#define NOT_PASS 2

void printHelp()
{
    printf("Usage: %s [-q] [right|wrong]\n"
           "Default to right\n\n"
           "Parameters:\n"
           "\t-v, --version:\tVersion info\n"
           "\t-h, --help:\tHelp message\n"
           "\t-q, --quiet:\tQuiet mode\n", PROGRAM);
}

int main(int argc, char *argv[])
{
    short bet;
    bool verbose = true;  // Flag for verbose message.

    // Parse command-line arguments without any library.
    // Run without any argument. Default to *pass* bet.
    if (argc == 1) {
        bet = PASS;
    }
    // Run with one or more argument.
    else if (argc >= 2) {
        // Print version info and exit.
        if (strcmp(argv[1], "-v") == 0 ||
            strcmp(argv[1], "--version") == 0) {
            printf("%s\n", VERSION);
            return EXIT_SUCCESS;
        }
        // Print help message and exit.
        else if (strcmp(argv[1], "-h") == 0 ||
            strcmp(argv[1], "--help") == 0) {
            printHelp();
            return EXIT_SUCCESS;
        }
        // Run in quiet mode.
        else if (strcmp(argv[1], "-q") == 0 ||
            strcmp(argv[1], "--quiet") == 0) {
            verbose = false;

            // Default to *pass* bet.
            if (argc == 2) {
                bet = PASS;
            }
            // Choose either *pass* or *no pass* bet.
            else if (argc >= 3) {
                // Choose *pass* bet.
                if (strcmp(argv[2], "right") == 0) {
                    bet = PASS;
                }
                // Choose *no pass* bet.
                else if (strcmp(argv[2], "wrong") == 0) {
                    bet = NOT_PASS;
                }
                // Invalid argument.
                // Exit the program with both error and help message.
                else {
                    fprintf(stderr, "Wrong arguments\n");
                    printHelp();
                    return EXIT_FAILURE;
                }
            }
        }
        // Choose *pass* bet.
        else if (strcmp(argv[1], "right") == 0) {
            bet = PASS;
        }
        // Choose *no pass* bet.
        else if (strcmp(argv[1], "wrong") == 0) {
            bet = NOT_PASS;
        }
        // Invalid argument.
        // Exit the program with both error and help message.
        else {
            fprintf(stderr, "Wrong arguments\n");
            printHelp();
            return EXIT_FAILURE;
        }
    }

    // Init a rand seed by current system time.
    srand((unsigned) time(NULL));

    short a, b;
    short result;
    bool over = false;

    // Come-out roll.
    a = rand() % 6 + 1;
    b = rand() % 6 + 1;
    short comeOut = a + b;

    if (verbose) {
        printf("Come-out roll: %d + %d = %d\n", a, b, comeOut);
    }

    // Craps: *no pass*. End the game.
    if (comeOut== 2 || comeOut == 3 || comeOut == 12) {
        if (verbose) {
            printf("Craps\n");
        }
        result = NOT_PASS;
        over = true;
    }
    // Natural: *pass*. End the game.
    else if (comeOut == 7) {
        if (verbose) {
            printf("Natural\n");
        }
        result = PASS;
        over = true;
    }

    short sum;
    // Point roll
    while (!over) {
        a = rand() % 6 + 1;
        b = rand() % 6 + 1;
        sum = a + b;
        // Hit: *pass*. End the game.
        if (sum == comeOut) {
            if (verbose) {
                printf("Hit: %d + %d = %d\n", a, b, sum);
            }
            result = PASS;
            over = true;
        }
        // Seven-out: *no pass*. End the game.
        else if (sum == 7) {
            if (verbose) {
                printf("Seven-out: %d + %d = %d\n", a, b, sum);
            }
            result = NOT_PASS;
            over = true;
        }
        // Keep rolling.
        else {
            if (verbose) {
                printf("Got %d + %d = %d. Try again...\n", a, b, sum);
            }
        }
    }

    // Report the game result/
    if (bet == result) {
        if (verbose) {
            printf("The player wins\n");
        } else {
            printf("win\n");
        }
    } else {
        if (verbose) {
            printf("The player loses\n");
        } else {
            printf("lose\n");
        }
    }

    return EXIT_SUCCESS;
}
