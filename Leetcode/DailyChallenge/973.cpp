#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    static int dist(vector<int> &a)
    {
        return (a[0] * a[0] + a[1] * a[1]);
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return dist(a) < dist(b);
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        nth_element(points.begin(), points.begin() + k, points.end(), cmp); // Performs quick select
        points.resize(k);
        return points;
    }
};