#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int bestBuy[10000];
    bestBuy[0] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(arr[i - 1], bestBuy[i - 1]);
    }
    int CProfit;
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        CProfit = arr[i] - bestBuy[i];
        maxProfit = max(CProfit, maxProfit);
    }
    cout << maxProfit;
}