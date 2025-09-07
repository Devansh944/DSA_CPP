#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string reverseString(string str)
{
    string ans;
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    while (!s.empty())
    {
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(2);

    s.push(1);

    PushAtBottom(s, 4);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}