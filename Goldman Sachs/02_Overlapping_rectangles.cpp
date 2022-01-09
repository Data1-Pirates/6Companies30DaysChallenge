/*
Your Task:
You don't need to read input or print anything.
Your task is to complete the function doOverlap() which takes the points L1, R1, L2, and R2 as input parameters and
returns 1 if the rectangles overlap. Otherwise, it returns 0.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/&sa=D&source=editors&ust=1641716809398000&usg=AOvVaw0nYFGiq0Iz2H0IUe5AU9QY
*/

#include <bits/stdc++.h>
using namespace std;

int doOverlap(int L1[], int R1[], int L2[], int R2[])
{
    // code here
    // if(L1[0]==R1[0]||L1[1]==R1[1])
    //      return 0;
    // if(L2[0]==R2[0]||L2[1]==R2[1])
    //     return 0;
    if (R2[1] > L1[1] || R1[1] > L2[1])
        return 0;
    if (R1[0] < L2[0] || R2[0] < L1[0])
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L1[] = {0, 10};
    int R1[] = {10, 0};
    int L2[] = {5, 5};
    int R2[] = {15, 0};

    if (doOverlap(L1, R1, L2, R2))
    {
        cout << "Output: " << 1 << endl
             << "The rectangles overlap.\n";
    }
    else
    {
        cout << "Output: " << 0 << endl
             << "The rectangles do not overlap.\n";
    }

    return 0;
}
