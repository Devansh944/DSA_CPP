#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{
    vector<T> vec;

public:
    void push(T val)
    {
        vec.push_back(val);
    }
    void pop()
    {
        if (isEmply())
        {
            return;
        }
        vec.pop_back();
    }
    T top()
    {
        // if (isEmply())
        // {
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }
    bool isEmply()
    {
        return vec.size() == 0;
    }
};

int main()
{
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmply())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}