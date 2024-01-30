// #pragma once
#include "controller.h"

int main() {
    int r, c;
    cout << "Enter Row & Column length: ";
    cin >> r >> c;
  
    CaroController caroGame(r, c);
    caroGame.startGame();

    return 0;
}
