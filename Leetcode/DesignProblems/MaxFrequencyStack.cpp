#include <bits/stdc++.h>
using namespace std;

class FreqStack
{
public:
    int timer;
    map<int, pair<int, stack<int>>> m;

    set<vector<int>> s;

    FreqStack()
    {
        timer = 0;
    }

    void push(int val)
    {
        int cur = 0;
        if (m.find(val) != m.end())
        {
            cur = m[val].first;
            s.erase({-cur, -m[val].second.top(), val});
        }
        m[val].first = cur + 1;
        m[val].second.push(timer);
        s.insert({-cur - 1, -timer, val});
        timer++;
    }

    int pop()
    {
        if (s.empty())
            return -1;

        auto it = s.begin();

        auto temp = *it;
        m[temp[2]].second.pop();
        m[temp[2]].first--;
        if (m[temp[2]].first == 0)
            m.erase(temp[2]);

        s.erase(it);
        if (-temp[0] > 1)
            s.insert({temp[0] + 1, -m[temp[2]].second.top(), temp[2]});

        return temp[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */