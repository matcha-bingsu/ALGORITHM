#include <bits/stdc++.h>
using namespace std;

pair<int, int>  get_coordinate(int number)
{
    pair<int, int>  ans;
    int total = 0;
    int cnt = 1;

    while (1)
    {
        total += cnt;
        if (number - total <= cnt)
            break;
        cnt++;
    }
    if (number - total == 0)
    {
        ans = {cnt, 1};
        return (ans);
    }
    else
    {
        ans = {number - total, cnt - (number - total) + 2};
        return (ans);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int c, d, number, ans;
        vector<pair<int, int>> v;

        for (int i = 0; i < 2; i++)
        {
            pair<int, int>  tmp;
            cin >> number;
            tmp = get_coordinate(number);
            v.push_back(tmp);
        }
        c = v[0].first + v[1].first;
        d = v[0].second + v[1].second;
        ans = (((c + d - 2) * (c + d - 1)) / 2) + c;
        cout << '#' << cur_case << ' ' << ans << '\n';
    }
    return (0);
}