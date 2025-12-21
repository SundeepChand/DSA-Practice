#include <bits/stdc++.h>
using namespace std;

long minCost(int numProjects, vector<int> projectId, vector<int> bid)
{
    vector<int> cost(numProjects, INT_MAX);

    int n = projectId.size();
    for (int i = 0; i < n; i++)
        cost[projectId[i]] = min(cost[projectId[i]], bid[i]);

    long ans = 0;
    for (int i = 0; i < numProjects; i++)
    {
        if (cost[i] == INT_MAX)
            return -1;
        ans += (long)cost[i];
    }
    return ans;
}

long getMaxFun2(vector<int> singer, vector<int> length)
{
    vector<vector<int>> pairs;
    int n = singer.size();

    for (int i = 0; i < n; i++)
        pairs.push_back({length[i], singer[i]});
    sort(pairs.begin(), pairs.end());

    long ans = 0;
    set<int> prev;
    for (int i = 0; i < n; i++)
    {
        prev.insert(pairs[i][1]);
        ans += (long)(prev.size()) * pairs[i][0];
    }
    return ans;
}

long getMaxFun1(vector<int> singer, vector<int> length)
{
    map<int, multiset<int>> m;

    int n = singer.size();
    for (int i = 0; i < n; i++)
        m[singer[i]].insert(length[i]);

    long ans = 0, cur = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cur++;
        ans += long(*(it->second.begin())) * cur;
        it->second.erase(it->second.begin());
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (auto x : it->second)
        {
            ans += long(x) * cur;
        }
    }
    return ans;
}

long getMaxFun(vector<int> singer, vector<int> length)
{
    return max(getMaxFun1(singer, length), getMaxFun2(singer, length));
}

void dfs(vector<vector<int>> &adj, vector<int> &A, int u, int v, int par, string &cur, string &res)
{
    cur.push_back(A[u] + '0');
    if (u == v)
    {
        res = cur;
        cur.pop_back();
        return;
    }

    for (auto nbr : adj[u])
    {
        if (res == "")
        {
            if (nbr != par)
                dfs(adj, A, nbr, v, u, cur, res);
        }
        else
            break;
    }
    cur.pop_back();
}

string getPath(vector<vector<int>> &adj, vector<int> &A, int u, int v)
{
    string cur = "", res = "";
    dfs(adj, A, u, v, -1, cur, res);
    cerr << "Res: " << res << endl;
    return res;
}

int solve(vector<vector<int>> &adj, vector<int> &A, int u, int v)
{
    string path = getPath(adj, A, u, v);

    int n = path.size();

    if (u == v or path[0] == path[n - 1])
        return 0;

    cerr << "Here3" << endl;

    int i = 1;
    while (path[i] == path[i - 1])
        i++;
    int ans = i;
    i = n - 2;
    while (path[i] == path[i + 1])
        i--;
    ans = min(ans, n - 1 - i);
    return ans;
}

