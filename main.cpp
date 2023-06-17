#include "saper.hpp"


int main() {
    GameMode difficulty = chooseDifficulty();
    MinesweeperBoard board(4,4, difficulty);

    //bool game_over = mina.is_game_over();
    board.place_flag(0, 1);

    board.debug_display();


    return 0;


    }






