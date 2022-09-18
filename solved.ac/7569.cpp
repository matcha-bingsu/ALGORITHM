#include <bits/stdc++.h>
using namespace std;
int x, y, h, num, days;
int arr[100][100][100];
int chck[100][100][100];
int dx[6] = {0, 0, 0, -1, 0, 1};
int dy[6] = {0, 0, -1, 0, 1, 0};
queue<tuple<int, int, int> >  q;

void    check()
{
    for (int height = 0; height < h; height++)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (chck[height][i][j] == 0 && arr[height][i][j] == 0)
                {
                    cout << -1;
                    return ;
                }
                days = max(days, chck[height][i][j]);
            }
        }
    }
    cout << days;
}

void    bfs()
{
    while (!q.empty())
    {
        int height, ox, oy;
        tie(height, ox, oy) = q.front();
        q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int floor;
            if (dir == 0)
                floor = height - 1;
            else if (dir == 1)
                floor = height + 1;
            else
                floor = height;
            int nx = ox + dx[dir];
            int ny = oy + dy[dir];
            if (floor < 0 || nx < 0 || ny < 0 || nx >= x || ny >= y || floor >= h)
                continue;
            if (arr[floor][nx][ny] != 0 || chck[floor][nx][ny] != 0)
                continue;
            q.push({floor, nx, ny});
            chck[floor][nx][ny] = chck[height][ox][oy] + 1;
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int init_chck = 1;
    cin >> y >> x >> h;
    for (int height = 0; height < h; height++)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> num;
                arr[height][i][j] = num;
                if (num == 1)
                    q.push({height, i, j});
                init_chck *= num;
            }
        }
    }
    if (init_chck == 0)
    {
        bfs();
        check();
    }
    else
        cout << 0;
    return (0);
}