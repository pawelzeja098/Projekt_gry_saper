#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

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
// tera biope pierwsze ileśtam pól i na nich robię miny
//for(auto i = 0; i < difficulty; i++){
//    numer_pola[i]
//
//}


        //wypisanie wektora pól
        for (const auto& element : numer_pola) {
            std::cout << element << " ";
        }
        std::cout<< std::endl;

    }
    void debug_display() const; // uwaga przy deklarowaniu z const, tak sie robi żeby w src definiować

private:
    Field board_[4][4];
//    std::unique_ptr<Field[]> myarray;

    int width_;
    int height_;
//    int  size_ = height_*width_;
    GameMode mode_;

};



#endif /* INCLUDE_MATLAB_HPP_ */
