#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define FF first
#define SS second
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
#define int ll

bool foundNonEmpytyInVicinity(vector<string> &v, set<pair<int, int>> &st)
{
    int n = v.size(), m = v[0].size();

    vector<int> di = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dj = {-1, 1, -1, 0, 1, -1, 0, 1};

    for (auto p : st)
    {
        int i = p.first, j = p.second;
        for (int k = 0; k < 8; k++)
        {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 and nj >= 0 and ni < n and nj < m and st.find({ni, nj}) == st.end() and v[ni][nj] != '.')
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '*')
                {
                    set<pair<int, int>> st;
                    int nj = j + 1;
                    if (nj < m and v[i][nj] == '*')
                    {
                        // * *
                        // x x
                        int ni = i + 1;
                        if (ni >= n or v[ni][j] == v[ni][nj])
                        {
                            flag = false;
                        }
                        else
                        {
                            st.insert({i, j});
                            st.insert({i, nj});
                            v[i][j] = v[i][nj] = 'o';
                            if (v[ni][j] == '*')
                            {
                                st.insert({ni, j});
                                v[ni][j] = 'o';
                            }
                            else
                            {
                                st.insert({ni, nj});
                                v[ni][nj] = 'o';
                            }
                        }
                    }
                    else
                    {
                        int ni = i + 1, pj = j - 1;
                        if (ni >= n or v[ni][j] == '.')
                        {
                            flag = false;
                        }
                        else if (pj >= 0 and nj < m)
                        {
                            if (v[ni][pj] == v[ni][nj])
                            {
                                flag = false;
                            }
                            else if (v[ni][pj] == '*')
                            {
                                // x *
                                // * *
                                st.insert({i, j});
                                st.insert({ni, pj});
                                st.insert({ni, j});
                                v[i][j] = v[ni][j] = v[ni][pj] = 'o';
                            }
                            else if (v[ni][nj] == '*')
                            {
                                // * x
                                // * *
                                st.insert({i, j});
                                st.insert({ni, j});
                                st.insert({ni, nj});
                                v[i][j] = v[ni][j] = v[ni][nj] = 'o';
                            }
                            else
                            {
                                flag = false;
                            }
                        }
                        else if (pj >= 0)
                        {
                            if (v[ni][pj] != '*')
                            {
                                flag = false;
                            }
                            else
                            {
                                // x *
                                // * *
                                st.insert({i, j});
                                st.insert({ni, pj});
                                st.insert({ni, j});
                                v[i][j] = v[ni][j] = v[ni][pj] = 'o';
                            }
                        }
                        else if (nj < m)
                        {
                            if (v[ni][nj] != '*')
                            {
                                flag = false;
                            }
                            else
                            {
                                // * x
                                // * *
                                st.insert({i, j});
                                st.insert({ni, j});
                                st.insert({ni, nj});
                                v[i][j] = v[ni][j] = v[ni][nj] = 'o';
                            }
                        }
                    }
                    // Rectangle has been localised, now check the vicinity of the rectangle
                    if (foundNonEmpytyInVicinity(v, st))
                    {
                        // cerr << "Here7" << endl;
                        flag = false;
                    }
                }
            }
        }

        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}