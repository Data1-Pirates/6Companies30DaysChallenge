/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and 
returns an array containing all the quadruples in a lexicographical manner. \
Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4. 

Link:

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    // Your code goes here
    vector<vector<int>> ans;
    int n = arr.size();
    unordered_set<string> s;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int l = j + 1, r = n - 1;
            int sum = arr[i] + arr[j];
            while (l < r)
            {
                if (sum + arr[l] + arr[r] < target)
                    l++;
                else if (sum + arr[l] + arr[r] > target)
                    r--;
                else
                {
                    string str;
                    str += to_string(arr[i]) + '|' + to_string(arr[j]) + '|' + to_string(arr[l]) + '|' + to_string(arr[r]);
                    if (s.find(str) == s.end())
                    {
                        vector<int> v = {arr[i], arr[j], arr[l], arr[r]};
                        ans.push_back(v);
                        s.insert(str);
                    }
                    l++;
                    r--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {88, 84, 3, 51, 54, 99, 32, 60, 76, 68, 39, 12, 26, 86, 94, 39, 95, 70, 34, 78, 67, 1, 97, 2, 17, 92, 52};
    int X = 179;
    vector<vector<int>> ans = fourSum(arr, X);
    for (auto i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}