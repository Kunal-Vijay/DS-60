#include <bits/stdc++.h>
#include <stack>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string s)
{

    stack<char> st;
    string postfix;
    int i = 0;
    while (i < s.length())
    {
        if (prec(s[i])==0)
        {
            if (s[i]=='(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    //popping the ( bracket from stack
                    st.pop();
                }
            }
            else
            {
                postfix += s[i];
            }
            i++;
        }
        else
        {
            if (st.empty() || prec(s[i]) > prec(st.top()))
            {
                st.push(s[i]);
                i++;
            }
            else
            {
                postfix += st.top();
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix = "x-y/z-k*d";
    // string infix = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(infix) << endl;
    return 0;
}