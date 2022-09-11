#include <bits/stdc++.h>
using namespace std;
int n, mx;
int arr[501][501];
int dp[501][501];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> arr[i][j];

    dp[1][1] = arr[0][0];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i - 1][j - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            mx = max(mx, dp[i][j]);
    cout << mx;
    return (0);
}