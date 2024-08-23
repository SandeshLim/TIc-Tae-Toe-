#include <iostream>
#include <string>
using namespace std;

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    const char playerX = 'X', playerO = 'O';
    char currentPlayer = playerX, winner = ' ';
    int r, c;

    for (int i = 0; i < 9 && winner == ' '; i++) {
        // Print game board
        for (int j = 0; j < 3; j++) {
            cout << " " << board[j][0] << " | " << board[j][1] << " | " << board[j][2] << endl;
            if (j < 2) cout << "---|---|---" << endl;
        }
        // Get player input
        do {
            cout << "Current Player is " << currentPlayer << ". Enter row and column (0-2): ";
            cin >> r >> c;
        } while (r < 0 || r > 2 || c < 0 || c > 2 || board[r][c] != ' ');

        board[r][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // Check for a winner
        for (int j = 0; j < 3; j++) {
            if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][0] != ' ') winner = board[j][0];
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') winner = board[0][j];
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') winner = board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') winner = board[0][2];
    }

    // Final board display
    for (int j = 0; j < 3; j++) {
        cout << " " << board[j][0] << " | " << board[j][1] << " | " << board[j][2] << endl;
        if (j < 2) cout << "---|---|---" << endl;
    }

    // Declare the result
    if (winner != ' ')
        cout << "Player " << winner << " is the winner!" << endl;
    else
        cout << "Tie!" << endl;

    return 0;
}