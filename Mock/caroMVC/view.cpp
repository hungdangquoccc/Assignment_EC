#include "view.h"

void CaroView::displayBoard( CaroModel& model)  {
    // Display the current state of the board
    for (int i = 0; i < model.getRows(); ++i) {
        for (int j = 0; j < model.getCols(); ++j) {
            cout << model.getCell(i, j) << " | ";
        }
        cout << endl;
        for (int j = 0; j < model.getRows(); ++j) {
            cout << "----";
        }
        cout << endl;
    }
    cout << endl;
}

void CaroView::displayMessage(const string& message) const {
    cout << message << endl;
}

void CaroView::displayResult(PlayerModel player)
{
    
     cout<< player.getPlayerName() << ": ";
     cout<<"\t"<< player.getPlayerScore()<<endl;

}

pair<int, int> CaroView::getUserMove() const {
    // Get user input for the next move
    int row, col;
    cout << "Enter row and column (e.g., 1 2): ";
    cin >> row >> col;
    return make_pair(row, col);
}
