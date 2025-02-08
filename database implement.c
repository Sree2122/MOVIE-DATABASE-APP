#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

MovieDatabase *create_movie_database() {
    MovieDatabase *db = (MovieDatabase *)malloc(sizeof(MovieDatabase));
    db->head = NULL;
    db->count = 0;
    return db;
}

void add_movie(MovieDatabase *db, Movie *movie) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->movie = movie; // Store the movie pointer
    new_node->next = NULL;

    if (db->head == NULL) {
        db->head = new_node;
    } else {
        Node *current = db->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    db->count++;
}

void list_movies(const MovieDatabase *db) {
  if (db->count == 0) {
    printf("Movie database is empty.\n");
    return;
  }
  Node *current = db->head;
  for (int i = 0; i < db->count; i++) {
    printf("%d. Title: %s, Genre: %s, Year: %d\n", i + 1, current->movie->title, current->movie->genre, current->movie->year);
    current = current->next;
  }
}

void search_movie(const MovieDatabase *db, const char *title) {
    Node *current = db->head;
    while (current != NULL) {
        if (strcmp(current->movie->title, title) == 0) {
            printf("Movie found: Title: %s, Genre: %s, Year: %d\n", current->movie->title, current->movie->genre, current->movie->year);
            return;
        }
        current = current->next;
    }
    printf("Movie not found.\n");
}

void remove_movie(MovieDatabase *db, const char *title) {
  Node *current = db->head;
  Node *prev = NULL;

  while (current != NULL && strcmp(current->movie->title, title) != 0) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Movie not found.\n");
    return;
  }

  if (prev == NULL) {
    db->head = current->next;
  } else {
    prev->next = current->next;
  }

  free(current->movie); // Free the movie data
  free(current); // Free the node
  db->count--;
  printf("Movie removed.\n");
}


// Simple bubble sort (for demonstration - you can use a better sorting algorithm)
void sort_movies(MovieDatabase *db) {
    if (db->count <= 1) return; // Nothing to sort

    for (int i = 0; i < db->count - 1; i++) {
        Node *current = db->head;
        Node *prev = NULL;
        int swaps = 0;
        for (int j = 0; j < db->count - i - 1; j++) {
            if (strcmp(current->movie->title, current->next->movie->title) > 0) {
                // Swap nodes
                if (prev == NULL) {
                    db->head = current->next;
                } else {
                    prev->next = current->next;
                }
                current->next->next = current;
                current->next = NULL;
                swaps++;
            }
            prev = current;
            current = current->next;
        }
        if (swaps == 0) break; // Optimization: If no swaps, list is sorted
    }
}


void save_