#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void PushAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    PushAtBottom(s, val);
    s.push(temp);
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