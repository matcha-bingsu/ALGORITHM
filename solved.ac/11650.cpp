// https://www.acmicpc.net/problem/11650 (좌표 정렬하기)
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;  

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, n1, n2;
    cin >> n;
    while (n--)
    {
        cin >> n1 >> n2;
        v.push_back({n1, n2});
    }
    sort (v.begin(), v.end());
    for (auto c : v)
        cout << c.first << ' ' << c.second << '\n';
    return (0);
}