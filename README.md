# Simple Movie Database Application in C

This repository contains a simple movie database application written in C. It allows you to store, list, search, remove, sort, and save movie information.

## Usage

1. Clone the repository: `git clone https://github.com/your_username/movie_database_c.git`
2. Navigate to the directory: `cd movie_database_c`
3. Compile the code: `make` (or `gcc main.c movie.c database.c -o movie_database`)
4. Run the application: `./movie_database`

## Features

- **Add Movie:** Add a new movie to the database (title, genre, year).
- **List Movies:** Display all movies in the database.
- **Search Movie:** Search for a movie by title.
- **Remove Movie:** Remove a movie from the database by title.
- **Sort Movies:** Sort the movies alphabetically by title.
- **Save Movies:** Save the movie database to a file (`movies.dat`).
- **Load Movies:** Load the movie database from a file (`movies.dat` - this happens automatically when the program starts).

## Data Storage

Movie data is stored in a file named `movies.dat`.  The file is loaded when the program starts and saved when the program exits or when the "Save Movies" option is chosen.

## Building

The provided `Makefile` simplifies the compilation process. Just run `make` in the project directory.

## Contributing

Contributions are welcome!  Feel free to submit pull requests or open issues.

## License

[Choose a license, e.g., MIT]
