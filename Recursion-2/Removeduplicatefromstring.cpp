#include <iostream>
using namespace std;

void removeDuplicates(string str, string ans, int i, int map[26])
{
    if (i == str.size())
    {
        cout << "ans : " << ans << endl;
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if (map[mapIdx] == true)
    {
        removeDuplicates(str, ans, i + 1, map);
    }
    else
    {
        map[mapIdx] = true;
        removeDuplicates(str, ans + str[i], i + 1, map);
    }
}

int main()
{
    string str = "appnnacollege";
    string ans = "";
    int map[26] = {false};

    removeDuplicates(str, ans, 0, map);
    return 0;
}