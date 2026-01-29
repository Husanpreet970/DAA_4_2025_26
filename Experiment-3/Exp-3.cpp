#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> board;
    vector<bool> colvalue, diag1, diag2;
    int n;
    bool found = false;
    bool solve(int row) {
        if (row == n) {
            return true;   
        }
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (colvalue[col] || diag1[d1] || diag2[d2])
                continue;
            board[row][col] = 'Q';
            colvalue[col] = diag1[d1] = diag2[d2] = true;
            if (solve(row + 1))
                return true;   
            board[row][col] = '.';
            colvalue[col] = diag1[d1] = diag2[d2] = false;
        }
        return false;
    }
    vector<string> solveNQueens(int N) {
        n = N;
        board = vector<string>(n, string(n, '.'));
        colvalue = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        solve(0);
        return board;
    }
};
int main() {
    Solution obj;
    int n;
    cout << "Enter value of N: ";
    cin >> n;
    vector<string> solution = obj.solveNQueens(n);
    cout << "\nOne valid solution:\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
