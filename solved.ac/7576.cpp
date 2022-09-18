#include <bits/stdc++.h>
using namespace std;
int n, m, flag;
int input[1001][1001];
int visited[1001][1001];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>>   q;

void    start()
{
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            if (input[x][y] != 0 || visited[x][y] != 0)
                continue;
            q.push({x, y});
            if (visited[cur.first][cur.second] == -1)
                visited[x][y] = 1;
            else
                visited[x][y] = visited[cur.first][cur.second] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && input[i][j] == 0)
            {
                cout << -1;
                return ;
            }
        }
    }
   cout << *max_element(visited[0], visited[n]);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (input[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = -1;
            }
            if (input[i][j] == 0)
                flag++;
        }
    }
    if (flag)
        start();
    else
        cout << 0;
    return (0);
}