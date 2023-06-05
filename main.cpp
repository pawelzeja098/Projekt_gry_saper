#include "matlab.hpp"
int main() {
    MinesweeperBoard mina(4,4, HARD);
    mina.debug_display();
    return 0;
}

void position ()
{
    time_t t;
    int poz_x, poz_y;
    int ilosc = 10;

    srand((unsigned)time(&t));

    while (ilosc>0)
    {
        poz_x = rand()%10;
        poz_y = rand()%10;

        if (plansza[poz_x][poz_y].wartosc!=9)
        {
            set_mine(poz_x,poz_y);
            ilosc--;
        }
    }
}

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

