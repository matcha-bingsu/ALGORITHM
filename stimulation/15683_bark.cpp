// https://www.acmicpc.net/problem/15683 [감시]
#include <bits/stdc++.h>

using namespace std;
int n, m, mn;
int board1[10][10];
int board2[10][10];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<pair<int,int> >  cctv;

void    color(int x, int y, int dir)
{
    dir %= 4;
    x += dx[dir];
    y += dy[dir];
    if (x < 0 || y < 0 || x >= n || y >= m || board2[x][y] == 6)
        return ;
    if (!board2[x][y])
        board2[x][y] = 35;
    color(x, y, dir);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});
            if (!board1[i][j])
                mn++;
        }
    }
  
    for (int i = 0; i < (1 << (2 * cctv.size())); i++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        int tmp = i;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = tmp % 4;
            tmp /= 4;
            int x, y;
            tie(x, y) = cctv[i];
            if (board1[x][y] == 1)
            {
                color(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                color(x, y, dir);
                color(x, y, dir + 2);
            }
            else if (board1[x][y] == 3)
            {
              color(x, y, dir);
              color(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            { 
              color(x, y, dir);
              color(x, y, dir + 1);
              color(x, y, dir + 2);
            }
            else
            {
              color(x, y, dir);
              color(x, y, dir + 1);
              color(x, y, dir + 2);
              color(x, y, dir + 3);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!board2[i][j])
                    cnt++;
        mn = min(mn, cnt);
    }
    cout << mn;
}