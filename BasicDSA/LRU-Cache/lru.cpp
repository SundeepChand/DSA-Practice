#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class LinkedListNode
{
    public:
        string key;
        int val;
        LinkedListNode *next, *prev;

        LinkedListNode(string key, int val)
        {
            this->key = key;
            this->val = val;
            next = prev = NULL;
        }
};

class LRUCache
{
    private:
        int maxSize;
        LinkedListNode* head, *tail;
        unordered_map<string, LinkedListNode*> u;

    private:
        void moveNodeToFront(string key)
        {
            LinkedListNode *node = u[key];
            if (node != head && node != tail)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->prev = NULL;
                node->next = head;
                head->prev = node;
                head = node;
            }
            else if (node == tail)
            {
                node->prev->next = NULL;
                tail = node->prev;
                node->prev = NULL;
                node->next = head;
                head->prev = node;
                head = node;
            }
        }

    public:
        LRUCache(int size = 10)
        {
            // Create a cache of size equal to size
            maxSize = size > 1 ? size : 2; // Max size should be at least 2
            head = tail = NULL;
        }
        void insert(string key, int value)
        {
            // O(1)
            // If the key exists in the cache
            if (u.find(key) != u.end())
            {
                moveNodeToFront(key);
                head->val = value;
                return;
            }
            // If the key does not exist
            if (u.size() >= maxSize)
            {
                // Delete the last node in the list.
                LinkedListNode* cur = tail;
                u.erase(tail->key);
                tail = tail->prev;
                tail->next = NULL;
                delete cur;
            }
            // Insert the element at the beginning of the list
            LinkedListNode *newNode = new LinkedListNode(key, value);
            if (head == NULL && tail == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                newNode->prev = NULL;
                head->prev = newNode;
                head = newNode;
            }
            u.insert({ key, newNode });
        }

        int getValue(string key)
        {
            // O(1)
            if (u.find(key) != u.end())
            {
                // Move the key node to the start of the list.
                moveNodeToFront(key);
                return head->val;
            }
            else
            {
                // The queried key does not exist in the cache.
                // We can populate the value, after fetching it from the
                // datastore and return it.
                return -1;
            }
        }

        string getMostRecentKey()
        {
            // O(1)
            if (head != NULL)
            {
                return head->key;
            }
            else
            {
                return "NULL";
            }
        }

        void printCache()
        {
            // O(N)
            LinkedListNode *cur = head;
            while (cur != NULL)
            {
                cout<<"("<<cur->key<<", "<<cur->val<<"), ";
                cur = cur->next;
            }
            cout<<endl;
        }
};

int main()
{
    LRUCache l(3);

    l.insert("apple", 1);
    l.insert("banana", 2);
    l.insert("orange", 3);
    l.insert("mango", 4);
    l.insert("guava", 5);

    l.printCache();

    cout<<"apple: "<<l.getValue("apple")<<endl;
    cout<<"orange: "<<l.getValue("orange")<<endl;
    cout<<"guava: "<<l.getValue("guava")<<endl;
    cout<<"banana: "<<l.getValue("banana")<<endl;

    l.insert("melon", 6);
    cout<<"melon: "<<l.getValue("melon")<<endl;
    l.insert("guava", 8);

    cout<<endl;
    l.printCache();

    return 0;
}