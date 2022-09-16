#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
public:
    MapNode<V> **buckets; // 1st * for list & 2nd for array
    int size;
    int numBuckets;

public:
    ourmap()
    {
        size = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return size;
    }

private:
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i++)
        {
            hashcode += key[i] * currentCoeff;
            hashcode %= numBuckets;
            currentCoeff *= 37; // any prime number
            currentCoeff %= numBuckets;
        }
        return hashcode % numBuckets;
    }

public:
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value; // if key already found replace its value
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head; // if not add the node
        buckets[bucketIndex] = node;
        size++;
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *head = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)

                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
};