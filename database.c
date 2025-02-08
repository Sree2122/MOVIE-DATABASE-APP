#ifndef DATABASE_H
#define DATABASE_H

#include "movie.h"

typedef struct Node {
    Movie *movie; // Pointer to a Movie struct
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} MovieDatabase;

MovieDatabase *create_movie_database();
void add_movie(MovieDatabase *db, Movie *movie); // Takes a Movie pointer
void list_movies(const MovieDatabase *db);
void search_movie(const MovieDatabase *db, const char *title);
void remove_movie(MovieDatabase *db, const char *title);
void sort_movies(MovieDatabase *db);
void save_movies(const MovieDatabase *db, const char *filename);
void load_movies(MovieDatabase *db, const char *filename);
void free_movie_database(MovieDatabase *db);

#endif