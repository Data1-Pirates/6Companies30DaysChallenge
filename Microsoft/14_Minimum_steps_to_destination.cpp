/*
Your Task:
You do not need to read input or print anything. 
Your task is to complete the function minSteps() which takes the value D as input parameter and 
returns the minimum number of steps required to reach the dedstination D from 0.

Link:
https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
*/

#include <bits/stdc++.h>
using namespace std;

int minSteps(int target)
{
    // code here
    target = abs(target);
    int sum = 0, step = 0;
    while (sum < target || (sum - target) % 2 != 0)
    {
        step++;
        sum += step;
    }
    return step;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << minSteps(10);

    return 0;
}