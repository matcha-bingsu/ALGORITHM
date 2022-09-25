#include <bits/stdc++.h>
using namespace std;
int n, c, num;
map<int, int>   m, order;

bool    cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return (order[a.first] < order[b.first]);
    return (a.second > b.second);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        m[num]++;
        if (order[num] == 0)
            order[num] = i + 1; 
    }
    vector<pair<int, int>> vec(m.begin(), m.end()); 
    sort(vec.begin(), vec.end(), cmp);
    for (auto a : vec)
        for (int i = 0; i < a.second; i++)
            cout << a.first << ' ';
    return (0);
}