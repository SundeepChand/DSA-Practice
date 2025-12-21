#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    bool isRoot = (path[0] == '/');
    deque<string> s;

    int n = path.length();
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (path[i] == '/')
            continue;
        string temp = "";
        while (i < n && path[i] != '/')
        {
            temp += path[i];
            i++;
        }
        if (temp == "..")
        {
            if (!isRoot && !flag)
            {
                s.push_back(temp);
            }
            else if (!s.empty())
            {
                s.pop_back();
            }
        }
        else if (temp != ".")
        {
            flag = true;
            s.push_back(temp);
        }
    }
    
    string ans = "";
    if (isRoot)
        ans = "/";
    while (!s.empty())
    {
        ans += s.front();
        s.pop_front();
        if (!s.empty())
            ans += '/';
    }
    return ans;
}

int main()
{
    string path1 = "../home/desktop/../../opt/ros";
    string path2 = "/../home/desktop/../../opt/ros";
    string path3 = "/home/desktop/../opt/ros";
    string path4 = "./home/desktop///..//./opt/ros";

    cout<<simplifyPath(path1)<<endl;
    cout<<simplifyPath(path2)<<endl;
    cout<<simplifyPath(path3)<<endl;
    cout<<simplifyPath(path4)<<endl;
    return 0;
}