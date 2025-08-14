#include <iostream>
using namespace std;

void Selectionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        {
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
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}