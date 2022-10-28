#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case = 10;
    int cur_case;
    string  target, str;

    while (test_case--)
    {
        int cnt = 0;
        cin >> cur_case;
        cin >> target >> str;

        for (int i = 0; i < str.size(); i++)
        {
            int j = 0;
            while (i + j < str.size() && j < target.size() && str[i + j] == target[j])
                j++;
            if (j == target.size())
                cnt++;
        }
        cout << '#' << cur_case << ' ' << cnt << '\n';
    }
    return (0);
}