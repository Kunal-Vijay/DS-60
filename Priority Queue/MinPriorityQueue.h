#include <vector>
using namespace std;
class MinPriorityQueue
{
    vector<int> pq;

public:
    MinPriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (pq.size() != 0)
            return pq[0];
        return 0; // priority queue is empty
    }

    void insert(int element)
    {
        pq.push_back(element);

        // up-heapify
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int minElement = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down-heapify
        int parentIndex = 0;
        int childIndex1 = (2 * parentIndex) + 1;
        int childIndex2 = (2 * parentIndex) + 2;
        while (childIndex1 < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[childIndex1] < pq[minIndex])
            {
                minIndex = childIndex1;
            }
            if (childIndex2 < pq.size() && pq[childIndex2] < pq[minIndex])
            {
                minIndex = childIndex2;
            }
            if (pq[minIndex] == pq[parentIndex])
            {
                break;
            }
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            childIndex1 = (2 * parentIndex) + 1;
            childIndex2 = (2 * parentIndex) + 2;
        }
        return minElement;
    }
};
