#include "saper.hpp"
int main() {
    MinesweeperBoard mina(4,4, HARD);
    mina.debug_display();
    
    bool game_over = mina.is_game_over();
    
    return 0;
}




