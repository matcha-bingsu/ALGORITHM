#include <bits/stdc++.h>
using namespace std;
int number[1001];

int calculate(int x_idx, int y_idx)
{
    int mx = 0;
    int total = number[y_idx];

    for (int i = 0; i < y_idx; i++)
    {
        mx = max (mx, number[i]);
        total += mx;
    }

    mx = 0;
    for (int i = x_idx; i > y_idx; i--)
    {
        mx = max (mx, number[i]);
        total += mx;
    }
    return (total);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, x, y, y_idx;
    int y_mx = 0;
    int x_idx = 0;

    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        number[x] = y;
        x_idx = max(x_idx, x);
        if (y > y_mx)
        {
            y_mx = y;
            y_idx = x;
        }
    }
    cout << calculate(x_idx, y_idx);
    return (0);
}