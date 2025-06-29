  #include <iostream>
using namespace std;

char board[3][3]; // Game board
char current_marker;
int current_player;

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j;
}

// Function to print the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n\n";
}

// Function to place marker
bool placeMarker(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = current_marker;
    return true;
}

// Function to check for a win
bool isWinner() {
    // Rows, Columns, Diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == current_marker && board[i][1] == current_marker && board[i][2] == current_marker) ||
            (board[0][i] == current_marker && board[1][i] == current_marker && board[2][i] == current_marker))
            return true;

    if ((board[0][0] == current_marker && board[1][1] == current_marker && board[2][2] == current_marker) ||
        (board[0][2] == current_marker && board[1][1] == current_marker && board[2][0] == current_marker))
        return true;

    return false;
}

// Function to switch player
void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

// Function to check draw
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Main game loop
void playGame() {
    initializeBoard();
    current_player = 1;
    current_marker = 'X';

    printBoard();

    int cell;
    while (true) {
        cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
        cin >> cell;

        if (!placeMarker(cell)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        printBoard();

        if (isWinner()) {
            cout << "🎉 Player " << current_player << " wins! 🎉\n";
            break;
        } else if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        swapPlayerAndMarker();
    }
}

// Main function
int main() {
    cout << "=== TIC TAC TOE ===\n";
    playGame();
    return 0;
}
