#include <bits/stdc++.h>
using namespace std;
int height, row, ans, x, y, z;;
vector<tuple<int, int, int> >  v; 
int given[500];

void    init(int num)
{
    int i = 1;
    int mx = 0;
    int same = 0;
    int mx_idx = 0;
    while (num + i != row && given[num] >= given[num + i])
    {
        if (given[num] == given[num + i])
            same++;
        mx = max(mx, given[num + i]);
        i++;
    }
    if (num + i != row)
        v.push_back({given[num], 0, given[num + i]});
    else if (same)
        v.push_back({given[num], 0, given[num]});
    else
        v.push_back({given[num], 0, mx});
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> height >> row;
    for (int i = 0; i < row; i++)
        cin >> given[i];
    init(0);

    for (int i = 1; i < row; i++)
    {
        int cnt = 0; 
        tie(x, y, z) = v[i - 1];
        if (z == given[i])
            init(i);
        else if (x < given[i])
            v.push_back({given[i], 0, given[i]});
        else
            v.push_back({x, min(x - given[i], z - given[i]), z});
    }
    for (auto c : v)
    {
        tie(x, y, z) = c;
        ans += y;
    }
    cout << ans;
    return (0);
}