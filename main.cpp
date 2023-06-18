#include "include/saper.hpp"
#include<bits/stdc++.h>

using namespace std;

// funkcja umozliwiajaca gre
void playMinesweeper ()
{
    // poczatkowo gra nie jest skonczona
    bool gameOver = false;

    // prawdziwa plansza (realBoard) oraz wyswietlana plansza (myBoard)
    char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];

    int movesLeft = SIDE * SIDE - MINES, x, y;
    int mines[MAXMINES][2]; // przechowuje wspolrzedne wszystkich min

    initialise (realBoard, myBoard);

    // ustawia losowo miny
    placeMines (mines, realBoard);

    /*
    cheatMinesweeper(realBoard);
    */

    int currentMoveIndex = 0;
    while (gameOver == false)
    {
        printf ("Plansza: \n");
        printBoard (myBoard);
        makeMove (&x, &y);

        // instrukcja gwarantujaca, ze pierwszy ruch zawsze bedzie bezpieczny
        if (currentMoveIndex == 0) //pierwszy ruch
        {
            // jesli w pierwszym ruchu uzytkownik natrafi na mine,
            // to zostanie ona przestawiona funkcja replaceMine
            if (isMine (x, y, realBoard) == true)
                replaceMine (x, y, realBoard);
        }

        currentMoveIndex ++;

        gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft);

        if ((gameOver == false) && (movesLeft == 0))
        {
            printf ("\nWygrales!\n");
            gameOver = true;
        }
    }
    return;
}


int main()
{
    chooseDifficultyLevel ();
    playMinesweeper ();
    return (0);
}
