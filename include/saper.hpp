
#ifndef PROJEKT_GRY_SAPER_SAPER_HPP
#define PROJEKT_GRY_SAPER_SAPER_HPP

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
//biblioteka do obsługi graficznej
//#include <SFML/Graphics.hpp>


// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include<iostream>
#include<vector>
#include<string>
#include <cmath>
#include <random>
#include <memory>
#include <algorithm>



enum GameMode  { DEBUG, EASY, NORMAL, HARD }; // jakie typy może przyjmować

struct Field{
    bool hasMine_ = false;
    bool hasFlag_ = false;
    bool isRevealed_ = false;
} ;

struct Score {
    std::string name;
    int score;
};

class RectangleShape;

class MinesweeperBoard {
public:
    MinesweeperBoard(int width, int height, GameMode mode):  width_(width), height_(height), mode_(mode) {
//        board_[0][0].hasMine_ = true;
//        board_[0][2].hasMine_ = true;
//        board_[0][2].hasFlag_ = true;
//        board_[1][1].isRevealed_ = true;
        int  size_ = height*width;
        float difficulty = 0;

        if (mode == EASY){difficulty = static_cast<float>(std::ceil(size_ * 0.1));}
        else if (mode == NORMAL){difficulty = static_cast<float>(std::ceil(size_ * 0.2));}
        else if (mode == HARD){difficulty = static_cast<float>(std::ceil(size_ * 0.3));}
        std::cout<< "Mine ma "<<difficulty<<" pol" << std::endl;

// tworzę wektor, który ma tyle miejsc ile jest pól, a następnie mieszam go i biorę difficulty pierwszych miejsc
        std::vector<int> numer_pola ;
        for (int i = 0; i < size_; i++) {
            numer_pola.push_back(1+i)     ;
        }
//wymieszańsko
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(numer_pola.begin(), numer_pola.end(), g);

// Ustawienie min na wylosowanych polach
        for (std::size_t i = 0; i < (std::size_t) difficulty; i++) {
            int row = (numer_pola[i] - 1) / width_;
            int col = (numer_pola[i] - 1) % width_;
            board_[row][col].hasMine_ = true;
        }


        //wypisanie wektora pól
        for (const auto& element : numer_pola) {
            std::cout << element << " ";
        }
        std::cout<< std::endl;

    }

    int get_width() const {
        return width_;
    }
    int get_height() const {
        return height_;
    }


    void debug_display() const; // uwaga przy deklarowaniu z const, tak sie robi żeby w src definiować


    bool is_game_over() const;
    /*
     * funkcja losuje pozycje na planszy zwraca numer pola
     */
    int random_position();


    /*
     * funckja zwiekszajaca wynik
     */

    void increase_score(int points);

    /*
     * funkcja pobiera wynik osiągnięty przez gracza
     */

    int get_score() const{
        return score_;
    }
    /*
    * dodanie do wektora highscore nazwy i wyniku
    */
    void add_to_highscore(const std::string& name) {
        highscore_.push_back({ name, score_ });
        sort_highscores();
    }

    /*
     * wyświetlenie najlepszych wyników
     */
    void display_highscores() const;

    void place_flag(int row, int col);



    void reveal_field(int row, int col) {
        if (row >= 0 && row < height_ && col >= 0 && col < width_ && !board_[row][col].isRevealed_) {
            board_[row][col].isRevealed_ = true;
            if (board_[row][col].hasMine_) {

                std::cout << "Przegrales" << std::endl;
            } else {
                // Zwieksz wynik jesli zostalo wybrane pole bez miny
                increase_score(10);

                // Sprawdz i odkryj sasiadujace
                if (count_adjacent_mines(row, col) == 0) {
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            reveal_field(row + i, col + j);
                        }
                    }
                }
            }
        }
    }


private:
    Field board_[4][4];
//    std::unique_ptr<Field[]> myarray;

    int width_;
    int height_;
//    int  size_ = height_*width_;
    GameMode mode_;
    int score_;
    std::vector<Score> highscore_;

    void sort_highscores();
    int count_adjacent_mines(int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = row + i;
                int newCol = col + j;
                if (newRow >= 0 && newRow < height_ && newCol >= 0 && newCol < width_ &&
                    board_[newRow][newCol].hasMine_) {
                    count++;
                }
            }
        }
        return count;
    }};

GameMode chooseDifficulty();




#endif //PROJEKT_GRY_SAPER_SAPER_HPP
