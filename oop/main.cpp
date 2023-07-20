#include <iostream>
#include "Movies.h"

using namespace std;

int main () {
  Movies movies;

  movies.addMovie("Star Wars IV: A New Hope", "PG", 1);
  movies.addMovie("Star Wars V: The Empire Strikes Back", "PG", 1);
  movies.addMovie("Star Wars VI: Return of the Jedi", "PG", 1);
  movies.addMovie("Aliens", "R", 1);
  movies.addMovie("Oppenheimer", "R", 1);

  movies.incrementWatched("Aliens");

  movies.display();

  return 0;
}