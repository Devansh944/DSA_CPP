#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span
void StockSpan(const vector<int>& stock, vector<int>& span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++)
    {
        int currPrice = stock[i];

        // Pop smaller or equal prices
        while (!s.empty() && currPrice >= stock[s.top()])
        {
            s.pop();
        }

        // If stack is empty, all previous prices are smaller
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - s.top();
        }

        // Push this day's index
        s.push(i);
    }
}

int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0);

    StockSpan(stock, span);

    cout << "Stock Prices: ";
    for (int price : stock) cout << price << " ";
    cout << endl;

    cout << "Stock Span:   ";
    for (int s : span) cout << s << " ";
    cout << endl;

    return 0;
}
