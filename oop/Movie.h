#ifndef BEGINNING_C_PLUS_PLUS_OOP_MOVIE_H_
#define BEGINNING_C_PLUS_PLUS_OOP_MOVIE_H_
#include <iostream>
#include <string>

using namespace std;

class Movie {
 private:
  std::string name;
  std::string rating;
  int watched;

 public:
  void setName(std::string name) {
    this->name = name;
  }

  std::string getName() const {
    return name;
  }

  void setRating(std::string rating) {
    this->rating = rating;
  }

  std::string getRating() const {
    return rating;
  }

  void setWatched(int watched) {
    this->watched = watched;
  }

  int getWatched() const {
    return watched;
  }

  void incrementWatched() {
    watched++;
  }

  void display() const {
    cout << name + ", " << rating + ", " << watched << endl;
  }

  Movie(std::string name, std::string rating, int watched) : name(name), rating(rating), watched(watched) {}
  Movie(const Movie &source) : Movie{source.name, source.rating, source.watched}{}
  ~Movie()= default;
};

#endif //BEGINNING_C_PLUS_PLUS_OOP_MOVIE_H_
