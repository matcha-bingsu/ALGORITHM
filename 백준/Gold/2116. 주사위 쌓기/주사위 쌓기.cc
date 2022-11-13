#include <bits/stdc++.h>
using namespace std;

void    init(int (*dice)[6], int many)
{   
    for (int i = 0; i < many; i++)
    {
        for (int j = 0; j < 6; j++)
            cin >> dice[i][j];
    }
}

int get_idx(int target, int *dice)
{
    for (int i = 0; i < 6; i++)
    {
        if (dice[i] == target)
            return (i);
    }
    return (0);
}

int correspond_idx(int target_idx)
{
    if (target_idx == 0)
        return (5);
    else if (target_idx == 1)
        return (3);
    else if (target_idx == 2)
        return (4);
    else if (target_idx == 3)
        return (1);
    else if (target_idx == 4)
        return (2);
    else
        return (0);
}

int get_max(int n1, int n2)
{
    int ans;

    for (int i = 1; i <= 6; i++)
        if(i != n1 && i != n2)
            ans = i;
    return (ans);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int many;
    int mx = 0;

    cin >> many;
    int dice[many][6];

    init(dice, many);

    for (int top = 1; top <= 6; top++)
    {
        int total = 0;
        int top_idx = get_idx(top, dice[0]);
        int bottom = dice[0][correspond_idx(top_idx)];
        total += get_max(top, bottom);
        bottom = top;
        for (int j = 1; j < many; j++)
        {
            int bottom_idx = get_idx(bottom, dice[j]);
            int top = dice[j][correspond_idx(bottom_idx)];
            total += get_max(top, bottom);
            bottom = top;
        }
        mx = max(mx, total);
    }
    cout << mx;
    return (0);
}