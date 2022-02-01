/*
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function height() which takes N as input parameter and 
returns the height of the triangle that we can form using N dots.

Link:
https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart
*/

#include <bits/stdc++.h>
using namespace std;

int height(int N)
{
    int x = sqrt(2 * N);
    if (N < (x * (x + 1)) / 2)
        x--;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<"Output: "<<height(10);

    return 0;
}