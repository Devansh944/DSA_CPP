#include <iostream>
using namespace std;

void counting(int arr[], int n)
{

    int freq[1000] = {0};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = minVal, j = 0; i <= maxVal; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }
}

int main()
{
    int arr[] = {5, 1, 2, 3, 4, 4, 4, 1, 1, 1, 6, 6, 6, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}