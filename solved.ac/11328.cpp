#include <bits/stdc++.h>
using namespace std;
int     tc;
int     alpha[123];
int     alpha2[123];
string  a, b;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> tc;
    while (tc--)
    {
        cin >> a;
        int flag = 0;
        fill(alpha, alpha + 123, 0);
        fill(alpha2, alpha2 + 123, 0);

        for (auto c : a)
            alpha[c]++;
        cin >> b;
        for (auto c : b)
            alpha2[c]++;

        for (int i = 97; i < 123; i++)
        {
            if (alpha[i] != alpha2[i])
            {
                flag++;
                break;
            }
        }
        if (flag)
            cout << "Impossible\n";
        else
            cout << "Possible\n";
    }
    return (0);
}