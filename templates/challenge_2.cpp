#include <list>
#include <iostream>
#include <iomanip>

class Song {
private:
    friend std::ostream &operator<<(std::ostream &os, const Song &s);

    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;

    Song(std::string name, std::string artist, int rating) {
        this->name = name;
        this->artist = artist;
        this->rating = rating;
    }

    ~Song() = default;

    std::string get_name() {
        return this->name;
    }

    std::string get_artist() {
        return this->artist;
    }

    int get_rating() {
        return this->rating;
    }

    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }

};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left
       << s.rating;

    return os;
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_play(const std::list<Song> &playlist, const Song &current_song) {
    for (const Song &song: playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "Current song:" << std::endl;
    std::cout << current_song << std::endl;
}

void display_menu() {
    std::cout << "\nF - Play first song" << std::endl;
    std::cout << "N - Play next song" << std::endl;
    std::cout << "P - Play previous song" << std::endl;
    std::cout << "A - Add and play a new song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit)" << std::endl;
}

int main() {

    std::list<Song> playlist{{"God's plan",        "Drake",                         5},
                             {"Never be the same", "Camila Cabello",                5},
                             {"Pray for me",       "The Weeknd and Kendrick Lamar", 4},
                             {"The Middle",        "Zedd, Maren Morris & Grey",     5},
                             {"Wait",              "Maroon 5",                      4},
                             {"Whatever it takes", "Imagine Dragons",               3}};

    auto current_song = playlist.begin();
    char option{};
    bool keep_playing{true};

    while (keep_playing) {
        display_menu();
        std::cin >> option;
        option = toupper(option);

        switch (option) {
            case 'F': {
                std::cout << "Playing first song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            }
            case 'N' : {
                std::cout << "Playing next song" << std::endl;
                current_song++;
                if (current_song == playlist.end()) {
                    std::cout << "Wrapping to start of playlist" << std::endl;
                    current_song = playlist.begin();
                }
                play_current_song(*current_song);
                break;
            }
            case 'P' : {
                std::cout << "Playing previous song" << std::endl;
                if (current_song == playlist.begin()) {
                    std::cout << "Wrapping to end of playlist" << std::endl;
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song);
                break;
            }
            case 'A' : {
                std::string name, artist;
                int rating;

                std::cin.clear();
                std::cin.ignore();

                std::cout << "Adding and playing new song" << std::endl;
                std::cout << "Enter song name: ";
                getline(std::cin, name);
                std::cout << "Enter song artist: ";
                getline(std::cin, artist);
                std::cout << "Enter your rating (1-5): ";
                std::cin >> rating;

                playlist.insert(current_song, Song(name, artist, rating));
                current_song--;
                play_current_song(*current_song);

                break;
            }
            case 'L' : {
                display_play(playlist, *current_song);
                break;
            }
            case 'Q': {
                keep_playing = false;
                break;
            }
            default : {
                display_menu();
            }
        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}