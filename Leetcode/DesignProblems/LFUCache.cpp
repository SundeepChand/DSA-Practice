// https://leetcode.com/problems/lfu-cache/
#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    int n;
    map<int, list<int>> freq;
    map<int, pair<int, int>> keys;

    LFUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (keys.find(key) == keys.end())
            return -1;
        int ctr = keys[key].first, value = keys[key].second;
        keys[key].first = ctr + 1;
        freq[ctr].remove(key);
        if (freq[ctr].size() == 0)
            freq.erase(ctr);
        freq[ctr + 1].push_back(key);
        return value;
    }

    void put(int key, int value)
    {
        if (n == 0)
            return;

        int ctr = 0;
        if (keys.find(key) != keys.end())
            ctr = keys[key].first;

        if (keys.find(key) == keys.end() && (keys.size() + 1) > n)
        {
            // Invalidate the cache
            int keyToRemove = freq.begin()->second.front();
            freq.begin()->second.pop_front();
            keys.erase(keyToRemove);
        }

        keys[key] = {ctr + 1, value};
        freq[ctr].remove(key);
        if (freq[ctr].size() == 0)
            freq.erase(ctr);
        freq[ctr + 1].push_back(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */