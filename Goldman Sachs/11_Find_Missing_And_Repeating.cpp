/*
Your Task:
You don't need to read input or print anything.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and
returns an array of integers of size 2 denoting the answer ( The first index contains repeating no and second index contains missing no.)

Link:
https://www.google.com/url?q=https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/&sa=D&source=editors&ust=1641716809407000&usg=AOvVaw01EIKJkpZERYfSxtWdJaen
*/

#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    // code here
    int *ans = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            ans[0] = abs(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[1] = i + 1;
            break;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {1, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    int *ans = (int *)malloc(2 * sizeof(int));
    ans = findTwoElement(arr, n);
    cout << "Repeating number: " << ans[0] << endl
         << "Missing Number: " << ans[1];
    return 0;
}