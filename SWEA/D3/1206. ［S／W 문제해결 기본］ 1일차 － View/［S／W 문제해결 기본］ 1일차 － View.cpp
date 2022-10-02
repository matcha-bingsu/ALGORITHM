#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, number;
    for (int i = 1; i <= 10; i++)
    {
        cin >> t;
        int towers[t];
        for (int i = 0; i < t; i++)
            cin >> towers[i];

        int total = 0;
        for (int i = 2; i < t - 2; i++)
        {
            int tmp = 0;
            if (towers[i] > max(towers[i - 1], towers[i - 2]))
                tmp += towers[i] - max(towers[i - 1], towers[i - 2]);
            if (towers[i] > max(towers[i + 1], towers[i + 2]))
                total += min(tmp, towers[i] - max(towers[i + 1], towers[i + 2]));
        }

        cout << '#' << i << ' ' << total << '\n';
    }
    return (0);
}