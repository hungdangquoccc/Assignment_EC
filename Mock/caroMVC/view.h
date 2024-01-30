#pragma once
#include <iostream>
#include "model.h"
#include "playerModel.h"

class CaroView {
public:
    void displayBoard( CaroModel& model) ;
    void displayResult(PlayerModel player);
    void displayMessage(const string& message) const;
    pair<int, int> getUserMove() const;
};