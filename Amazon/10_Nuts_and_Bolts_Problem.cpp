/*
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function matchPairs() which takes an array of characters nuts[], bolts[] and n as parameters and 
returns void. You need to change the array itself.

Link:
https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<char> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";
}

int partition(vector<char> &arr, int low, int high, char pivot)
{
    int i = low;
    char temp;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        else if (arr[j] == pivot)
        {
            temp = arr[high];
            arr[high] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void matchPairs(vector<char> &nuts, vector<char> &bolts, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(nuts, low, high, bolts[high]);
        partition(bolts, low, high, nuts[pivot]);
        matchPairs(nuts, bolts, low, pivot - 1);
        matchPairs(nuts, bolts, pivot + 1, high);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> nuts = {'^', '&', '%', '@', '#', '*', '$', '~', '!'};
    vector<char> bolts = {'~', '#', '@', '%', '&', '*', '$', '^', '!'};
    int n = nuts.size();

    matchPairs(nuts, bolts, 0, n - 1);

    cout << "Matched nuts and bolts are : \n";
    printArray(nuts);
    printArray(bolts);

    return 0;
}