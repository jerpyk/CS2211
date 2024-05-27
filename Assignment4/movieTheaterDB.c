/*Program Name: movieTheaterDB.c
Program Description: The program implements a database of all movies shown at the theater.
Author: Eunsung Kim, 251275156*/

// Directives
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

// Define lengths of the strings
#define MOVIE_LEN 100
#define NAME_LEN 100
#define GENRE_LEN 25

// Structure for each movie
typedef struct
{
    int code;
    char name[NAME_LEN];
    char genre[GENRE_LEN];
    float rating;
} Movie;

// gloabl variable 
Movie movie[MOVIE_LEN];

// function prototypes
void printMovie(int);
void printMovieTable(int);

// Main method
int main(void)
{
    // local variables
    char op;
    int movieCode;
    char movieName[NAME_LEN];
    char movieGenre[GENRE_LEN];
    float movieRating;
    bool movieFound = false;

    printf("*********************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("*********************\n");

    // repeat until the user quits
    for (int i = 0;;)
    {
        // Get operation code
        printf("\nEnter operation code (i = insert, s = search, u = update, p = print, q = quit): ");
        // receive input
        scanf(" %c", &op);
        switch (op)
        {
        // INSERT A NEW MOVIE
        case 'i':
            // Get movie code
            printf("\tEnter movie code: ");
            scanf("%d", &movieCode);
            // error handling for codes below 0
            if (movieCode < 0)
            {
                printf("Invalid code, must be over 0.\n");
                break;
            }
            // traverse the array of movie structure and check if it already exists
            for (int j = 0; j < i; j++)
            {
                if (movie[j].code == movieCode)
                {
                    printf("Movie already exists.\n");
                    movieFound = true;
                    break;
                }
            }
            // return to main menu if the movie is found
            if (movieFound)
            {
                movieFound = false;
                break;
            }
            // set movie code
            movie[i].code = movieCode;

            // Get movie name
            printf("\tEnter movie name: ");
            // fgetc to remove the \n in the buffer from scanf
            fgetc(stdin);
            fgets(movieName, NAME_LEN, stdin);
            movieName[strlen(movieName) - 1] = 0;
            // error handling, error has occurred if errno is not 0
            if (errno != 0)
            {
                perror("There was an error");
                break;
            }
            // set movie name with string copy method
            strcpy(movie[i].name, movieName);

            // Get movie genre
            printf("\tEnter movie genre: ");
            fgets(movieGenre, GENRE_LEN, stdin);
            movieGenre[strlen(movieGenre) - 1] = 0;
            if (errno != 0)
            {
                perror("There was an error");
                break;
            }
            // set movie genre
            strcpy(movie[i].genre, movieGenre);

            // Get movie rating
            printf("\tEnter movie rating: ");
            scanf("%f", &movieRating);
            if (movieRating < 0.0 || movieRating > 10.0)
            {
                printf("Invalid rating. Try again.\n");
                break;
            }
            // set movie rating
            movie[i].rating = movieRating;

            // Increase the array element index and break
            i++;
            break;

        // SEARCH FOR A MOVIE
        case 's':
            printf("\tEnter movie code: ");
            scanf("%d", &movieCode);
            // traverse through movie array to check if the movie is present
            for (int j = 0; j < i; j++)
            {
                if (movie[j].code == movieCode)
                {
                    printMovie(j);
                    movieFound = true;
                    break;
                }
            }
            // if not then return to main menu
            if (!movieFound)
            {
                printf("Movie not found.\n");
            }
            movieFound = false;
            break;
        //UPDATE MOVIE
        case 'u':
            // Get movie code
            printf("\tEnter movie code: ");
            scanf("%d", &movieCode);
            int j;
            // traverse through the movie array to find the movie to update
            for (j = 0; j < i; j++)
            {
                if (movie[j].code == movieCode)
                {
                    movieFound = true;
                    break;
                }
            }
            // if it does not exist, return to main menu
            if (!movieFound)
            {
                printf("Movie to update not found.\n");
                break;
            }
            // Get movie name
            printf("\tEnter movie name: ");
            fgetc(stdin);
            fgets(movieName, NAME_LEN, stdin);
            movieName[strlen(movieName) - 1] = 0;
            // error has occurred if errno is not 0
            if (errno != 0)
            {
                perror("There was an error\n");
                break;
            }
            strcpy(movie[j].name, movieName);

            // Get movie genre
            printf("\tEnter movie genre: ");
            fgets(movieGenre, GENRE_LEN, stdin);
            movieGenre[strlen(movieGenre) - 1] = 0;
            if (errno != 0)
            {
                perror("There was an\n");
                break;
            }
            strcpy(movie[j].genre, movieGenre);

            // Get movie rating
            printf("\tEnter movie rating: ");
            scanf("%f", &movieRating);
            if (movieRating < 0.0 || movieRating > 10.0)
            {
                printf("Invalid rating.\n");
                break;
            }
            movie[j].rating = movieRating;
            break;
        // PRINT MOVIE LIST TABLE
        case 'p':
            printMovieTable(i);
            break;
        // QUIT
        case 'q':
            exit(0);
        }
    }
    return 0;
}

// Function to print out one movie in the database at index i
void printMovie(int i)
{
    printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
    // format with format specifiers
    printf("%-13d%-32s%-26s%-12.1f\n", movie[i].code, movie[i].name,
           movie[i].genre, movie[i].rating);
}

// Function to print out the movie table up to index i
void printMovieTable(int i)
{
    printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
    for (int j = 0; j < i; j++)
    {
            // format with format specifiers

        printf("%-13d%-32s%-26s%-12.1f\n", movie[j].code, movie[j].name,
               movie[j].genre, movie[j].rating);
    }
}