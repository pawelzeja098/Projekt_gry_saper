#include "saper.hpp"

void MinesweeperBoard::debug_display() const {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            char M = '.', o = '.', F = '.';
            if (board_[i][j].hasMine_) { M = 'M'; }
            if (board_[i][j].hasFlag_) { F = 'F'; }
            if (board_[i][j].isRevealed_) { o = 'o'; }
            std::cout << "[" << M << F << o << "] ";
        }
        std::cout << std::endl;
    }

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
