// the n-queens puzzel is the problem of placing n queens on an n*n chessboard such that no two queens aatach each other.
// given an integer n, return the number of distinct solution to the n-queens puzzle
#include<bits/stdc++.h>
using namespace std;
class Solution{
    
    public:
    int totalNQueens(int n){
        vector<vector<int>> board(n,vector<int>(n,0));
        return solve(board,0);
    }
    int solve(vector<vector<int>>& board,int row){
        if(row==board.size()) return 1;
        int count=0;
        for(int col=0;col<board.size();col++){
            if(isSafe(board,row,col)){
                board[row][col]=1;
                count+=solve(board,row+1);
                board[row][col]=0;
            }
        }
        return count;
    }
    bool isSafe(vector<vector<int>>& board,int row,int col){
        for(int i=row-1,j=col;i>=0;i--){
            if(board[i][j]==1) return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1) return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
            if(board[i][j]==1) return false;
        }
        return true;
    }
};