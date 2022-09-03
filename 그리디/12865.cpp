// https://www.acmicpc.net/problem/12865 (평볌한 배냥)
#include <bits/stdc++.h>
using namespace std;

int dp[102][100002];
int v[101];
int w[101];
int n, k;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    cout << dp[n][k];
    return (0);
}