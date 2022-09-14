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
int main()
{
    // Problem 1
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
    
    cout << maxFrequency(a, size) << endl;
    return 0;
}