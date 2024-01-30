#pragma once
#include <string>

class PlayerModel {
private:
    char playerType;  
    string playerName;  
    int playerScore;  

public:
    PlayerModel(char type, const string& name = "") : playerType(type), playerName(name), playerScore(0) {}

    void setPlayerName(const string &name)
    {
        playerName = name;
    }

    const string& getPlayerName() const {
        return playerName;
    }

    int getPlayerScore() const {
        return playerScore;
    }

    void increasePlayerScore(int points) {
        playerScore += points;
    }
};
