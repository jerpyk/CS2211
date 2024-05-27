/*Program Name: actorTheaterDB.c
Program Description: The program implements a database of all actors shown at the theater.
Author: Eunsung Kim, 251275156*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "movieTheaterDB_actor.h"

// linked list node for actor
struct actorNode
{
    int code;
    char name[ACTOR_NAME_LEN];
    int age;
    char page[ACTOR_PAGE_LEN];
    struct actorNode *next;
};

// Returns the inserted node, which is the new head with the pointer to the new head of the list
struct actorNode *insertActor(struct actorNode *list)
{
    struct actorNode *newActor;
    newActor = (struct actorNode *)malloc(sizeof(struct actorNode));
    if (newActor == NULL)
    {
        printf("Error: malloc failed.\n");
        return list;
    }
    // Get actor code
    printf("\tEnter actor code: ");
    scanf("%d", &newActor->code);
    // error handling for codes below 0
    if (newActor->code < 0)
    {
        printf("Invalid code, must be over 0.\n");
        return list;
    }
    struct actorNode *currActor = list;
    // traverse the array of actor structure and check if it already exists
    while (currActor != NULL && currActor->code != newActor->code)
    {
        currActor = currActor->next;
    }
    // return to main menu if the actor is found
    if (currActor != NULL)
    {
        printf("Actor already exists.\n");
        free(newActor);
        return list;
    }
    // Get actor name
    printf("\tEnter actor name: ");
    // fgetc to remove the \n in the buffer from scanf
    fgetc(stdin);
    fgets(newActor->name, ACTOR_NAME_LEN, stdin);
    newActor->name[strlen(newActor->name) - 1] = '\0';
    // error handling, error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        free(newActor);
        return list;
    }
    // Get actor age
    printf("\tEnter actor age: ");
    scanf("%d", &newActor->age);
    if (newActor->age < 0 || newActor->age > 120)
    {
        printf("Invalid age. Has to be 0-120.\n");
        free(newActor);
        return list;
    }
    // Get actor IMDB profile page
    printf("\tEnter actor IMDB profile page: ");
    fgetc(stdin);
    fgets(newActor->page, ACTOR_PAGE_LEN, stdin);
    newActor->page[strlen(newActor->page) - 1] = '\0';
    // error handling, error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        free(newActor);
        return list;
    }
    // Put the new actor node in the front of the list
    newActor->next = list;
    return newActor;
}

// Searches for an actor and prints out all the information about the actor
void searchActor(struct actorNode *list)
{
    int actorCode;
    printf("\tEnter actor code: ");
    scanf("%d", &actorCode);
    // traverse through actor array to check if the actor is present
    while (list != NULL && list->code != actorCode)
    {
        list = list->next;
    }
    // if not then return to main menu
    if (list == NULL)
    {
        printf("Actor not found.\n");
        return;
    }
    else
    {
        struct actorNode *currActor = list;
        printf("Actor Code   Actor Name                      Actor Age    Actor Page\n");
        // format with format specifiers
        printf("%-13d%-32s%-13d%-26s\n", currActor->code, currActor->name, currActor->age, currActor->page);
    }
}
// Updates all the information about the actor with the selected code
void updateActor(struct actorNode *list)
{
    int actorCode;
    printf("\tEnter actor code: ");
    scanf("%d", &actorCode);
    // traverse through actor linked list to check if the actor is present
    struct actorNode *currActor = list;
    while (currActor != NULL && currActor->code != actorCode)
    {
        currActor = currActor->next;
    }
    // if not then return to main menu
    if (currActor == NULL)
    {
        printf("Actor not found.\n");
        return;
    }
    // Get actor name
    char actorName[ACTOR_NAME_LEN];
    printf("\tEnter actor name: ");
    fgetc(stdin);
    fgets(actorName, ACTOR_NAME_LEN, stdin);
    actorName[strlen(actorName) - 1] = '\0';
    // error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        return;
    }
    // Get actor genre
    int actorAge;
    printf("\tEnter actor age: ");
    scanf("%d", &actorAge);
    if (actorAge < 0 || actorAge > 120)
    {
        printf("Invalid age. Has to be 0-120.\n");
        return;
    }
    // Get actor IMDB profile page
    char actorPage[ACTOR_PAGE_LEN];
    printf("\tEnter actor IMDB profile page: ");
    fgetc(stdin);
    fgets(actorPage, ACTOR_PAGE_LEN, stdin);
    actorPage[strlen(actorPage) - 1] = '\0';
    // error handling, error has occurred if errno is not 0
    if (errno != 0)
    {
        perror("There was an error\n");
        return;
    }
    // Update name, genre, and rating of the actor
    currActor->code = actorCode;
    strcpy(currActor->name, actorName);
    currActor->age = actorAge;
    strcpy(currActor->page, actorPage);
}

// PRINT ACTOR LIST TABLE
void printActor(struct actorNode *list)
{
    // format with format specifiers
    printf("Actor Code   Actor Name                      Actor Age    Actor Page\n");
    while (list != NULL)
    {
        printf("%-13d%-32s%-13d%-26s\n", list->code, list->name, list->age, list->page);
        list = list->next;
    }
}

// Removes the selected actor and returns the new first node of the actor linked list
struct actorNode *removeActor(struct actorNode *list)
{
    int actorCode;
    printf("\tEnter actor code: ");
    scanf("%d", &actorCode);
    // traverse through actor array to check if the actor is present
    struct actorNode *currActor, *prevActor;
    for (currActor = list, prevActor = NULL;
         currActor != NULL && currActor->code != actorCode;
         prevActor = currActor, currActor = currActor->next)
        ;
    // if actorCode does not match any of the actorNode
    if (currActor == NULL)
    {
        printf("Actor not found.\n");
        return list;
    }
    // if actorCode matches the code of the first actorNode
    if (prevActor == NULL)
    {
        list = list->next;
    }
    // if actorCode matches the code other than the first actorNode
    else
    {
        prevActor->next = currActor->next;
    }
    printf("Actor successfully erased.\n");
    free(currActor);
    return list;
}