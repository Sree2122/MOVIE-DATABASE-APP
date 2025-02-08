#ifndef MOVIE_H
#define MOVIE_H

#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
} Movie;

#endif