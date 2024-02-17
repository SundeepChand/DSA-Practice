#include <bits/stdc++.h>
using namespace std;

template <class T>
class PriorityQueue
{
private:
    vector<T> arr;
    int curSize;

public:
    PriorityQueue()
    {
        curSize = 0;
    }

    void swim(int pos)
    {
        while (pos > 0)
        {
            int parent = (pos - 1) / 2;
            if (arr[parent] < arr[pos])
                swap(arr[parent], arr[pos]);
            else
                break;
            pos = parent;
        }
    }

    void push(T val)
    {
        curSize++;
        int pos = curSize - 1;
        if (curSize > arr.size())
            arr.push_back(val);
        else
            arr[pos] = val;

        swim(pos);
    }

    void sink(int pos, int end)
    {
        while (pos <= end)
        {
            int left = 2 * pos + 1, right = 2 * pos + 2;
            if (left > end)
                break;
            else if (right > end)
            {
                if (arr[pos] < arr[left])
                {
                    swap(arr[pos], arr[left]);
                    pos = left;
                }
                else
                    break;
            }
            else if (arr[pos] < arr[left] or arr[pos] < arr[right])
            {
                if (arr[left] > arr[right])
                {
                    swap(arr[left], arr[pos]);
                    pos = left;
                }
                else
                {
                    swap(arr[right], arr[pos]);
                    pos = right;
                }
            }
            else
                break;
        }
    }

    void pop()
    {
        swap(arr[0], arr[curSize - 1]);
        curSize--;
        int pos = curSize - 1;
        sink(0, pos);
    }

    T top()
    {
        if (curSize <= 0)
            return INT_MIN;
        return arr[0];
    }

    bool empty()
    {
        return curSize == 0;
    }

    void printArr()
    {
        cout << "Arr: ";
        for (int i = 0; i < curSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    PriorityQueue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(1);

    cout << pq.top() << endl;
    pq.pop();

    pq.push(5);
    pq.push(3);

    // pq.printArr();

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
        // pq.printArr();
        // break;
    }

    return 0;
}