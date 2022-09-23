#include <bits/stdc++.h>
using namespace std;
int mx, x, y;
int board[501][501];
bool visited[501][501];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void    last_case(int i, int j)
{
    if (i + 1 < x && j + 2 < y)
    {
        mx = max(mx, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]);
        mx = max(mx, board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]);
    }
    if (i + 2 < x && j + 1 < y)
    {
        mx = max(mx, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]);
        mx = max(mx, board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]);
    }
}

void    dfs(int xx, int yy, int t, int sum)
{
    if (t == 3)
    {
        mx = max(mx, sum);
        return ;
    }
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = xx + dx[dir];
        int ny = yy + dy[dir];
        if (nx < 0 || ny < 0 || nx >= x || ny >= y)
            continue;
        if (visited[nx][ny])
            continue;
        visited[nx][ny] = true;
        dfs(nx, ny, t + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
    visited[xx][yy] = false;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> x >> y;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> board[i][j];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 0, board[i][j]);
            visited[i][j] = false;
            last_case(i, j);
        }
    }
    cout << mx;
    return (0);
}