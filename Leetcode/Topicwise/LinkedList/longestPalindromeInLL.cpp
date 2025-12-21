#include <bits/stdc++.h>
using namespace std;

class LinkedListNode
{
public:
    int data;
    LinkedListNode *next;

    LinkedListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    LinkedListNode *head;

    LinkedList()
    {
        head = NULL;
    }

    void insertAtHead(int data)
    {
        LinkedListNode *newNode = new LinkedListNode(data);
        newNode->next = head;
        head = newNode;
    }

    void printList()
    {
        LinkedListNode *cur = head;

        cout << "Data in list:\n";
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    int commonNodes(LinkedListNode *a, LinkedListNode *b)
    {
        int curLen = 0;
        LinkedListNode *cur1 = a, *cur2 = b;
        while (cur1 != NULL and cur2 != NULL and cur1->data == cur2->data)
            curLen += 1, cur1 = cur1->next, cur2 = cur2->next;

        return curLen;
    }

    int longestPalindrome()
    {
        int ans = (head == NULL) ? 0 : 1;

        LinkedListNode *reversedList = NULL;

        LinkedListNode *cur = head;
        while (cur != NULL)
        {
            LinkedListNode *next = cur->next;
            cur->next = reversedList;
            reversedList = cur;

            // Find the longest matching portion of reversedList and next.
            ans = max(ans, 2 * commonNodes(reversedList, next));

            // Find the longest matching portion of reversedList and next->next (i.e. by taking next as center).
            if (next != NULL)
                ans = max(ans, 2 * commonNodes(reversedList, next->next) + 1);

            // Finally update cur to next.
            cur = next;
        }
        return ans;
    }
};

int main()
{
    LinkedList l;
    l.insertAtHead(24);
    l.insertAtHead(12);
    l.insertAtHead(2);
    l.insertAtHead(3);
    l.insertAtHead(7);
    l.insertAtHead(3);
    l.insertAtHead(2);

    l.printList();

    cout << l.longestPalindrome() << endl;
    return 0;
}