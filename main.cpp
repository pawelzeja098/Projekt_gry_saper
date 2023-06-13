#include "saper.hpp"


int main() {
    MinesweeperBoard board(4,4, EASY);

//    bool game_over = mina.is_game_over();
    board.place_flag(0, 1);

    board.debug_display();
    return 0;
}




