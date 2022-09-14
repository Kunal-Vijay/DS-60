#include <bits/stdc++.h>
using namespace std;

void traverseMap(unordered_map<string, int> m)
{
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << "Key : " << it->first << " -- Value : " << it->second << endl;
        it++;
    }
}

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

    // traversal in unordered map
    unordered_map<string, int> map2;
    map2["abc1"] = 1;
    map2["abc2"] = 2;
    map2["abc3"] = 3;
    map2["abc4"] = 4;
    map2["abc5"] = 5;
    map2["abc6"] = 6;

    traverseMap(map2);

    // find
    unordered_map<string, int>::iterator it2 = map2.find("abc1");
    map2.erase(it2);
    cout << "after deletion" << endl;
    traverseMap(map2);

    return 0;
}