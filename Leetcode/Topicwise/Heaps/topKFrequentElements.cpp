#include <bits/stdc++.h>
using namespace std;

class SolutionWithHeaps
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        set<pair<int, int>> s;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            s.insert({-(it->second), it->first});
        }

        vector<int> ans;
        auto it = s.begin();
        for (int i = 0; i < k; i++, it++)
            ans.push_back(it->second);
        return ans;
    }
};

class SolutionQuickSelect
{
public:
    vector<int> generateAnswer(vector<int> &unique, int i)
    {
        int n = unique.size();
        vector<int> ans;
        for (; i < n; i++)
            ans.push_back(unique[i]);
        return ans;
    }

    vector<int> KthFrequent(unordered_map<int, int> &freq, vector<int> &unique, int lo, int hi, int k)
    {
        int pivot = lo, n = unique.size();
        int i = lo + 1, j = lo + 1;

        if (lo >= hi)
            return generateAnswer(unique, lo);
        if (hi - lo == 1)
        {
            if (freq[unique[hi]] < freq[unique[lo]])
            {
                swap(unique[hi], unique[lo]);
            }
            if (hi == n - k)
                return generateAnswer(unique, hi);
            return generateAnswer(unique, lo);
        }

        while (j <= hi)
        {
            if (freq[unique[j]] <= freq[unique[pivot]])
            {
                swap(unique[i], unique[j]);
                i++;
            }
            j++;
        }

        swap(unique[i - 1], unique[pivot]);

        if (i < n - k + 1)
            return KthFrequent(freq, unique, i, hi, k);
        else if (i > n - k + 1)
            return KthFrequent(freq, unique, lo, i - 2, k);

        return generateAnswer(unique, i - 1);
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        vector<int> unique;
        for (int x : nums)
        {
            freq[x]++;
            if (freq[x] == 1)
                unique.push_back(x);
        }

        return KthFrequent(freq, unique, 0, unique.size() - 1, k);
    }
};

class SolutionWithBucketing
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<set<int>> freq(n + 1, set<int>());
        unordered_map<int, int> m;
        for (int x : nums)
        {
            m[x]++;
            if (m[x] == 1)
            {
                freq[1].insert(x);
            }
            else
            {
                freq[m[x] - 1].erase(x);
                freq[m[x]].insert(x);
            }
        }

        vector<int> ans;
        for (int i = n; k > 0 and i >= 0; i--)
        {
            for (auto it = freq[i].begin(); k > 0 and it != freq[i].end(); it++)
            {
                ans.push_back(*it);
                k--;
            }
        }
        return ans;
    }
};