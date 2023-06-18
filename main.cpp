#include "include/saper.hpp"
#include<bits/stdc++.h>

using namespace std;


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





int main()
{
    chooseDifficultyLevel ();
    playMinesweeper ();
    return (0);
}
