#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case, num, every_sec, bbang, mx, sec, flag;
    int dp[11111];
    int people[11111];
    string  ans;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        flag = 0;
        mx = 0;
        fill(dp, dp + 11111, 0);
        fill(people, people + 11111, 0);

        cin >> num >> every_sec >> bbang;
        while (num--)
        {
            cin >> sec;
            people[sec]++;
            if (sec > mx)
                mx = sec;
        }
        for (int i = 1; i <= mx; i++)
        {
            if (i % every_sec == 0)
                dp[i] = dp[i - 1] + bbang - people[i];
            else
                dp[i] = dp[i - 1] - people[i];
            if (dp[i] < 0)
            {
                flag++;
                break;
            }
        }
        if (flag || people[0])
            ans = "Impossible";
        else
            ans = "Possible";
        cout << '#' << cur_case << ' ' << ans << '\n';
    }
    return (0);
}