#include "include/saper.hpp"
#include<bits/stdc++.h>

using namespace std;

// funkcja inicjalizujaca gre
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
    // generator losowych liczb
    srand(time (NULL));

    // przydziela wszystkie komorki jako niezaminowane
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
            myBoard[i][j] = realBoard[i][j] = '-';
        }
    }

    return;
}

// funkcja ujawniajaca polozenie min
void cheatMinesweeper (char realBoard[][MAXSIDE])
{
    printf ("Miny znajduja sie: \n");
    printBoard (realBoard);
    return;
}

// funkcja zmieniajaca polozenie miny na wolne miejsce
void replaceMine (int row, int col, char board[][MAXSIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
            // znajduje miejsce na planszy bez miny
            // a nastepnie umieszcza ja w nim
            if (board[i][j] != '*')
            {
                board[i][j] = '*';
                board[row][col] = '-';
                return;
            }
        }
    }
    return;
}

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

//Funkcja umozliwiajaca wybor poziomu trudnosci
void chooseDifficultyLevel ()
{
    int level;

    printf ("Wybierz poziom trudnosci: \n");
    printf ("Nacisnij 0 aby wybrac LATWY (plansza o wymiarach 9x9 oraz o 10 minach)\n");
    printf ("Nacisnij 1 aby wybrac SREDNI (plansza o wymiarach 16x16 oraz o 40 minach)\n");
    printf ("Nacisnij 2 aby wybrac TRUDNY (plansza o wymiarach 24x24 oraz o 99 minach)\n");
    printf ("Twoj wybor: ");
    scanf ("%d", &level);

    if (level == EASY)
    {
        SIDE = 9;
        MINES = 10;
    }

    if (level == NORMAL)
    {
        SIDE = 12;
        MINES = 30;
    }

    if (level == HARD)
    {
        SIDE = 16;
        MINES = 50;
    }

    return;
}

int main()
{
    chooseDifficultyLevel ();
    playMinesweeper ();
    return (0);
}
