/*
Given a mountain array mountainArr, 
return the minimum index such that mountainArr.get(index) == target. 
If such an index does not exist, return -1.

Link:
https://leetcode.com/problems/find-in-mountain-array
*/

#include <bits/stdc++.h>
using namespace std;

class MountainArray
{

public:
    vector<int> arr;
    int get(int index)
    {
        return arr[index];
    }
    int length()
    {
        return arr.size();
    }
};

int partition(MountainArray &m)
{
    int l = 0, r = m.length() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (m.get(mid) > m.get(mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}
int findInMountainArray(int target, MountainArray &mountainArr)
{
    int len = mountainArr.length();
    int pivot = partition(mountainArr);
    int l = 0, r = pivot - 1;
    if (mountainArr.get(pivot) == target)
        return pivot;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int a = mountainArr.get(mid);
        if (a == target)
            return mid;
        else if (a > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    l = pivot + 1, r = len - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int a = mountainArr.get(mid);
        if (a == target)
            return mid;
        else if (a > target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target = 3;
    MountainArray m;
    m.arr = {1, 2, 3, 4, 5, 3, 1};
    cout << "Output: " << findInMountainArray(target, m);
    return 0;
}