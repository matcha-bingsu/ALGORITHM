#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case, num, ans;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        ans = 0;

        cin >> num;
        for (int st = 1; st <= num; st++)
        {
            int tmp = st;
            int ed = st + 1;
            while (tmp < num)
                tmp += ed++;
            if (tmp == num)
                ans++;
        }
        cout << '#' << cur_case << ' ' << ans << '\n';
    }
    return (0);
}