#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int si, int ei, int tar)
{
    if (si > ei)
    {
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if (arr[mid] == tar)
    {
        return mid;
    }

    if (arr[si] <= arr[mid])
    { // L1
        if (arr[si] <= tar && tar < arr[mid])
        {
            // LEFT
            return search(arr, si, mid - 1, tar);
        }
        else
        { // RIGHT
            return search(arr, mid + 1, ei, tar);
        }
    }
    else
    {
        if (arr[mid] <= tar && tar < arr[ei])
        {
            // RIGHT
            return search(arr, mid + 1, ei, tar);
        }
        else
        { // LEFT
            return search(arr, si, mid - 1, tar);
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "IDX " << search(arr, 0, n - 1, 0) << endl;
    return 0;
}