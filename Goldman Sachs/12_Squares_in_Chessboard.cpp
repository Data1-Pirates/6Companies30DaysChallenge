/*
You don't need to read input or print anything.
Your task is to complete the function squaresInChessBoard() which takes an Integer N as input and
returns the number of squares in a N*N chessboard.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1&sa=D&source=editors&ust=1641716809408000&usg=AOvVaw3hjCwh4yhWa3pqXHip2ulW
*/

#include <bits/stdc++.h>
using namespace std;

long long int squaresInChessBoard(long long int N)
{
    // code here
    long long int ans = N * (N + 1) * (2 * N + 1) / 6;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n = 4;
    cout << "Total Squares: " << squaresInChessBoard(n);
    return 0;
}