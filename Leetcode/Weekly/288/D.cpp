#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    ll solve(multiset<ll> &flowers, ll comp, ll minPartial, ll newFlowers, ll &target, ll &full, ll &partial)
    {
        // cout<<"DEB: "<<comp<<" "<<minPartial<<" "<<newFlowers<<endl;
        if (newFlowers == 0 or flowers.size() == 0)
        {
            return comp * full + minPartial * partial;
        }
        if (flowers.size() == 1)
        {
            ll minFlowers = *flowers.begin();
            ll ans = comp * full + (minFlowers)*partial;
            if (newFlowers >= (target - minFlowers))
            {
                ans = max(ans, (comp + 1) * full);
            }
            return ans;
        }

        ll ans = 0;
        ll largestGarden = *flowers.rbegin();
        if (newFlowers >= (target - largestGarden))
        {
            flowers.erase(--flowers.end());
            if (flowers.empty())
                return comp * full + minPartial * partial;
            ans = max(ans, solve(flowers, comp + 1, *flowers.begin(), newFlowers - (target - largestGarden), target, full, partial));
            flowers.insert(largestGarden);
        }

        ll smallestPartial = *flowers.begin();
        flowers.erase(flowers.begin());
        if (smallestPartial == target - 1)
        {
            ans = max(ans, solve(flowers, comp + 1, *flowers.begin(), newFlowers - 1, target, full, partial));
        }
        else
        {
            flowers.insert(smallestPartial + 1);
            ans = max(ans, solve(flowers, comp, *flowers.begin(), newFlowers - 1, target, full, partial));
            flowers.erase(flowers.find(smallestPartial + 1));
        }
        flowers.insert(smallestPartial);
        return ans;
    }

    long long maximumBeauty(vector<int> &flowers, long long newFlowers, ll target, ll full, ll partial)
    {

        multiset<ll> m(flowers.begin(), flowers.end());

        ll comp = 0;
        while (!m.empty() and *m.rbegin() >= target)
        {
            comp++;
            auto it = m.end();
            it--;
            m.erase(it);
        }

        if (m.empty())
        {
            return full * comp;
        }

        return solve(m, comp, *m.begin(), newFlowers, target, full, partial);
    }
};