#include <bits/stdc++.h>
using namespace std;
int origin[1025][1025];
int dp[1025][1025];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin[i + 1][j + 1];
            dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + origin[i + 1][j + 1];
        }
    }
    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (dp[x2][y2] - dp[x1 -1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) << '\n';
    }
    return (0);
}