#include <bits/stdc++.h>
using namespace std;
int E, S, M, from;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> E >> S >> M;
    if (S < 28)
        from = 0;
    else
        from = 1;
    while (1)
    {
        int standard = from * 28 + S;
        int e = standard % 15;
        int m = standard % 19;
        if (!e)
            e = 15;
        if (!m)
            m = 19;
        if (e == E && m == M)
            break;
        from++;
    }
    cout << from * 28 + S;
    return (0);
}