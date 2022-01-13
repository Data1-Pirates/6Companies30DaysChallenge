/*
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function isValid() which takes mat[][] as input parameter and 
returns 1 if any solution is possible. Otherwise, returns 0.

Link:
https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
*/

#include <bits/stdc++.h>
using namespace std;

int isValid(vector<vector<int>> mat)
{
    int r[9][9], c[9][9], s[3][3][9];
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(s, 0, sizeof(s));
    int number;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] > 0 && mat[i][j] <= 9)
            {
                number = mat[i][j] - 1;
                if (r[i][number])
                    return 0;
                r[i][number] = 1;
                if (c[j][number])
                    return 0;
                c[j][number] = 1;
                // checking if same box have repeated value except for 0
                if (s[i / 3][j / 3][number])
                    return 0;
                s[i / 3][j / 3][number] = 1;
            }
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                               {5, 2, 0, 0, 0, 0, 0, 0, 0},
                               {0, 8, 7, 0, 0, 0, 0, 3, 1},
                               {0, 0, 3, 0, 1, 0, 0, 8, 0},
                               {9, 0, 0, 8, 6, 3, 0, 0, 5},
                               {0, 5, 0, 0, 9, 0, 6, 0, 0},
                               {1, 3, 0, 0, 0, 0, 2, 5, 0},
                               {0, 0, 0, 0, 0, 0, 0, 7, 4},
                               {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    cout << ((isValid(arr)) ? "YES" : "NO");
    return 0;
}