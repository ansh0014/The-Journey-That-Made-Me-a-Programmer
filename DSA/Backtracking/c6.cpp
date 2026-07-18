// now i am doing the valid sudoku problem
// this is backtracking problem
// i have given a 9*9 sudoku board. i have to check if the given sudoku board is valid or not. the sudoku board could be partially filled, where empty cells are filled with the character '.'. a valid sudoku board (partially filled) is not necessarily solvable. only the filled cells need to be validated according to the following rules:
// each row must contain the digits 1-9 without repetition.
// each column must contain the digits 1-9 without repetition.
// each of the 9 3*3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// approach i will use backtracking to check if the given sudoku board is valid or not.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<vector<char>>& board, int row, int col, char ch) {

        // Row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

   
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int idx) {

        if (idx == 81)
            return true;

        int row = idx / 9;
        int col = idx % 9;

        if (board[row][col] == '.')
            return solve(board, idx + 1);

        char ch = board[row][col];
        board[row][col] = '.';   

        if (!check(board, row, col, ch))
            return false;

        board[row][col] = ch;    

        return solve(board, idx + 1);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board, 0);
    }
};

