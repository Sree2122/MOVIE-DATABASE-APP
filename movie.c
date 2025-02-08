#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int main() {
    MovieDatabase *db = create_movie_database();
    load_movies(db, "movies.dat");

    int choice;
    while (1) {
        printf("\nMovie Database Menu:\n");
        printf("1. Add Movie\n");
        printf("2. List Movies\n");
        printf("3. Search Movie by Title\n");
        printf("4. Remove Movie\n");
        printf("5. Sort Movies by Title\n");
        printf("6. Save Movies\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: {
                Movie *movie = (Movie *)malloc(sizeof(Movie)); // Allocate memory for the movie
                printf("Enter title: ");
                fgets(movie->title, sizeof(movie->title), stdin);
                movie->title[strcspn(movie->title, "\n")] = 0;
                printf("Enter genre: ");
                fgets(movie->genre, sizeof(movie->genre), stdin);
                movie->genre[strcspn(movie->genre, "\n")] = 0;
                printf("Enter year: ");
                scanf("%d", &movie->year);
                getchar(); // Consume newline
                add_movie(db, movie); // Pass the allocated movie pointer
                free(movie); // Free the memory after adding it to the database
                break;
            }
            case 2:
                list_movies(db);
                break;
            case 3: {
                char title[100];
                printf("Enter title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                search_movie(db, title);
                break;
            }
            case 4: {
                char title[100];
                printf("Enter title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                remove_movie(db, title);
                break;
            }
            case 5:
                sort_movies(db);
                printf("Movies sorted by title.\n");
                break;
            case 6:
                save_movies(db, "movies.dat");
                printf("Movies saved.\n");
                break;
            case 7:
                free_movie_database(db);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}