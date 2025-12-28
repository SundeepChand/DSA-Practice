// https://leetcode.com/discuss/post/6244752/google-l3-interview-experience-questions-2utz/
/*
There will be some tasks, and each task can have one or more subtasks,
by default all tasks have completion time 1 unit, but the comp_time of
a parent task is the x if all subtasks have time x, otherwise it is
their sum, we have to find the total completion time
*/
#include <bits/stdc++.h>
using namespace std;

// Similar to https://leetcode.com/problems/employee-importance/description/
// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    unordered_map<int, Employee *> mp;

    int solve(int curId)
    {
        Employee *e = mp[curId];

        int res = e->importance;
        for (auto s : e->subordinates)
        {
            res += solve(s);
        }
        return res;
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto e : employees)
        {
            mp[e->id] = e;
        }

        return solve(id);
    }
};