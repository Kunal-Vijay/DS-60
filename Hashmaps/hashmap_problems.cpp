#include <bits/stdc++.h>
using namespace std;

// Problem 1 - Remove Duplicates
vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

// Problem 2 - Maximum Frequency Number
int maxFrequency(int *a, int size)
{
    unordered_map<int, int> numcount;
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        numcount[a[i]]++;
        if (numcount.count(a[i]) > numcount.count(max))
        {
            max = a[i];
        }
    }
    return max;
}

// Problem 3 - Print array intersection
void arrayIntersection(int *a1, int size1, int *a2, int size2)
{
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    for (int i = 0; i < size1; i++)
    {
        map1[a1[i]]++;
    }
    for (int i = 0; i < size2; i++)
    {
        map2[a2[i]]++;
        if (map1.count(a2[i]) > 0)
        {
            cout << a2[i] << " ";
            map1[a2[i]]--;
        }
    }
}

// Problem 4 - Pair sum to 0
int pairSum0(int *a, int size)
{
    unordered_map<int, int> map1;
    int pairCount = 0;
    for (int i = 0; i < size; i++)
    {
        map1[a[i]]++;
        if (map1.count(-a[i]) > 0)
        {
            pairCount++;
        }
    }
    return pairCount;
}

// Problem 5 - Longest consecutive sequence
vector<int> LongestConsecutive(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> map1;
    for (int i = 0; i < size; i++)
    {
        map1[a[i]] = true;
    }
    int maxLength = 0;
    int start = 0;
    int length = 0;
    int SeqStart;
    int SeqEnd;
    for (int i = 0; i < size; i++)
    {
        if (map1.count(a[i]) > 0 && map1[a[i]] == true)
        {

            start = a[i];
            length++;
            map1[a[i]] = false;
            int k = a[i] - 1;
            while (map1.count(k) > 0 && map1[k] == true)
            {
                start = k;
                length++;
                map1[k] = false;
                k--;
            }
            int j = a[i] + 1;
            while (map1[j] == true)
            {
                length++;
                map1[j] = false;
                j++;
            }
            if (length > maxLength)
            {
                maxLength = length;
                SeqStart = start;
                SeqEnd = start + maxLength - 1;
            }
            length = 0;
        }
    }
    if (SeqStart)
        output.push_back(SeqStart);
    if (SeqEnd)
        output.push_back(SeqEnd);
    return output;
}

// Problem 6 - Pair with difference k
int pairDifferenceK(int *a, int size, int k)
{
    unordered_map<int, int> map1;
    int pairCount = 0;
    for (int i = 0; i < size; i++)
    {
        map1[a[i]]++;
        if (map1.count(k - a[i]) > 0)
        {
            pairCount += map1[k - a[i]];
        }
        if (map1.count(a[i] - k) > 0)
        {
            pairCount += map1[a[i] - k];
        }
        if (k == 0)
        {
            pairCount--;     // self pair 
        }
    }
    return pairCount;
}
int main()
{
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    // vector<int> output = removeDuplicates(a, size);
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << endl;
    // }

    // cout << maxFrequency(a, size) << endl;

    // int size2;
    // cin >> size2;
    // int a2[size2];
    // for (int i = 0; i < size2; i++)
    // {
    //     cin >> a2[i];
    // }
    // arrayIntersection(a,size,a2,size2);

    // cout << pairSum0(a, size) << endl;

    // vector<int> output = LongestConsecutive(a, size);
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << " ";
    // }
    int k;
    cin >> k;
    cout << pairDifferenceK(a, size, k) << endl;
    return 0;
}