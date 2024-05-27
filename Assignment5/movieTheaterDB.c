/*Program Name: movieTheaterDB.c
Program Description: The program uses functions for movies and actors databases by depending on the header file.
Author: Eunsung Kim, 251275156*/

#include <stdio.h>
#include <stdlib.h>
#include "movieTheaterDB.h"

// main function for the execution of the program
int main(void)
{
    // local variables
    struct movieNode *movieFirst = NULL; // first nod
    struct actorNode *actorFirst = NULL;
    char op;
    int movieCode;
    char movieName[MOVIE_NAME_LEN];
    char movieGenre[MOVIE_GENRE_LEN];
    float movieRating;

    printf("*********************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("*********************\n");
    for (;;)
    {
        // Get operation code
        printf("\nEnter operation code (h = help, q = quit, m = movie, a = actor): ");
        // receive input
        scanf(" %c", &op);
        switch (op)
        {
        case 'h':
            printf("Enter one of the listed commands and follow the prompt instructions.\n");
            printf("If entered m, the commands are for database of movies.\n");
            printf("If entered a, the commands are for database of actors.\n");
            break;
        // q = EXIT
        case 'q':
            exit(0);
        // m = OPERATION FOR MOVIES
        case 'm':
            // Get operation code
            printf("\nEnter operation code (i = insert, s = search, u = update, p = print, e = erase): ");
            // receive input
            scanf(" %c", &op);
            switch (op)
            {
            // INSERT A NEW MOVIE
            case 'i':
                movieFirst = insertMovie(movieFirst);
                break;
            // SEARCH FOR A MOVIE
            case 's':
                searchMovie(movieFirst);
                break;
            // UPDATE MOVIE
            case 'u':
                updateMovie(movieFirst);
                break;
            // PRINT MOVIE LIST TABLE
            case 'p':
                printMovie(movieFirst);
                break;
            // REMOVE A MOVIE
            case 'e':
                movieFirst = removeMovie(movieFirst);
                break;
            default:
                printf("Invalid command.\n");
            }
            break;
        // a = OPERATIONS FOR ACTORS
        case 'a':
            // Get operation code
            printf("\nEnter operation code (i = insert, s = search, u = update, p = print, e = erase): ");
            // receive input
            scanf(" %c", &op);
            switch (op)
            {
            // INSERT A NEW MOVIE
            case 'i':
                actorFirst = insertActor(actorFirst);
                break;
            // SEARCH FOR A MOVIE
            case 's':
                searchActor(actorFirst);
                break;
            // UPDATE MOVIE
            case 'u':
                updateActor(actorFirst);
                break;
            // PRINT MOVIE LIST TABLE
            case 'p':
                printActor(actorFirst);
                break;
            // REMOVE A MOVIE
            case 'e':
                actorFirst = removeActor(actorFirst);
                break;
            default:
                printf("Invalid command.\n");
            }
            break;
        default:
            printf("Invlaid commnad.\n");
        }
    }
}
