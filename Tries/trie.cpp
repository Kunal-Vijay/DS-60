#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    TrieNode *root;

   
    void insertHelper(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            // absent -- create new
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertHelper(child, word.substr(1));
    }

    bool searchHelper(TrieNode *root, string word)
    {
         // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }else{
            return false;
        }
        // Recursive call
        return searchHelper(child, word.substr(1));
    }

    void removeHelper(TrieNode *root, string word)
    {
         // base case
        if (word.length() == 0)
        {
            root->isTerminal=false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }else{
            return;
        }
        // Recursive call
        removeHelper(child, word.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insert(string word)
    {
        insertHelper(root, word);
    }
    bool search(string word)
    {
        return searchHelper(root, word);
    }
    void remove(string word){
        removeHelper(root,word);
    }
};

int main()
{

    Trie *t = new Trie;
    t->insert("ARM");
    t->insert("DO");
    t->insert("TIMER");
    cout<<t->search("ARM")<<endl;
    cout<<t->search("AR")<<endl;
    cout<<t->search("TIME")<<endl;
    cout<<t->search("TIMER")<<endl;
    t->remove("TIMER");
    cout<<t->search("TIMER")<<endl;

    return 0;
}