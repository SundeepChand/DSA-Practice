// https://leetcode.com/problems/lru-cache/
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class ListNode
    {
    public:
        int key, val;
        ListNode *next, *prev;

        ListNode(int k, int v)
        {
            key = k, val = v;
            next = prev = NULL;
        }
        ListNode(int k, int v, ListNode *n, ListNode *p)
        {
            key = k, val = v;
            next = n, prev = p;
        }
    };

    int n;
    ListNode *head, *tail;
    unordered_map<int, ListNode *> u;
    LRUCache(int capacity)
    {
        n = capacity;
        head = tail = NULL;
    }

    int get(int key)
    {
        if (u.find(key) == u.end())
            return -1;
        int val = u[key]->val;
        ListNode *k = u[key];
        u[key] = insertNodeAtTail(key, val);
        deleteNode(k);
        return val;
    }

    int deleteNodeFromHead()
    {
        ListNode *cur = head;
        head = head->next;
        head->prev = NULL;
        int k = cur->key;
        delete cur;
        return k;
    }

    void deleteNode(ListNode *node)
    {
        if (node == head)
        {
            deleteNodeFromHead();
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }

    ListNode *insertNodeAtTail(int key, int value)
    {
        ListNode *cur = new ListNode(key, value, NULL, tail);
        if (head == NULL)
        {
            head = tail = cur;
        }
        else
        {
            tail->next = cur;
            tail = cur;
        }
        return cur;
    }

    void put(int key, int value)
    {
        if (u.find(key) != u.end())
        {
            if (u[key] == tail)
            {
                u[key]->val = value;
                return;
            }
            else
            {
                deleteNode(u[key]);
            }
        }
        u[key] = insertNodeAtTail(key, value);
        if (u.size() > n)
        {
            int k = deleteNodeFromHead();
            u.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */