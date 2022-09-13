#include <bits/stdc++.h>
using namespace std;
int n;
int day[16];
int num[16];
int ans[16];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> day[i];
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (day[j] + (j - 1) < i)
                ans[i] = max(ans[i], ans[j]);
        if (i + day[i] - 1 < n)
            ans[i] += num[i];
    }
    cout << *max_element(ans, ans + n);
}