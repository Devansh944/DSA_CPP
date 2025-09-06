#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubsets(string str, string subset)
{
    if (str.size() == 0)
    {
        cout << subset << "\n";
        return;
    }
    char ch = str[0];

    // yes
    printSubsets(str.substr(1, str.size() - 1), subset + ch);
    // No
    printSubsets(str.substr(1, str.size() - 1), subset);
}

// void printArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main()
{
    string str = "abc";
    string subset = "";
    printSubsets(str, subset);
    return 0;
}