#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int arr[n];
    int dp[n];
    fill(dp, dp + n, 1);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp, dp + n);
    return (0);
}