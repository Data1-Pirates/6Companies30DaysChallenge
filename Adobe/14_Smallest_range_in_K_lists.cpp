/*
Your Task :
Complete the function findSmallestRange() that receives array , array size n and k as parameters and 
returns the output range (as a pair in cpp and array of size 2 in java and python)

Link:
https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int i, j;
};

class compare
{
public:
    bool operator()(Node &x, Node &y)
    {
        return x.data > y.data;
    }
};

pair<int, int> findSmallestRange(int arr[][5], int n, int k)
{
    // code here
    priority_queue<Node, vector<Node>, compare> pq;
    int maxele = INT_MIN;
    int minrange = INT_MAX, start, end;

    for (int i = 0; i < k; i++)
    {
        Node temp;
        temp.data = arr[i][0];
        temp.i = i;
        temp.j = 1;
        pq.push(temp);
        if (maxele < temp.data)
            maxele = temp.data;
    }
    while (true)
    {
        Node root = pq.top();
        pq.pop();
        if (minrange > maxele - root.data)
        {
            minrange = maxele - root.data;
            start = root.data;
            end = maxele;
        }
        if (root.j < n)
        {
            root.data = arr[root.i][root.j];
            root.j += 1;
            pq.push(root);
            if (root.data > maxele)
                maxele = root.data;
        }
        else
            break;
    }
    pair<int, int> ans;
    ans.first = start;
    ans.second = end;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[][5] = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};
    pair<int, int> ans = findSmallestRange(arr, 5, 3);
    cout << ans.first << " " << ans.second;
    return 0;
}