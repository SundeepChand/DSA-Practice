#include <bits/stdc++.h>
using namespace std;

double area(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    return abs((
               p1.first * (p2.second - p3.second) +
               p2.first * (p3.second - p1.second) +
               p3.first * (p1.second - p2.second))) /
           2.0;
}

bool isInside(pair<int, int> b, pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    double A = area(p1, p2, p3);
    double A1 = area(b, p2, p3);
    double A2 = area(b, p1, p3);
    double A3 = area(b, p1, p2);
    if (A != A1 + A2 + A3)
        return false;

    // Check if the point lies on a line
    if (area(b, p1, p2) == 0 || area(b, p2, p3) == 0 || area(b, p1, p3) == 0)
        return false;
    return true;
}

double peri(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    return (
        sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)) +
        sqrt(pow(p2.first - p3.first, 2) + pow(p2.second - p3.second, 2)) +
        sqrt(pow(p1.first - p3.first, 2) + pow(p1.second - p3.second, 2)));
}

int main()
{
    int t;
    cin >> t;

    int temp = t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v[i].first = x, v[i].second = y;
        }

        pair<int, int> b;
        cin >> b.first >> b.second;

        // Brute force
        double min_peri = 1e18;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (isInside(b, v[i], v[j], v[k]))
                    {
                        double cur_peri = peri(v[i], v[j], v[k]);
                        if (cur_peri < min_peri)
                            min_peri = cur_peri;
                    }
                }
            }
        }

        cout << "Case #" << (temp - t) << ": ";
        if (min_peri == 1e18)
            cout << "IMPOSSIBLE";
        else
        {
            cout << setprecision(6) << fixed << min_peri;
        }
        cout << endl;
    }
    return 0;
}