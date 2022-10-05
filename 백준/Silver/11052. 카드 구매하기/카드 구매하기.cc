#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int arr[n + 1];
    int ans[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    ans[0] = 0;
    ans[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        int tmp = arr[i];
        for (int j = 1; j < i; j++)
            tmp = max(tmp, ans[j] + ans[i - j]);
        ans[i] = tmp;
    }
    cout << ans[n];
    return (0);
}