vector<int> binPath(int N, int Q, vector<vector<int>> edge, vector<int> A, vector<vector<int>> query)
{
    vector<vector<int>> adj(N, vector<int>());

    for (auto e : edge)
    {
        int u = e[0], v = e[1];
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cerr << "Here2" << endl;

    vector<int> ans(Q);
    for (int i = 0; i < Q; i++)
    {
        ans[i] = solve(adj, A, query[i][0] - 1, query[i][1] - 1);
    }
    return ans;
}

int makeSingleDigit(int v)
{
    int sum = 0;
    while (v)
    {
        sum += (v % 10);
        v /= 10;
    }
    if (sum < 10)
        return sum;
    return makeSingleDigit(sum);
}

void resultantCombination(string str, int birthYear, char luckyChar)
{
    int x = 0, y = 0, z = tolower(luckyChar) - 'a' + 1;
    for (char c : str)
    {
        c = tolower(c);
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
            x++;
    }

    while (birthYear)
    {
        y += (birthYear % 10);
        birthYear /= 10;
    }

    x = makeSingleDigit(x), y = makeSingleDigit(y), z = makeSingleDigit(z);
    cout << x << y << z << endl;

    if (x == y and y == z)
        cout << 1;
    else
        cout << 0;
    cout << endl;
}

int getMinimumFileChanged(vector<int> fileSize, vector<int> minSize)
{
    int n = fileSize.size();
    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        diff[i] = fileSize[i] - minSize[i];
    }

    sort(diff.begin(), diff.end());

    // if (n == 1)
    // {
    //     return diff[0] < 0 ? -1 : 0;
    // }

    int i = 0, j = n - 1;
    vector<bool> changed(n, false);
    while (i <= j)
    {
        if (diff[i] >= 0)
            break;
        if ((i == j and diff[i] < 0) or (diff[i] < 0 and diff[j] < 0))
            return -1;

        int need = -diff[i], give = diff[j];
        if (need > give)
            diff[j] = 0, diff[i] += give, changed[i] = changed[j] = true, j--;
        else if (need == give)
            diff[i] = diff[j] = 0, changed[i] = changed[j] = true, i++, j--;
        else if (need < give)
            diff[i] = 0, diff[j] -= need, changed[i] = changed[j] = true, i++;
    }

    cout << "Idx: ";
    cout << i << " " << j << endl;
    cout << "Changed: ";
    for (auto c : changed)
    {
        cout << c << " ";
    }
    cout << endl;

    int ans = 0;
    for (auto c : changed)
        ans += c;
    return ans;
}

// int main()
// {
//     //     ios_base::sync_with_stdio(false);
//     //     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     //     freopen("in.txt", "r", stdin);
//     //     freopen("out.txt", "w", stdout);
//     // #endif

//     // int N, Q;
//     // cin >> N >> Q;

//     // vector<vector<int>> edge(N - 1, vector<int>(2));
//     // for (int i = 0; i < N - 1; i++)
//     // {
//     //     cin >> edge[i][0] >> edge[i][1];
//     // }

//     // vector<int> A(N);
//     // for (int i = 0; i < N; i++)
//     // {
//     //     cin >> A[i];
//     // }

//     // vector<vector<int>> q(Q, vector<int>(2));
//     // for (int i = 0; i < Q; i++)
//     // {
//     //     cin >> q[i][0] >> q[i][1];
//     // }

//     // cerr << "Here" << endl;
//     // vector<int> ans = binPath(N, Q, edge, A, q);
//     // for (int x : ans)
//     //     cout << x << endl;
//     // return 0;

//     // string n1 = "Sam", n2 = "Robinhood";
//     // cout << n1 << endl;
//     // resultantCombination(n1, 1000, 'a');
//     // resultantCombination(n2, 1989, 'N');

//     // int x = 5;
//     // cout << x + 3 << endl;
//     int n = 5;
//     //
//     //
//     vector<int> fileSize = {4, 1, 5, 2, 3}, minSize = {3, 2, 2, 1, 4};

//     cout << getMinimumFileChanged(fileSize, minSize) << endl;
// }

int solve(vector<int> arr, int cnt, int i, vector<vector<int>> &dp)
{
    cerr << cnt << " " << i << endl;
    if (cnt >= arr.size())
    {
        return 0;
    }
    if (arr.size() <= i + cnt)
    {
        return 0;
    }
    // if(i==arr.size() || sum<ssf){
    //     return false;
    // }

    if (dp[i][cnt] != -1)
    {
        return dp[i][cnt];
    }
    int ans = arr[i] + solve(arr, cnt + i + 1, i, dp);
    ans = max(ans, solve(arr, cnt, i + 1, dp));

    // return ans;
    // if(ans){
    //     return dp[i][cnt]=ans;
    // }
    return dp[i][cnt] = ans;
}

int main()
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // if(s==0){
        //         cout<< "YES"<<endl;
        //         continue;
        //     }

        vector<vector<int>> dp(arr.size(), vector<int>(n + 1, -1));
        int ans = solve(arr, 0, 0, dp);
        //// if(ans)
        //// {
        cout << ans << endl;
        //// }
        //// else cout<<"NO"<<endl;
    }
    return 0;
}
