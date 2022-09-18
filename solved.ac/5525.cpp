#include <bits/stdc++.h>
using namespace std;
int st, ed, cnt;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    char    previous = 's';
    int     n, m;
    string  str;
    cin >> n >> m >> str;

    while (st <= ed && st <= m - (2 * n + 1) && ed <= m - 1)
    {
        if (str[ed] != previous && ed - st == 2 * n)
        {
            cnt++;
            st += 2;
            previous = str[ed];
            ed += 1;
        }
        else if (str[st] == 'I' && str[ed] != previous)
        {
            previous = str[ed];
            ed += 1;
        }
        else if (previous == str[ed])
        {
            st = ed;
            previous = str[ed];
            ed += 1;
        }
        else if (str[st] != 'I')
        {
            st++;
            previous = str[ed];
            ed++;
        }
    }
    cout << cnt;
    return (0);
}