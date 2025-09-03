#include <iostream>
using namespace std;

int tilingProblem(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // vetical
    int ans1 = tilingProblem(n - 1); // 2xn-1

    // hirzontal
    int ans2 = tilingProblem(n - 2); // 2xn-2

    return ans1 + ans2;
}

int main()
{
    int n = 3;
    cout << tilingProblem(4) << endl;
    return 0;
}