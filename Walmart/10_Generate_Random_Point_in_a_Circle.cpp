/*
Given the radius and the position of the center of a circle, 
implement the function randPoint which generates a uniform random point inside the circle.

Link:
https://leetcode.com/problems/generate-random-point-in-a-circle
*/

#include <bits/stdc++.h>
using namespace std;

double x;
double y;
double r;
void Solution(double radius, double x_center, double y_center)
{
    x = x_center;
    y = y_center;
    r = radius;
}
vector<double> randPoint()
{
    vector<double> ans;
    double rad = (double)rand() / RAND_MAX;
    rad = sqrt(rad) * r;
    double teta = (double)rand() / RAND_MAX;
    teta *= 360.0;
    ans.push_back(x + rad * cos(teta));
    ans.push_back(y + rad * sin(teta));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution(1.0, 0.0, 0.0);
    vector<double> ans = randPoint();
    for (auto i : ans)
        cout << i << " ";

    return 0;
}