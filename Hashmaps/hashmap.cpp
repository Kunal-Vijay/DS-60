#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;

    // insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // find and access
    cout << ourMap["abc"] << endl;    // output = 1
    cout << ourMap.at("def") << endl; // output = 2

    cout << ourMap["ghi"] << endl;    // output = 0 [insert default 0 value in ghi]
    cout << ourMap.at("ghi") << endl; // error - key not found

    // check presence
    if (ourMap.count("dlf") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }

    // size of map
    cout << "size:" << ourMap.size() << endl;

    // erase
    ourMap.erase("ghi");
    cout << "size:" << ourMap.size() << endl;

    return 0;
}