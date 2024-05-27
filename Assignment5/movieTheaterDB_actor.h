#ifndef MOVIETHEATERDB_ACTOR_H
#define MOVIETHEATERDB_ACTOR_H {

// maximum length for actor name
#define ACTOR_NAME_LEN 50
// maximum length for IMDB profile page
#define ACTOR_PAGE_LEN 50
// function for inserting an actor by taking in the first node of the actor linked list
// it returns the new first node of the list after the insertion
struct actorNode *insertActor(struct actorNode *list);
// function for searching and printing the information the actor by taking in the first node of the linked list
void searchActor(struct actorNode *list);
// function for updating an actor by taking in the first node of the linked list
void updateActor(struct actorNode *list);
// function for printing all movies in the linked list actor database
void printActor(struct actorNode *list);
//function for removing an acotr by taking in the first node of the actor linked list
// it returns the new first node of thel ist after the removal
struct actorNode *removeActor(struct actorNode *list);

}
#endif