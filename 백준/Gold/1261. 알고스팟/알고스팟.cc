#include <bits/stdc++.h>
using namespace std;
int     n, m;

int bfs(int (*arr)[100])
{
    int ans = 987654321;
    int chck[100][100];
    int x_dir[4] = {0, -1, 0, 1};
    int y_dir[4] = {-1, 0, 1, 0};
    queue<tuple<int, int, int>>   q;

    chck[0][0] = -1;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        int f, s, t;
        tie(f, s, t) = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int new_x = f + x_dir[dir];
            int new_y = s + y_dir[dir];
            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
                continue;
            if (chck[new_x][new_y] == -1)
                continue;
            if (arr[new_x][new_y] && chck[new_x][new_y] != 0 && t + 1 >= chck[new_x][new_y])
                continue;
            if (!arr[new_x][new_y] && chck[new_x][new_y] != 0 && t >= chck[new_x][new_y])
                continue;
            if (arr[new_x][new_y])
            {
                q.push({new_x, new_y, t + 1});
                chck[new_x][new_y] = t + 1;
            }
            else
            {
                q.push({new_x, new_y, t});
                if (!t)
                    chck[new_x][new_y] = -1;
                else
                    chck[new_x][new_y] = t;
            }
        }
    }
    if (chck[n - 1][m - 1] == -1)
        return (0);
    else
        return (chck[n - 1][m - 1]);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> m >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j] = s[j] - '0';
    }
    cout << bfs(arr);
    return (0);
}