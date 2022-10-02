#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int     t;
    string  alpha = "abcdefghijklmnopqrstuvwxyz";
    string  str;

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int j = 0;
        cin >> str;
        while (str[j] != '\0' && str[j] == alpha[j])
            j++;
        cout << '#' << i << ' ' << j << '\n';
    }
    return (0);
}