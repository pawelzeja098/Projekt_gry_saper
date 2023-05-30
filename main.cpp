#include "matlab.hpp"
int main() {
    MinesweeperBoard mina(4,4, HARD);
    mina.debug_display();
    return 0;
}

void losuj_pozycje ()
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
            ustaw_mine(poz_x,poz_y);
            ilosc--;
        }
    }
}
