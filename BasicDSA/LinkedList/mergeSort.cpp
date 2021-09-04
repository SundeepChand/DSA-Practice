#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;

        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};

template <class T>
class LinkedList
{
    private:
        Node<T> *head;

    public:
        LinkedList(): head(NULL) {}

        void insertBeg(T data)
        {
            Node<T> *newNode = new Node<T>(data);
            newNode->next = head;
            head = newNode;
        }

        void printList()
        {
            Node<T> *cur = head;
            while (cur != NULL)
            {
                cout<<cur->data<<" -> ";
                cur = cur->next;
            }
            cout<<"NULL"<<endl;
        }

        Node<T>* getMid(Node<T> *head)
        {
            Node<T> *slow = head;
            Node<T> *fast = head->next;
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node<T>* merge(Node<T>* a, Node<T>* b)
        {
            if (a == NULL)
                return b;
            if (b == NULL)
                return a;

            if (a->data < b->data)
            {
                a->next = merge(a->next, b);
                return a;
            }
            else
            {
                b->next = merge(a, b->next);
                return b;
            }
        }

        Node<T>* mergeSortUtil(Node<T> *head)
        {
            // Base case
            if (head == NULL || head->next == NULL)
                return head;

            // Recursive case
            Node<T> *mid = getMid(head);
            Node<T> *a = head;
            Node<T> *b = mid->next;
            mid->next = NULL;

            // Recursive case
            a = mergeSortUtil(a);
            b = mergeSortUtil(b);

            return merge(a, b);
        }

        void mergeSort()
        {
            head = mergeSortUtil(head);
        }
};

int main()
{
    LinkedList<int> l;
    l.insertBeg(4);
    l.insertBeg(5);
    l.insertBeg(1);
    l.insertBeg(2);
    l.insertBeg(3);

    l.printList();

    l.mergeSort();
    l.printList();

    return 0;
}