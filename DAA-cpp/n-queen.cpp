
#include<iostream>
#include<vector>
using namespace std;

int n;

// Print Board
void printBoard(vector<vector<char>>& board) {

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// ==========================================
// 1. BACKTRACKING
// ==========================================

bool isSafe(vector<vector<char>>& board, int row, int col) {

    for(int i=row-1;i>=0;i--) {
        if(board[i][col]=='Q')
            return false;
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) {
        if(board[i][j]=='Q')
            return false;
    }

    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++) {
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}

bool backtracking(vector<vector<char>>& board, int row) {

    if(row==n)
        return true;

    for(int col=0;col<n;col++) {

        if(isSafe(board,row,col)) {

            board[row][col]='Q';

            if(backtracking(board,row+1))
                return true;

            board[row][col]='.';
        }
    }

    return false;
}

// ==========================================
// 2. BRANCH AND BOUND
// ==========================================

bool branchBound(vector<vector<char>>& board, int row,
                 vector<int>& col,
                 vector<int>& diag1,
                 vector<int>& diag2) {

    if(row==n)
        return true;

    for(int j=0;j<n;j++) {

        int d1 = row-j+(n-1);
        int d2 = row+j;

        if(col[j] || diag1[d1] || diag2[d2])
            continue;

        board[row][j]='Q';

        col[j]=1;
        diag1[d1]=1;
        diag2[d2]=1;

        if(branchBound(board,row+1,col,diag1,diag2))
            return true;

        board[row][j]='.';

        col[j]=0;
        diag1[d1]=0;
        diag2[d2]=0;
    }

    return false;
}

// ==========================================
// MAIN
// ==========================================

int main() {

    cout << "Enter N: ";
    cin >> n;

    if(n<=0) {
        cout << "Invalid input!";
        return 0;
    }

    // BACKTRACKING
    vector<vector<char>> board1(n,vector<char>(n,'.'));

    cout << "\n--- BACKTRACKING ---\n";

    if(backtracking(board1,0)) {
        printBoard(board1);
    }
    else {
        cout << "No solution exists!\n";
    }


    // BRANCH AND BOUND
    vector<vector<char>> board2(n,vector<char>(n,'.'));

    vector<int> col(n,0);
    vector<int> diag1(2*n-1,0);
    vector<int> diag2(2*n-1,0);

    cout << "\n--- BRANCH AND BOUND ---\n";

    if(branchBound(board2,0,col,diag1,diag2)) {
        printBoard(board2);
    }
    else {
        cout << "No solution exists!\n";
    }

    return 0;
}
