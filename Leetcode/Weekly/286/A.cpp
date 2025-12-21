class Solution
{
public:
    typedef long long ll;

    vector<ll> pals;

    void generatePals(int i, int len, string &cur)
    {
        if (len % 2 == 1 && i > len / 2)
        {
            pals.push_back(stoll(cur));
            return;
        }
        else if (len % 2 == 0 && i == len / 2)
        {
            pals.push_back(stoll(cur));
            return;
        }

        for (char j = i == 0 ? '1' : '0'; j <= '9'; j++)
        {
            cur[i] = j;
            cur[len - 1 - i] = j;
            generatePals(i + 1, len, cur);
        }
    }

    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        string cur;
        for (int i = 0; i < intLength; i++)
        {
            cur += ' ';
        }
        generatePals(0, intLength, cur);

        // for (auto x : pals)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return pals;
    }
};

class Solution
{
public:
    typedef long long ll;

    ll generatePals(int i, int ct, int len, string &cur)
    {
        // if (len % 2 == 1 && i == len / 2)
        // {
        //     // pals.push_back(stoll(cur));
        //     return stoll(cur);
        // }
        // else if (len % 2 == 0 && i == len / 2)
        // {
        //     // pals.push_back(stoll(cur));
        //     return stoll(cur);
        // }
        if (ct == 0)
            return stoll(cur);

        int n = len - 1 - i - i - 1;
        ll ctb = pow(10, n);
        int d = ct - 1;
        if (i != len - 1 - i)
            d = ct / ctb;
        cout << "DEB: " << d << endl;
        if (i == 0 && d > 8)
            return -1;
        else if (d > 9)
            return -1;

        cur[i] = cur[len - 1 - i] = d + '0';
        if (i == 0)
        {
            cur[i]++, cur[len - 1 - i]++;
        }
        return generatePals(i + 1, ctb == 0 ? 0 : ct - d * ctb, len, cur);
        // for (char j = i == 0 ? '1' : '0'; j <= '9'; j++)
        // {
        //     cur[i] = j;
        //     cur[len - 1 - i] = j;
        //     generatePals(i + 1, len, cur);
        // }
    }

    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        string cur;
        for (int i = 0; i < intLength; i++)
        {
            cur += ' ';
        }
        vector<ll> ans;

        int n = queries.size();
        // for (int i = 0; i < n; i++)
        // {
        //     string temp = cur;
        //     ans.push_back(generatePals(0, queries[i], intLength, temp));
        // }
        // return ans;
        return {generatePals(0, 89, intLength, cur)};

        // for (auto x : pals)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // return pals;
    }
};