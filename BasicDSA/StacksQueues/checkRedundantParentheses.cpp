#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string input)
{
    stack<char> s;
    bool ans = true;
    for (auto x: input)
    {
        if (x == '(')
            s.push(x);
        else if (x == ')')
        {
            if (s.empty())
            {
                ans = false;
                break;
            }
            s.pop();
        }
    }
    ans = ans && s.empty();
    return ans;
}

bool isCharOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool hasRedundant(string input)
{
    stack<char> s;

    bool balanced = true, redundant = false;

    for (auto x: input)
    {
        if (x == ')')
        {
            bool charsExist = false;
            while (!s.empty() && s.top() != '(')
            {
                if (isCharOperator(s.top()))
                    charsExist = true;
                s.pop();
            }
            if (s.empty())
            {
                balanced = false;
                break;
            }
            else if (!charsExist)
            {
                redundant = true;
            }
            s.pop();
        }
        else
        {
            s.push(x);
        }
    }
    balanced = balanced && s.empty();
    return (balanced && redundant);
}

int main()
{
    string s1 = "((a+b))";
    string s2 = "(a+(b)/c)";
    string s3 = "(a+b*(c-d))";

    cout<<hasRedundant(s1)<<endl;
    cout<<hasRedundant(s2)<<endl;
    cout<<hasRedundant(s3)<<endl;

    return 0;
}