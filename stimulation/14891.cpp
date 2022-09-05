// https://www.acmicpc.net/problem/14891 (톱니바퀴)
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string                  wheel[4];
queue<pair<int, int> >   rot;
int                     t, num, dir, ans;

void    set_down()
{
    int d = dir;
    for (int i = num - 1; i > 0; i--)
    {
        if (wheel[i][6] != wheel[i - 1][2])
        {
            d *= -1;
            rot.push({i - 1, d});
        }
        else
            break;
    }
}

void    set_up()
{
    int d = dir;
    for (int i = num - 1; i < 3; i++)
    {
        if (wheel[i][2] != wheel[i + 1][6])
        {
            d *= -1;
            rot.push({i + 1, d});
        }
        else
            break;
    }
}

void    rotate()
{
    while (!rot.empty())
    {
        char    tmp;
        pair<int, int>  cur = rot.front();
        if (cur.Y == -1)
        {
            tmp = wheel[cur.X][0];
            for (int i = 0; i < 7; i++)
                wheel[cur.X][i] = wheel[cur.X][i + 1];
            wheel[cur.X][5] = tmp;
        }
        else
        {
            tmp = wheel[cur.X][5];
            for (int i = 7; i > 0; i--)
                wheel[cur.X][i] = wheel[cur.X][i - 1];
            wheel[cur.X][0] = tmp;
        }
        rot.pop();
    }
}

void    get_answer()
{
    if (wheel[0][0] == '1')
        ans += 1;
    if (wheel[1][0] == '1')
        ans += 2;
    if (wheel[2][0] == '1')
        ans += 4;
    if (wheel[3][0] == '1')
        ans += 8;
    cout << ans;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 4; i++)
        cin >> wheel[i];
    
    cin >> t;
    while (t--)
    {
        cin >> num >> dir;
        
        rot.push({num - 1, dir});
        set_down();
        set_up();
        rotate();
    }
    get_answer();
    return (0);
}