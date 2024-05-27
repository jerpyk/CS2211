#ifndef MOVIETHEATERDB_MOVIE_H
#define MOVIETHEATERDB_MOVIE_H

// maximum length for movie name
#define MOVIE_NAME_LEN 100
// maximum length for movie genre
#define MOVIE_GENRE_LEN 25
// function for inserting a movie by taking in the first node of the movie linked list
// it returns the new first node of the list after the insertion
struct movieNode *insertMovie(struct movieNode *list);
// function for searching and printing the output for that movie by taking in the first node of the linked list
void searchMovie(struct movieNode *list);
// funciton for updating a movie by taking in the first node of the linked list
void updateMovie(struct movieNode *list);
// function for printing all movies in the linked list movie database
void printMovie(struct movieNode *list);
//function for removing a movie by taking in the first node of the movie linked list
// it returns the new first node of thel ist after the removal
struct movieNode *removeMovie(struct movieNode *list);

#endif