#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string  str[n];
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0; i < str[0].size(); i++)
    {
        char standard = str[0][i];
        int flag = 0;
        for (int j = 1; j < n; j++)
        {
            if (str[j][i] != standard)
            {
                flag++;
                cout << '?';
                break;
            }
        }
        if (!flag)
            cout << standard;
    }
    return (0);
}