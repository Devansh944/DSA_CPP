#include <iostream>
using namespace std;

void bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}
void selection(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertion(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && curr < arr[prev])
        {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }
        swap(arr[prev + 1], curr);
    }
}

void counting(int arr[], int n)
{
    int freq[1000] = {0};
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        minVal = min(arr[i], minVal);
        maxVal = max(arr[i], maxVal);
    }
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = minVal, j = 0; i < maxVal; i++)
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
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}