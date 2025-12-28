// https://leetcode.com/discuss/post/6352084/google-l4-phone-screening-round-by-anony-aa15/
#include <bits/stdc++.h>
using namespace std;

/*

NYC: (LAX, 0, 6), (LAX, 1, 4)
LAX: (SFO, 5, 7)

start: NYC
dest: SFO

Approach:
Using dijkstra keep track of the minimum time to reach an airport, once the dest airport
is reached, end the search.
        NYC  LAX  SFO
times:    0    4    7

V = No of airports
E = No of flights

Time Complexity: O((V + E) logV), Space complexity: O(1)

*/
class Solution
{
public:
    bool isReachableBfs(const vector<vector<vector<int>>> &adj, map<string, int> &airportCodes, string start, string destination)
    {
        int n = adj.size();

        if (airportCodes.find(start) == airportCodes.end() or airportCodes.find(destination) == airportCodes.end())
        {
            // No flights available
            return false;
        }

        int originAirportCode = airportCodes[start], destinationAirportCode = airportCodes[destination];
        if (originAirportCode == destinationAirportCode)
        {
            return true;
        }

        // Dijkstra
        vector<int> times(n, INT_MAX);

        set<vector<int>> st;
        st.insert({0, originAirportCode});
        times[originAirportCode] = 0;

        while (!st.empty())
        {
            auto front = *st.begin();
            st.erase(st.begin());

            int u = front[1], minTime = front[0];

            // minTime denotes the current min time to reach the node u
            for (auto nbr : adj[u])
            {
                int flightStartTime = nbr[0], flightEndTime = nbr[1], curDest = nbr[2];
                if (flightStartTime < minTime)
                {
                    // This can be further optimized by starting the iteration from the first ge element
                    // using binary search.
                    continue;
                }

                if (curDest == destinationAirportCode)
                {
                    return true;
                }
                if (flightEndTime < times[curDest])
                {
                    st.erase({times[curDest], curDest});
                    st.insert({flightEndTime, curDest});
                    times[curDest] = flightEndTime;
                }
            }
        }
        return false;
    }

    // Returns the minimum time to reach the destination, -1 if destination not reachable
    int getMinTime(const vector<vector<vector<int>>> &adj, map<string, int> &airportCodes, string start, string destination)
    {
        int n = adj.size();

        if (airportCodes.find(start) == airportCodes.end() or airportCodes.find(destination) == airportCodes.end())
        {
            // No flights available
            return -1;
        }

        int originAirportCode = airportCodes[start], destinationAirportCode = airportCodes[destination];
        if (originAirportCode == destinationAirportCode)
        {
            return 0;
        }

        // Dijkstra
        vector<int> times(n, INT_MAX);

        set<vector<int>> st;
        st.insert({0, originAirportCode});
        times[originAirportCode] = 0;

        while (!st.empty())
        {
            auto front = *st.begin();
            st.erase(st.begin());

            int u = front[1], minTime = front[0];

            // minTime denotes the current min time to reach the front
            for (auto nbr : adj[u])
            {
                int flightStartTime = nbr[0], flightEndTime = nbr[1], curDest = nbr[2];
                if (flightStartTime < minTime)
                {
                    // This can be further optimized by starting the iteration from the first ge element
                    // using binary search.
                    continue;
                }
                if (flightEndTime < times[curDest])
                {
                    st.erase({times[curDest], curDest});
                    st.insert({flightEndTime, curDest});
                    times[curDest] = flightEndTime;
                }
            }
        }
        return times[destinationAirportCode] == INT_MAX ? -1 : times[destinationAirportCode];
    }
};

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
        int n, e;
        cin >> n >> e;

        vector<vector<vector<int>>> adj(n, vector<vector<int>>());

        map<string, int> airportCodes;

        for (int i = 0; i < e; i++)
        {
            string originAirport, destinationAirport;

            int startTime, endTime;

            cin >> originAirport >> destinationAirport >> startTime >> endTime;

            if (airportCodes.find(originAirport) == airportCodes.end())
            {
                airportCodes[originAirport] = airportCodes.size();
            }
            if (airportCodes.find(destinationAirport) == airportCodes.end())
            {
                airportCodes[destinationAirport] = airportCodes.size();
            }

            int originAirportCode = airportCodes[originAirport], destinationAirportCode = airportCodes[destinationAirport];
            adj[originAirportCode].push_back({startTime, endTime, destinationAirportCode});
        }

        string origin, destination;
        cin >> origin >> destination;

        Solution s;
        cout << s.isReachableBfs(adj, airportCodes, origin, destination) << " " << s.getMinTime(adj, airportCodes, origin, destination) << endl;
    }
    return 0;
}

/*
1 7
0 -1
1 12
0 -1
1 13
0 -1
1 5
1 10
1 9
0 -1
1 6
1 7
1 8
1 6
0 -1
1 9
1 105


*/