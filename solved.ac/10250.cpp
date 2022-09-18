// https://www.acmicpc.net/problem/10250
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, h, w, n;

    cin >> t;
    while (t--)
    {
        cin >> h >> w >> n;
        
        int h1, ;
        h1 = n % h;
        w1 = n / h;

        if (h1 > 0)
            w1++;
        else
            h1 = h;
        cout << h1 * 100 + w1 << '\n';
    }
    return (0);
}