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
