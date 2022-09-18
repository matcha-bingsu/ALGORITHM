// https://www.acmicpc.net/problem/1003 (파보나치 함수)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--)
    {
        int                         num;
        vector<pair<int, int > >    v;

        cin >> num;
        v.push_back({1, 0});
        v.push_back({0, 1});
        for (int i = 2; i <= num; i++)
            v.push_back({v[i - 1].first + v[i - 2].first, v[i - 1].second + v[i - 2].second});
        cout << v[num].first << ' ' << v[num].second << '\n';
    }
    return (0);
}