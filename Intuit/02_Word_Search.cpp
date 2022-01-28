/*
our Task:
You don't need to read or print anything. 
Your task is to complete the function isWordExist() which takes board and word as input parameter and 
returns boolean value true if word can be found otherwise returns false.

Link:
https://practice.geeksforgeeks.org/problems/word-search/1/
*/

#include <bits/stdc++.h>
using namespace std;

int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};
bool found(vector<vector<char>> &board, int i, int j, string &word, int R, int C, int k)
{
    int n = word.length();
    if (k == n)
        return true;
    if (i >= R || i < 0 || j < 0 || j >= C)
        return false;
    if (word[k] != board[i][j])
        return false;
    board[i][j] = '*';

    for (int direct = 0; direct < 4; direct++)
    {
        int row = i + x[direct], col = j + y[direct];
        if (found(board, row, col, word, R, C, k + 1))
            return true;
    }
    board[i][j] = word[k];
    return false;
}

bool isWordExist(vector<vector<char>> &board, string word)
{
    // Code here
    int R = board.size();
    int C = board[0].size();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (word[0] == board[i][j])
            {
                if (found(board, i, j, word, R, C, 0))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> board = {{'a', 'g', 'b', 'c'}, {'q', 'e', 'e', 'l'}, {'g', 'b', 'k', 's'}};
    string word = "geeks";
    if (isWordExist(board, word))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}