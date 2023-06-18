#ifndef PROJEKT_GRY_SAPER_SAPER_HPP
#define PROJEKT_GRY_SAPER_SAPER_HPP

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define EASY 0
#define NORMAL 1
#define HARD 2
#define MAXSIDE 17
#define MAXMINES 50


bool isValid(int row, int col);

bool isMine (int row, int col, char board[][MAXSIDE]);

void makeMove(int *x, int *y);

void printBoard(char myBoard[][MAXSIDE]);

int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE]);

bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
                         int mines[][2], int row, int col, int *movesLeft);

void placeMines(int mines[][2], char realBoard[][MAXSIDE]);

void chooseDifficultyLevel ();
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE]);
void replaceMine (int row, int col, char board[][MAXSIDE]);
void cheatMinesweeper (char realBoard[][MAXSIDE]);

///*
// * dodanie do wektora highscore nazwy i wyniku
// */
//    void add_to_highscore(const std::string& name) {
//        highscore_.push_back({ name, score_ });
//        sort_highscores();
//    }
///*
// * wyświetlenie najlepszych wyników
// */
//    void display_highscores() const;
//
//    void place_flag(int row, int col);
//
//private:
//    Field board_[4][4];
////    std::unique_ptr<Field[]> myarray;
//
//    int width_;
//    int height_;
////    int  size_ = height_*width_;
//    GameMode mode_;
//    int score_;
//    std::vector<Score> highscore_;
//
//    void sort_highscores();
//
//};
//
//
//GameMode chooseDifficulty();
//
//
//
//
//
//
//
#endif
