/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.

Link:
https://leetcode.com/problems/divide-two-integers/
*/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;
    if (dividend == -2147483648 && divisor == 1)
        return -2147483648;
    int sign = 2;
    if (dividend > 0)
    {
        dividend = -dividend;
        sign -= 1;
    }
    if (divisor > 0)
    {
        divisor = -divisor;
        sign -= 1;
    }
    int output = 0;
    while (dividend <= divisor)
    {
        int shifts = 0;
        int half = dividend >> 1;
        int dp = divisor;
        while (dp > half)
        {
            dp <<= 1;
            shifts++;
        }
        output += (1 << shifts);
        dividend -= dp;
    }
    if (sign == 1)
        output = -output;
    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Output: " << divide(-10, 3);

    return 0;
}