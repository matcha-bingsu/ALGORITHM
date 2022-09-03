// https://www.acmicpc.net/problem/1931 (회의실 배정)
#include <bits/stdc++.h>
using namespace std;
int mx;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    pair<int, int>  p[n + 1];
    for (int i = 0; i < n; i++)
        cin >> p[i].second >> p[i].first;
    sort(p, p + n);

    int cnt = 1;
    int cur = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].second >= p[cur].first)
        {
            cnt++;
            cur = i;
        }
    }
    cout << cnt;
    return (0);
}