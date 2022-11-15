#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    int cur = 0;
    vector<int> v;
    int dp[100000];
    int arr[100000];

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        if (cur < K)
        {
            if (i == 0)
                dp[i] = arr[i];
            else
                dp[i] = dp[i - 1] + arr[i];
            cur++;
            if (cur == K)
                v.push_back(dp[i]);
        }
        else
        {
            dp[i] = (dp[i - 1] - arr[i - 1 - (K - 1)]) + arr[i];
            v.push_back(dp[i]);
        }
    }

    cout << *max_element(v.begin(), v.end());
    return (0);
}