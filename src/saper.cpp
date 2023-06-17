#include "saper.hpp"


void MinesweeperBoard::debug_display() const {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            char M = '.', o = '.', F = '.';
            if (board_[i][j].hasMine_ && board_[i][j].isRevealed_) { M = 'M'; }
            if (board_[i][j].hasFlag_) { F = 'F'; }
            if (board_[i][j].isRevealed_) { o = 'o'; }
            std::cout << "[" << M << F << o << "] ";
        }
        std::cout << std::endl;
    }
}

//ustawianie poziomu trudności, bo komunikacja z konsolą powinna być
GameMode chooseDifficulty(){

    int difficulty;
    std::cout << "Podaj poziom trudnosci: " << std::endl;
    std::cout << "1 - latwy " << std::endl;
    std::cout << "2 - normalny " << std::endl;
    std::cout << "3 - trudny " << std::endl;

    std::cin >> difficulty;

    switch (difficulty)
    {
        case 0 : return GameMode::DEBUG;
        case 1 : return GameMode::EASY;
        case 2 : return GameMode::NORMAL;
        case 3 : return GameMode::HARD;
    }
    // w razie gdyby nie to wpisał co trzeaba
    return GameMode::DEBUG;
}

//czy koniec gry
bool MinesweeperBoard::is_game_over() const {
    for (int row = 0; row < height_; row++) {
        for (int col = 0; col < width_; col++) {
            if (board_[row][col].hasMine_ && !board_[row][col].hasFlag_)
                return false;
            if (!board_[row][col].hasMine_ && !board_[row][col].isRevealed_)
                return false;
        }
    }
    return true;
}

int MinesweeperBoard::random_position()
{
    time_t t;
    int poz_x, poz_y;

    srand((unsigned)time(&t));

    poz_x = rand()%width_;
    poz_y = rand()%height_;

    return poz_x * poz_y;
}

void MinesweeperBoard::increase_score(int points)
{
    score_ += points;
}


void MinesweeperBoard::display_highscores() const{
        std::cout << "Highscores:\n";
        for (const auto& score : highscore_) {
            std::cout << score.name << ": " << score.score << "\n";
        }
}
void MinesweeperBoard::sort_highscores() {
    std::sort(highscore_.begin(), highscore_.end(), [](const Score& s1, const Score& s2) {
        return s1.score > s2.score;
    });
}
void MinesweeperBoard::place_flag(int row, int col) {
    if (row >= 0 && row < height_ && col >= 0 && col < width_) {
        board_[row][col].hasFlag_ = true;
    }
}





