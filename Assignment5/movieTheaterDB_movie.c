/*Program Name: movieTheaterDB.c
Program Description: The program implements a database of all movies shown at the theater.
Author: Eunsung Kim, 251275156*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "movieTheaterDB_movie.h"

// linked list node for movie
struct movieNode
{
    int code;
    char name[MOVIE_NAME_LEN];
    char genre[MOVIE_GENRE_LEN];
    float rating;
    struct movieNode *next;
};

// Returns the inserted node, which is the new head with the pointer to the head of the list
struct movieNode *insertMovie(struct movieNode *list)
{
    struct movieNode *newMovie;
    newMovie = (struct movieNode *)malloc(sizeof(struct movieNode));
    if (newMovie == NULL)
    {
        printf("Error: malloc failed.\n");
        return list;
    }
    // Get movie code
    printf("\tEnter movie code: ");
    scanf("%d", &newMovie->code);
    // error handling for codes below 0
    if (newMovie->code < 0)
    {
        printf("Invalid code, must be over 0.\n");
        return list;
    }
    struct movieNode *currMovie = list;
    // traverse the array of movie structure and check if it already exists
    while (currMovie != NULL && currMovie->code != newMovie->code)
    {
        currMovie = currMovie->next;
    }
    // return to main menu if the movie is found
    if (currMovie != NULL)
    {
        printf("Movie already exists.\n");
        free(newMovie);
        return list;
    }
    // Get movie name
    printf("\tEnter movie name: ");
    // fgetc to remove the \n in the buffer from scanf
    fgetc(stdin);
    fgets(newMovie->name, MOVIE_NAME_LEN, stdin);
    newMovie->name[strlen(newMovie->name) - 1] = '\0';
    // error handling, error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        free(newMovie);
        return list;
    }
    // Get movie genre
    printf("\tEnter movie genre: ");
    fgets(newMovie->genre, MOVIE_GENRE_LEN, stdin);
    newMovie->genre[strlen(newMovie->genre) - 1] = '\0';
    if (errno != 0)
    {
        perror("There was an error\n");
        free(newMovie);
        return list;
    }
    // Get movie rating
    printf("\tEnter movie rating: ");
    scanf("%f", &newMovie->rating);
    if (newMovie->rating < 0.0 || newMovie->rating > 10.0)
    {
        printf("Invalid rating. Try again.\n");
        free(newMovie);
        return list;
    }
    // Put the new movie node in the front of the list
    newMovie->next = list;
    return newMovie;
}

// SEARCH FOR A MOVIE
void searchMovie(struct movieNode *list)
{
    int movieCode;
    printf("\tEnter movie code: ");
    scanf("%d", &movieCode);
    // traverse through movie array to check if the movie is present
    while (list != NULL && list->code != movieCode)
    {
        list = list->next;
    }
    // if not then return to main menu
    if (list == NULL)
    {
        printf("Movie not found.\n");
        return;
    }
    else
    {
        struct movieNode *currMovie = list;
        printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
        // format with format specifiers
        printf("%-13d%-32s%-26s%-12.1f\n", currMovie->code, currMovie->name, currMovie->genre, currMovie->rating);
    }
}
// UPDATE MOVIE
void updateMovie(struct movieNode *list)
{
    int movieCode;
    printf("\tEnter movie code: ");
    scanf("%d", &movieCode);
    // traverse through movie array to check if the movie is present
    struct movieNode *currMovie = list;
    while (currMovie != NULL && currMovie->code != movieCode)
    {
        currMovie = currMovie->next;
    }
    // if not then return to main menu
    if (currMovie == NULL)
    {
        printf("Movie not found.\n");
        return;
    }
    // Get movie name
    char movieName[MOVIE_NAME_LEN];
    printf("\tEnter movie name: ");
    fgetc(stdin);
    fgets(movieName, MOVIE_NAME_LEN, stdin);
    movieName[strlen(movieName) - 1] = '\0';
    // error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        return;
    }
    // Get movie genre
    char movieGenre[MOVIE_GENRE_LEN];
    printf("\tEnter movie genre: ");
    fgets(movieGenre, MOVIE_GENRE_LEN, stdin);
    movieGenre[strlen(movieGenre) - 1] = '\0';
    if (errno != 0)
    {
        perror("There was an error\n");
        return;
    }
    // Get movie rating
    float movieRating;
    printf("\tEnter movie rating: ");
    scanf("%f", &movieRating);
    if (movieRating < 0.0 || movieRating > 10.0)
    {
        printf("Invalid rating.\n");
        return;
    }
    // Update name, genre, and rating of the movie
    currMovie->code = movieCode;
    strcpy(currMovie->name, movieName);
    strcpy(currMovie->genre, movieGenre);
    currMovie->rating = movieRating;
}

// PRINT MOVIE LIST TABLE
void printMovie(struct movieNode *list)
{
    printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
    while (list != NULL)
    {
        printf("%-13d%-32s%-26s%-12.1f\n", list->code, list->name, list->genre, list->rating);
        list = list->next;
    }
}
// Removes the selected actor and returns the new first node of the movie linked list
struct movieNode *removeMovie(struct movieNode *list)
{
    int movieCode;
    printf("\tEnter movie code: ");
    scanf("%d", &movieCode);
    // traverse through movie array to check if the movie is present
    struct movieNode *currMovie, *prevMovie;
    for (currMovie = list, prevMovie = NULL;
         currMovie != NULL && currMovie->code != movieCode;
         prevMovie = currMovie, currMovie = currMovie->next)
        ;
    // if movieCode does not match any of the movieNode
    if (currMovie == NULL)
    {
        printf("Movie not found.\n");
        return list;
    }
    // if movieCode matches the code of the first movieNode
    if (prevMovie == NULL)
    {
        list = list->next;
    }
    // if movieCode matches the code other than the first movieNode
    else
    {
        prevMovie->next = currMovie->next;
    }
    printf("Movie successfully erased.\n");
    free(currMovie);
    return list;
}