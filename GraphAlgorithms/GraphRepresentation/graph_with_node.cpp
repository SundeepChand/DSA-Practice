#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    vector<string> nbrs;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
public:
    unordered_map<string, Node *> m;

    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
            m[y]->nbrs.push_back(x);
    }

    void printAdjList()
    {
        for (auto cityPair : m)
        {
            string city = cityPair.first;
            cout << city << ": ";
            for (string nbrs : cityPair.second->nbrs)
                cout << nbrs << ", ";
            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.printAdjList();
    return 0;
}