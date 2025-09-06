#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutation(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << "\n";
        return;
    }
    int n = str.size();
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        permutation(str.substr(0, i) + str.substr(i + 1, n - i - 1), ans + ch);
    }
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
    string ans = "";
    permutation(str, ans);
    return 0;
}