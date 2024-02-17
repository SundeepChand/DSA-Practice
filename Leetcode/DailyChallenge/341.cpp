#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    stack<vector<vector<NestedInteger>::iterator>> s;
    vector<NestedInteger>::iterator cur_it, cur_end;
    vector<NestedInteger> nestedList;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->nestedList = nestedList;

        cur_it = (this->nestedList).begin();
        cur_end = (this->nestedList).end();
    }

    int next()
    {
        if (cur_it->isInteger())
        {
            int val = cur_it->getInteger();
            cur_it++;
            return val;
        }
        // cout<<"NEXT: "<<(cur_it == cur_end)<<endl;
        if (cur_it == cur_end)
        {
            while (cur_it == cur_end and !s.empty())
            {
                cur_it = s.top()[0], cur_end = s.top()[1];
                s.pop();
            }
            cur_it++;
        }

        vector<NestedInteger> list;
        while (!(cur_it->isInteger()))
        {
            s.push({cur_it, cur_end});
            // list = cur_it->getList();
            auto it = cur_it;
            cur_it = cur_it.begin(), cur_end = list.end();
            // if (cur_it->isInteger())
            // cout<<"DEB: "<<cur_it->isInteger()<<" "<<cur_it->getInteger()<<endl;
            cout << "DEB2: " << (!cur_it->isInteger()) << endl;
        }
        int val = cur_it->getInteger();
        // int val = 0;
        cout << "Value: " << val << endl;
        cur_it++;
        return val;
    }

    bool hasNext()
    {
        auto temp_it = cur_it, temp_end = cur_end;
        auto temp_stack = s;
        if (temp_it == temp_end)
        {
            while (temp_it == temp_end and !temp_stack.empty())
            {
                temp_it = temp_stack.top()[0], temp_end = temp_stack.top()[1];
                temp_stack.pop();
            }
            temp_it++;
        }
        // cout<<(temp_it == temp_end)<<endl;
        return temp_it != temp_end;
    }
};

/**
 * @brief
 *
 * @return * Your*
 *NestedIterator i(nestedList);
 *while (i.hasNext()) cout << i.next();
 */