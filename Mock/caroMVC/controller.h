#pragma once
#include "model.h"
#include "view.h"
#include "playerModel.h"

class CaroController {
private:
    CaroModel model;
    CaroView view;
    PlayerModel playerX;
    PlayerModel playerO;

public:
    CaroController(int numRows, int numCols);
    void startGame();
};