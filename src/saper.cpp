#include "saper.hpp"
#
int SIDE ; // dlugosc boku planszy
int MINES ; // liczba min

std::chrono::steady_clock::time_point startTime;

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

// funkcja pozwalajaca na ciagla gre
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE],
                         int mines[][2], int row, int col, int *movesLeft)
{

    // podstawowy warunek ciaglej gry
    if (myBoard[row][col] != '-')
        return (false);

    int i, j;

    // gdy uzytkownik natrafi na mine
    if (realBoard[row][col] == '*')
    {
        myBoard[row][col]='*';

        for (i=0; i<MINES; i++)
            myBoard[mines[i][0]][mines[i][1]]='*';

        printBoard (myBoard);
        printf ("\nPrzegrales!\n");
        return (true) ;
    }

    else
    {
        // zlicza liczbe sasiadujacych min
        int count = countAdjacentMines(row, col, mines, realBoard);
        (*movesLeft)--;

        myBoard[row][col] = count + '0';

        if (!count)
        {
            // 1 (gora)
            if (isValid (row-1, col) == true)
            {
                if (isMine (row-1, col, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft);
            }

            // 2 (dol)
            if (isValid (row+1, col) == true)
            {
                if (isMine (row+1, col, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft);
            }

            // 3 (prawo)
            if (isValid (row, col+1) == true)
            {
                if (isMine (row, col+1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft);
            }

            // 4 (lewo)
            if (isValid (row, col-1) == true)
            {
                if (isMine (row, col-1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft);
            }

            // 5 (prawy gorny rog)
            if (isValid (row-1, col+1) == true)
            {
                if (isMine (row-1, col+1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft);
            }

            // 6 (lewy gorny rog)
            if (isValid (row-1, col-1) == true)
            {
                if (isMine (row-1, col-1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft);
            }

            // 7 (prawy dolny rog)
            if (isValid (row+1, col+1) == true)
            {
                if (isMine (row+1, col+1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft);
            }

            // 8 (lewy dolny rog)
            if (isValid (row+1, col-1) == true)
            {
                if (isMine (row+1, col-1, realBoard) == false)
                    playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft);
            }
        }

        return (false);
    }
}

// funkcja umieszczajaca miny w losowych miejscach na planszy
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
    bool mark[MAXSIDE*MAXSIDE];

    memset(mark, false, sizeof (mark));

    // kontynuuje, dopoki wszystkie miny nie zostana umieszczone
    for (int i=0; i<MINES; )
    {
        int random = rand() % (SIDE*SIDE);
        int x = random / SIDE;
        int y = random % SIDE;

        // ustawia mine w wolnym miejscu
        if (mark[random] == false)
        {
            // polozenie miny dla wspolrzednej wierszowej
            mines[i][0]= x;
            // polozenie miny dla wspolrzednej kolumnowej
            mines[i][1] = y;

            // ustawianie miny na tym miejscu
            realBoard[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }

    return;
}
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

void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
    //generuje losowe liczny
    srand(time (NULL));

    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
            myBoard[i][j] = realBoard[i][j] = '-';
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

void replaceMine (int row, int col, char board[][MAXSIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
        {
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


void cheatMinesweeper (char realBoard[][MAXSIDE])
{
    printf ("Miny znajduja sie: \n");
    printBoard (realBoard);
    return;
}

// Funkcja do rozpoczęcia liczenia czasu
void startTimer()
{
    startTime = std::chrono::steady_clock::now();
}

// Funkcja do zatrzymania licznika czasu i wyświetlenia czasu gry
void stopTimer()
{
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    int seconds = duration.count();

    std::cout << "Czas gry: " << seconds << " sekundy" << std::endl;
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
