#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, d, cnt;
int area[50][50];

int correct_dir()
{
    if (d == 0 && !area[r][c - 1])
    {
        c -= 1;
        d = 3;
        return (1);
    }
    else if (d == 1 && !area[r - 1][c])
    {
        r -= 1;
        d = 0;
        return (1);
    }
    else if (d == 2 && !area[r][c + 1])
    {
        c += 1;
        d = 1;
        return (1);
    }
    else if (d == 3 && !area[r + 1][c])
    {
        r += 1;
        d = 2;
        return (1);
    }
    return (0);
}

int    dir_chck()
{
    for (int i = 0; i < 4; i++)
    {
        if (correct_dir())
            return (1);
        else
        {
            if (d == 0)
                d = 3;
            else if (d == 1)
                d = 0;
            else if (d == 2)
                d = 1;
            else if (d == 3)
                d = 2;
        }
    }
    return (0);
}

int back_chck()
{
    return ((d == 0 && area[r + 1][c] == 1) || (d == 1 && area[r][c - 1] == 1) || (d == 2 && area[r - 1][c] == 1) || (d == 3 && area[r][c + 1] == 1));
}

void    turn_back()
{
    if (d == 0)
        r += 1;
    else if (d == 1)
        c -= 1;
    else if (d == 2)
        r -= 1;
    else if (d == 3)
        c += 1;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> area[i][j];
    
    while(1)
    {
        if (!area[r][c])
        {
            area[r][c] = 100;
            cnt++;
        }

        if (dir_chck())
            continue;

        if (back_chck())
            break;

        turn_back();
    }
    cout << cnt;
}