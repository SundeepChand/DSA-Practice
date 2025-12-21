#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstring>
using namespace std::chrono;
using namespace std;

class SolutionStuti
{
public:
    static string remove(string s)
    {
        string gs = s;
        int tc = 0;
        while (true)
        {
            int n = gs.length();
            string ans = "";
            int i = 0, j = 1;
            bool f = false;
            while (j < n)
            {
                if (gs[i] == gs[j])
                {
                    f = true;
                    while (j < n && gs[i] == gs[j])
                    {
                        j++;
                        tc++;
                    }
                    i = j;
                    j++;
                    tc++;
                }
                else
                {
                    ans += gs[i];
                    i++;
                    j++;
                    tc++;
                }
            }
            if (i < n)
            {
                ans += gs[i];
            }
            gs = ans;
            if (f == false || gs.length() == 1)
            {
                break;
            }
        }
        cout << "tc " << tc << endl;
        return gs;
    }
};

class MySolution
{
public:
    static string remove(string s)
    {
        int n = s.length();
        string res = "";
        char prev = '\0';
        bool shouldPop = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != prev)
            {
                res += s[i];
                shouldPop = true;
            }
            else if (shouldPop)
            {
                res.pop_back();
                shouldPop = false;
            }
            prev = s[i];
        }
        if (res.length() == s.length())
            return s;
        return remove(res);
    }
};

class StdSolution
{
public:
    static char *removeUtil(char *str, char *last_removed)
    {

        // If length of string is 1 or 0
        if (str[0] == '\0' || str[1] == '\0')
            return str;

        // Remove leftmost same characters
        // and recur for remaining
        // string
        if (str[0] == str[1])
        {
            *last_removed = str[0];
            while (str[1] && str[0] == str[1])
                str++;
            str++;
            return removeUtil(str, last_removed);
        }

        // At this point, the first character
        // is definiotely different
        // from its adjacent. Ignore first
        // character and recursively
        // remove characters from remaining string
        char *rem_str = removeUtil(str + 1,
                                   last_removed);

        // Check if the first character
        // of the rem_string matches with
        // the first character of the
        // original string
        if (rem_str[0] && rem_str[0] == str[0])
        {
            *last_removed = str[0];

            // Remove first character
            return (rem_str + 1);
        }

        // If remaining string becomes
        // empty and last removed character
        // is same as first character of
        // original string. This is needed
        // for a string like "acbbcddc"
        if (rem_str[0] == '\0' &&
            *last_removed == str[0])
            return rem_str;

        // If the two first characters
        // of str and rem_str don't match,
        // append first character of str
        // before the first character of
        // rem_str.
        rem_str--;
        rem_str[0] = str[0];
        return rem_str;
    }

    // Function to remove
    static char *remove(char *str)
    {
        char last_removed = '\0';
        return removeUtil(str, &last_removed);
    }
};

class StdSoln2
{
public:
    static string removeDuplicates(string s, char ch)
    {

        // If length of string is 1 or 0
        if (s.length() <= 1)
        {
            return s;
        }

        int i = 0;
        while (i < s.length())
        {
            if (i + 1 < s.length() && s[i] == s[i + 1])
            {
                int j = i;
                while (j + 1 < s.length() && s[j] == s[j + 1])
                {
                    j++;
                }
                char lastChar = i > 0 ? s[i - 1] : ch;

                string remStr = removeDuplicates(
                    s.substr(j + 1, s.length()), lastChar);

                s = s.substr(0, i);
                int k = s.length(), l = 0;

                // Recursively remove all the adjacent
                // characters formed by removing the
                // adjacent characters
                while (remStr.length() > 0 && s.length() > 0 && remStr[0] == s[s.length() - 1])
                {

                    // Have to check whether this is the
                    // repeated character that matches the
                    // last char of the parent String
                    while (remStr.length() > 0 && remStr[0] != ch && remStr[0] == s[s.length() - 1])
                    {
                        remStr = remStr.substr(1, remStr.length());
                    }
                    s = s.substr(0, s.length() - 1);
                }
                s = s + remStr;
                i = j;
            }
            else
            {
                i++;
            }
        }
        return s;
    }

    static string remove(string s)
    {
        return removeDuplicates(s, ' ');
    }
};

int main()
{
    string tc = "";
    int n = 30000 / 2;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        tc += ('a' + cur);
        cur = (cur + 1) % 26;
    }

    string other = tc;
    reverse(other.begin(), other.end());
    tc += other;
    // cout << tc << endl;
    cout << "Running Stuti's algorithm:" << endl;
    auto start = high_resolution_clock::now();
    string s = SolutionStuti::remove(tc);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Took " << duration.count() << " ms" << endl;

    // cout << "\n";
    // cout << "Running My algorithm:" << endl;
    // start = high_resolution_clock::now();
    // s = MySolution::remove(tc);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<milliseconds>(stop - start);
    // cout << "Took " << duration.count() << " ms" << endl;

    cout << "\n";
    cout << "Running Standard algorithm:" << endl;
    start = high_resolution_clock::now();
    char oriStr[tc.size() + 1];
    strcpy(oriStr, tc.c_str());
    char *removedStr = StdSolution::remove(oriStr);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Took " << duration.count() << " ms" << endl;

    cout << "\n";
    cout << "Running 2nd Standard algorithm:" << endl;
    start = high_resolution_clock::now();
    s = StdSoln2::remove(tc);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "Took " << duration.count() << " ms" << endl;

    return 0;
}