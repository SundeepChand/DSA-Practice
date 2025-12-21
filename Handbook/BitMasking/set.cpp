#include <bits/stdc++.h>
using namespace std;

class Set
{
private:
    // A class to represent a subset of {0, 1, ... 31}
    int x;

public:
    Set() : x(0) {}
    Set(int n) : x(n) {}

    void insert(int n)
    {
        if (n >= 0 && n <= 31)
            x |= (1 << n);
    }

    void printAllElements()
    {
        cout << "{";
        for (int i = 0; i < 31; i++)
        {
            if (x & (1 << i))
                cout << i << ", ";
        }
        cout << "}" << endl;
    }

    int size()
    {
        return __builtin_popcount(x);
    }

    Set Union(Set other)
    {
        return Set(x | other.x);
    }

    Set intersection(Set other)
    {
        return Set(x & other.x);
    }

    Set complement(Set other)
    {
        return Set(~x);
    }

    Set difference(Set other)
    {
        return Set(x & ~other.x);
    }

    void printAllSubsets()
    {
        cout << "Printing all subsets:";
        int b = 0;
        do
        {
            Set(b).printAllElements();
        } while (b = (b - x) & x);
    }
};

int main()
{
    // Create a set
    cout << "Set operations:\n";
    Set s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    s.insert(8);
    cout << s.size() << endl;
    s.printAllElements();
    s.printAllSubsets();

    Set t;
    t.insert(3);
    t.insert(6);
    t.insert(8);
    t.insert(9);

    Set u = s.Union(t);
    u.printAllElements();

    return 0;
}