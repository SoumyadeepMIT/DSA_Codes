#include <bits/stdc++.h>
using namespace std;
bool val(int i, int j, int n, const vector<vector<int>> &board)
{
    return !(i < 0 || j < 0 || i >= n || j >= n || board[i][j] != -1);
}

bool gen(int step, int n, vector<vector<int>> &board,
         vector<vector<int>> &dir, int i, int j)
{

    if (step == n * n)
        return true;

    for (int s = 0; s < 8; s++)
    {
        int ni = i + dir[s][0];
        int nj = j + dir[s][1];

        if (val(ni, nj, n, board))
        {
            board[ni][nj] = step;
            if (gen(step + 1, n, board, dir, ni, nj))
                return true;
            board[ni][nj] = -1;
        }
    }
    return false;
}

vector<vector<int>> knightTour(int n)
{
    // code here
    if (n <= 3)
        return {{}};
    vector<vector<int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0;
    if (gen(1, n, board, dir, 0, 0))
    {
        return board;
    }
    return {{}};
}

int main() {
    int n = 5; // Size of the chessboard
    vector<vector<int>> tour = knightTour(n);
    
    if (tour.size() == 1 && tour[0].size() == 1 && tour[0][0] == -1) {
        cout << "No solution exists for the knight's tour on a " << n << "x" << n << " board." << endl;
    } else {
        cout << "Knight's Tour on a " << n << "x" << n << " board:" << endl;
        for (const auto& row : tour) {
            for (const auto& cell : row) {
                cout << setw(2) << cell << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}