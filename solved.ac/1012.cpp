// https://www.acmicpc.net/problem/1012 (유기농 배추)
#include <bits/stdc++.h>
using namespace std;
int tot_x, tot_y, cabbage;
int board[50][50];
queue<pair<int, int> >  q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void    bfs()
{
    int cnt = 0;
    for (int i = 0; i < tot_x; i++)
    {
        for (int j = 0; j < tot_y; j++)
        {
            if (board[i][j] == 1)
            {
                cnt++;
                board[i][j] = 4;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int>  cur = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int x = cur.first + dx[d];
                        int y = cur.second + dy[d];
                        if (x < 0 || y < 0 || x >= tot_x || y >= tot_y || board[x][y] != 1)
                            continue;
                        q.push({x,y});
                        board[x][y] = 4;
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        cin >> tot_x >> tot_y >> cabbage;

        fill(board[0], board[49], 0);
        while (cabbage--)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }
        bfs();
    }
    return (0);
}