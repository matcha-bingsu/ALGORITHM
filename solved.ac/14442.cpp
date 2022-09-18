// https://www.acmicpc.net/problem/14442 (벽 부수고 이동하기2)

#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int input[1002][1002];
int visited[11][1002][1002];
queue<tuple<int, int, int>>   q;
int xd[3] = {-1, 0, 1, 0};
int yd[3] = {0, -1, 0, 1};

int solution()
{
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while (!q.empty())
    {
        int x, y, wall;
        tie(x, y, wall) = q.front();
        if (x == N - 1 && y == M - 1)
            return (visited[wall][x][y]);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + xd[i];
            int ny = y + yd[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[wall][nx][ny] != 0)
                continue;
            if (!input[nx][ny] && visited[wall][nx][ny] == 0)
            {
                visited[wall][nx][ny] = visited[wall][x][y] + 1;
                q.push({nx, ny, wall});
            }
            else if (input[nx][ny] && wall < K && visited[wall][nx][ny] == 0)
            {
                visited[wall + 1][nx][ny] = visited[wall][x][y] + 1;
                q.push({nx, ny, wall + 1});
            }
        }
    }
    return (-1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int j = 0;
        string s;
        cin >> s;
        for (char e : s)
            input[i][j++] = e - 48;
    }

    cout << solution();
    return (0);
}