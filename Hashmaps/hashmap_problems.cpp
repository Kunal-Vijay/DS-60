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
    // return 0;

    int size2;
    cin >> size2;
    int a2[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> a2[i];
    }
    arrayIntersection(a,size,a2,size2);
}