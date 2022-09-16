#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    dp[4] = 11;
    for (int i = 5; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    cout << dp[n];
    return (0);
}