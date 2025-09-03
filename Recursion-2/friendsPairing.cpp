#include <iostream>
using namespace std;

int friendsPairing(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }

    // //single
    // friendsPairing(n-1);
    // //pair
    // (n-1)*friendsPairing(n-2);

    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{
    cout << friendsPairing(3) << endl;
    return 0;
}