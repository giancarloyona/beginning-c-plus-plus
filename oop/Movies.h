#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"

#ifndef BEGINNING_C_PLUS_PLUS_OOP_MOVIES_H_
#define BEGINNING_C_PLUS_PLUS_OOP_MOVIES_H_

class Movies {
 private:
  std::vector <Movie> movies;

 public:
  ~Movies()=default;

  bool addMovie(std::string name, std::string rating, int watched){

    for (const Movie &movie : movies) {
      if (movie.getName() == name) {
        return false;
      }
    }

    Movie m(name, rating, watched);
    movies.push_back(m);
    cout << name << " added!" << endl;
    return true;
  }

  bool incrementWatched(std::string name){

    for (Movie &movie : movies) {
      if (movie.getName() == name) {
        movie.incrementWatched();
        return true;
      }
    }
    return false;
  }

  void display() const{
    if (movies.empty()) {
      cout << "No movies to display!" << endl;
    } else {
      cout << "Movies watched: " << endl;
      for (const auto& movie:movies) {
        movie.display();
      }
    }
  }

};

#endif
