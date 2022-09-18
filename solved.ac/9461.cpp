#include <bits/stdc++.h>
using namespace std;
int t, num;
long dp[101];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 100; i++)
        dp[i] = dp[i - 3] + dp[i - 2];

    while (t--)
    {
        cin >> num;
        cout << dp[num] << '\n';
    }
    return (0);
}