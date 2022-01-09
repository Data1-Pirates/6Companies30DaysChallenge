/*
Your Task:
You don't need to read input or print anything.
Your task is to complete the function countSubArrayProductLessThanK() which takes the array a[],
its size n and an integer k as inputs and returns the count of required subarrays.

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/&sa=D&source=editors&ust=1641716809398000&usg=AOvVaw0MNvZAKHccbSaQBqcCE5sZ
*/

#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    long long int prod = 1;
    int ans = 0;
    int l = 0, r = 0;
    while (r < n)
    {
        prod *= a[r];
        while (l < r && prod >= k)
        {
            prod /= a[l];
            l++;
        }
        if (prod < k)
            ans += (r - l + 1);
        r++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k = 100;
    int n = 7;
    vector<int> v = {1, 9, 2, 8, 6, 4, 3};
    cout << "Ans: " << countSubArrayProductLessThanK(v, n, k);

    return 0;
}