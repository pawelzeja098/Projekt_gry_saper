#include "saper.hpp"

int SIDE ; // dlugosc boku planszy
int MINES ; // liczba min

// funkcja sprawdzajaca, czy podana komorka o wspolrzednych (row, col)
// jest prawidlowa
bool isValid(int row, int col)
{
    // zwraca true jesli jest prawidlowa
    return (row >= 0) && (row < SIDE) &&
           (col >= 0) && (col < SIDE);
}

// funkcja sprawdzajaca, czy podana komorka posiada w sobie mine
bool isMine (int row, int col, char board[][MAXSIDE])
{
    if (board[row][col] == '*')
        return (true);
    else
        return (false);
}

// funkcja czytajaca ruch uzytkownika
void makeMove(int *x, int *y)
{
    // sczytywanie ruchu
    printf("Twoj ruch, (wiersz, kolumna) -> ");
    scanf("%d %d", x, y);
    *x = *x - 1;
    *y = *y - 1;
    return;
}

// funkcja zwracajaca aktualna tablice
void printBoard(char myBoard[][MAXSIDE])
{
    int i, j;

    printf ("    ");

    for (i=1; i<SIDE + 1; i++)
        printf ("%d ", i);

    printf ("\n\n");
    int k = 1;
    for (i=0; i<SIDE; i++)
    {
        printf ("%d   ", k);

        for (j=0; j<SIDE; j++)
            printf ("%c ", myBoard[i][j]);
        printf ("\n");
        k++;
    }
    return;
}

// funkcja liczaca ilosc min sasiadujacych z komorka
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][MAXSIDE])
{
    int i;
    int count = 0;

    // 1 (gora)
    if (isValid (row-1, col) == true)
    {
        if (isMine (row-1, col, realBoard) == true)
            count++;
    }

    // 2 (dol)
    if (isValid (row+1, col) == true)
    {
        if (isMine (row+1, col, realBoard) == true)
            count++;
    }

    // 3 (prawo)
    if (isValid (row, col+1) == true)
    {
        if (isMine (row, col+1, realBoard) == true)
            count++;
    }

    // 4 (lewo)
    if (isValid (row, col-1) == true)
    {
        if (isMine (row, col-1, realBoard) == true)
            count++;
    }

    // 5 (prawy gorny rog)
    if (isValid (row-1, col+1) == true)
    {
        if (isMine (row-1, col+1, realBoard) == true)
            count++;
    }

    // 6 (lewy gorny rog)
    if (isValid (row-1, col-1) == true)
    {
        if (isMine (row-1, col-1, realBoard) == true)
            count++;
    }

    // 7 (prawy dolny rog)
    if (isValid (row+1, col+1) == true)
    {
        if (isMine (row+1, col+1, realBoard) == true)
            count++;
    }

    // 8 (lewy dolny rog)
    if (isValid (row+1, col-1) == true)
    {
        if (isMine (row+1, col-1, realBoard) == true)
            count++;
    }
    return (count);
}

//void MinesweeperBoard::debug_display() const {
//    for (int i = 0; i < height_; i++) {
//        for (int j = 0; j < width_; j++) {
//            char M = '.', o = '.', F = '.';
//            if (board_[i][j].hasMine_ && board_[i][j].isRevealed_) { M = 'M'; }
//            if (board_[i][j].hasFlag_) { F = 'F'; }
//            if (board_[i][j].isRevealed_) { o = 'o'; }
//            std::cout << "[" << M << F << o << "] ";
//        }
//        std::cout << std::endl;
//    }
//}
//
////ustawianie poziomu trudności, bo komunikacja z konsolą powinna być
//GameMode chooseDifficulty(){
//
//    int difficulty;
//    std::cout << "Podaj poziom trudnosci: " << std::endl;
//    std::cout << "1 - latwy " << std::endl;
//    std::cout << "2 - normalny " << std::endl;
//    std::cout << "3 - trudny " << std::endl;
//
//    std::cin >> difficulty;
//
//    switch (difficulty)
//    {
//        case 0 : return GameMode::DEBUG;
//        case 1 : return GameMode::EASY;
//        case 2 : return GameMode::NORMAL;
//        case 3 : return GameMode::HARD;
//    }
//    // w razie gdyby nie to wpisał co trzeaba
//    return GameMode::DEBUG;
//}
//
////czy koniec gry
//bool MinesweeperBoard::is_game_over() const {
//    for (int row = 0; row < height_; row++) {
//        for (int col = 0; col < width_; col++) {
//            if (board_[row][col].hasMine_ && !board_[row][col].hasFlag_)
//                return false;
//            if (!board_[row][col].hasMine_ && !board_[row][col].isRevealed_)
//                return false;
//        }
//    }
//    return true;
//}
//
//int MinesweeperBoard::random_position()
//{
//    time_t t;
//    int poz_x, poz_y;
//
//    srand((unsigned)time(&t));
//
//    poz_x = rand()%width_;
//    poz_y = rand()%height_;
//
//    return poz_x * poz_y;
//}
//
//void MinesweeperBoard::increase_score(int points)
//{
//    score_ += points;
//}
//
//
//void MinesweeperBoard::display_highscores() const{
//        std::cout << "Highscores:\n";
//        for (const auto& score : highscore_) {
//            std::cout << score.name << ": " << score.score << "\n";
//        }
