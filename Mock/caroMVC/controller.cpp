#include "controller.h"

CaroController::CaroController(int numRows, int numCols)
    : model(numRows, numCols), playerX('X'), playerO('O') {}

void CaroController::startGame() {
    view.displayMessage("Welcome to Caro!");

    view.displayMessage("Enter the name for Player X:");
    string nameP1;
    cin >> nameP1;
    playerO.setPlayerName(nameP1);

    view.displayMessage("Enter the name for Player O:");
    
    string nameP2;
    cin >> nameP2;
    playerX.setPlayerName(nameP2);

    char check;
    bool gameover = false;

    do {
        
        view.displayBoard(model);

        /*Player X's turn*/
        pair<int, int> moveX;
        do {
            view.displayMessage("Player X(" + playerX.getPlayerName() + ") turn");
            moveX = view.getUserMove();
            if (model.markX(moveX.first, moveX.second)) {
                break;  // break if invalid mark
            } else {
                view.displayMessage("Invalid move for Player X " + playerX.getPlayerName() + "Try again.");
            }
        } while (true);

            /*check win player X*/
        if (model.checkWin(moveX.first, moveX.second)) {
            view.displayBoard(model);
            view.displayMessage("Player X(" + playerX.getPlayerName() + ") wins!");
            playerX.increasePlayerScore(1); 
            view.displayResult(playerX);
            view.displayResult(playerO);
            
            view.displayMessage("Continue play? (Y/N)");
            cin >> check;
            if (check == 'N') {
                gameover = true;
            }
            else
            {
                model.resetBoard();
            }
        } else if (model.isBoardFull()) {
            view.displayBoard(model);
            view.displayMessage("It's a draw!");
            view.displayResult(playerX);
            view.displayResult(playerO);

            view.displayMessage("Continue play? (Y/N)");
            cin >> check;
            if (check == 'N') {
                gameover = true;
            }
        }

        if (gameover) {
            break;
        }

        /*Display board after Player X's move*/
        view.displayBoard(model);

        /*Player O's turn*/
        pair<int, int> moveO;
        do {
            view.displayMessage("Player O(" + playerX.getPlayerName() + ") turn");
            moveO = view.getUserMove();
            if (model.markO(moveO.first, moveO.second)) {
                break;  //break if invalid mark
            } else {
                view.displayMessage("Invalid move for Player O.(" + playerO.getPlayerName() + ") Try again.");
            }
        } while (true);


            /*check win player O*/
        if (model.checkWin(moveO.first, moveO.second)) {
            view.displayBoard(model);
            view.displayMessage("Player O(" + playerX.getPlayerName() + ") wins!");
            playerO.increasePlayerScore(1);
            
            view.displayResult(playerX);
            view.displayResult(playerO);

            view.displayMessage("Continue play? (Y/N)");
            cin >> check;
            if (check == 'N') {
                gameover = true;
            }
            else
            {
                model.resetBoard();
            }
        } else if (model.isBoardFull()) {
            view.displayBoard(model);
            view.displayMessage("It's a draw!");
            view.displayResult(playerX);
            view.displayResult(playerO);

            view.displayMessage("Continue play? (Y/N)");
            cin >> check;
            if (check == 'N') {
                gameover = true;
            }
            else
            {
                model.resetBoard();
            }
        }

    } while (!gameover);
}

