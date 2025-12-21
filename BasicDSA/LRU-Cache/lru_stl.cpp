#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        string key;
        int value;

        Node(string key, int value)
        {
            this->key = key;
            this->value = value;
        }
};

class LRUCache
{
    private:
        int maxSize;
        list<Node> l;
        unordered_map<string, list<Node>::iterator> m;

    public:
        LRUCache(int maxSize)
        {
            this->maxSize = maxSize > 1 ? maxSize : 1;
        }

        void insertKeyValue(string key, int value)
        {
            if (m.count(key) != 0)
            {
                auto it = m[key];
                it->value = value;
            }
            else
            {
                if (l.size() == maxSize)
                {
                    Node last = l.back();
                    m.erase(last.key);
                    l.pop_back();
                }
                Node newNode(key, value);
                l.push_front(newNode);
                m[key] = l.begin();
            }
        }

        int* getValue(string key)
        {
            if (m.count(key) != 0)
            {
                auto it = m[key];
                l.push_front(*it);
                l.erase(it);
                m[key] = l.begin();
                return &l.begin()->value;
            }
            return NULL;
        }

        string mostRecentKey()
        {
            return l.front().key;
        }
};

int main()
{
    LRUCache l(3);

    l.insertKeyValue("apple", 1);
    l.insertKeyValue("banana", 2);
    l.insertKeyValue("orange", 3);
    l.insertKeyValue("mango", 4);
    l.insertKeyValue("guava", 5);

    int *val = l.getValue("apple");
    if (val != NULL)
        cout<<"apple: "<<*val<<endl;
    else
        cout<<"apple: "<<-1<<endl;

    val = l.getValue("orange");
    if (val != NULL)
        cout<<"orange: "<<*val<<endl;
    else
        cout<<"orange: "<<-1<<endl;

    val = l.getValue("guava");
    if (val != NULL)
        cout<<"guava: "<<*val<<endl;
    else
        cout<<"guava: "<<-1<<endl;
    
    val = l.getValue("banana");
    if (val != NULL)
        cout<<"banana: "<<*val<<endl;
    else
        cout<<"banana: "<<-1<<endl;

    l.insertKeyValue("melon", 6);

    val = l.getValue("melon");
    if (val != NULL)
        cout<<"melon: "<<*val<<endl;
    else
        cout<<"melon: "<<-1<<endl;

    l.insertKeyValue("guava", 8);

    return 0;
}