// https://www.acmicpc.net/problem/1149 (RGB거리)
#include <bits/stdc++.h>
using namespace std;
int n;
int r[1002];
int g[1002];
int b[1002];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        cin >> g[i];
        cin >> b[i];
    }

    int get[n + 2][3];
    get[1][0] = r[1];
    get[1][1] = g[1];
    get[1][2] = b[1];

    for (int i = 2; i <= n; i++)
    {
        get[i][0] = min(get[i - 1][1], get[i - 1][2]) + r[i];
        get[i][1] = min(get[i - 1][0], get[i - 1][2]) + g[i];
        get[i][2] = min(get[i - 1][0], get[i - 1][1]) + b[i];
    }

    cout << min(min(get[n][0], get[n][1]), get[n][2]);
    return (0);
}