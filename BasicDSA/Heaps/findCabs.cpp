#include <bits/stdc++.h>
using namespace std;

class Cab
{
    public:
        string name;
        int x, y;

        Cab(string name, int x, int y)
        {
            this->name = name;
            this->x = x;
            this->y = y;
        }

        bool operator< (Cab that)
        {
            double d1 = this->x * this->x + this->y * this->y;
            double d2 = that.x * that.x + that.y * that.y;
            return d1 < d2;
        }
};

class Comparator
{
    public:
        bool operator()(Cab* a, Cab* b)
        {
            return *a < *b;
        }
};

vector<Cab> findKNearestCabs(vector<Cab> v, int k)
{
    int n = v.size();

    priority_queue<Cab*, vector<Cab*>, Comparator> q; // Max pq based on dist
    for (int i = 0; i < n; i++)
    {
        if (q.size() < k)
            q.push(&v[i]);
        else
        {
            if (v[i] < *(q.top()))
            {
                q.pop();
                q.push(&v[i]);
            }
        }
    }

    vector<Cab> ans;
    while (!q.empty())
    {
        ans.push_back(*(q.top()));
        q.pop();
    }
    return ans;
}

int main()
{
    vector<Cab> v = {
        Cab("C1", 1, 0),
        Cab("C2", 2, 1),
        Cab("C3", 3, 6),
        Cab("C4", -5, 2),
        Cab("C5", 1, -4)
    };
    int k = 3;

    vector<Cab> ans = findKNearestCabs(v, k);
    for (auto x: ans)
    {
        cout<<x.name<<", ";
    }
    return 0;
}