#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
        if (cnt == k)
        {
            cout << i;
            return (0);
        }
    }
    cout << 0;
    return (0);
}