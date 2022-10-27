/** Problem Statement:  
The N-queens puzzle is the problem of placing N queens on an N x N chessboard such that no two queens attack each other. **/

/** Approach

Using the concept of Backtracking, we will place Queen at different positions of the chessboard and find the right arrangement
where all the N queens can be placed on the N*N grid. **/

/** Cpp code **/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> TempGrid;
bool is_valid(vector<string> &board, int row, int col)
{
    // check col
    for (int i = row; i >= 0; --i)
        if (board[i][col] == 'Q')
            return false;
    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void dfs(vector<string> &board, int row)
{
    // exit condition
    if (row == board.size())
    {
        TempGrid.push_back(board);
        return;
    }
    // iterate every possible position
    for (int i = 0; i < board.size(); ++i)
    {
        if (is_valid(board, row, i))
        {
            // make decision
            board[row][i] = 'Q';
            // next iteration
            dfs(board, row + 1);
            // back-tracking
            board[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    // return empty if n <= 0
    if (n <= 0)
    return {{}};
    vector<string> board(n, string(n, '.'));
    dfs(board, 0);
    return TempGrid;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<string>>FinalGrid = solveNQueens(n);
  for (int i = 0; i < n; i++)
  {
    for(int j=0;j<n;j++){
    cout<<FinalGrid[i][j]<<" ";
    }
    cout<<endl;
  }
}


  
