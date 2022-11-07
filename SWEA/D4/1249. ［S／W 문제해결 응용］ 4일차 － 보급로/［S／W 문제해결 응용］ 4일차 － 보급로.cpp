#include <bits/stdc++.h>
using namespace std;
int n;
int board[100][100], chck[100][100];
int dir_x[4] = {0, -1, 0, 1};
int dir_y[4] = {-1, 0, 1, 0};

void    init()
{
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        string str;

        cin >> str;
        for (auto c : str)
            board[i][j++] = c - '0';
    }
    fill(&chck[0][0], &chck[99][100], 2147483647);
}

void    bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    chck[0][0] = 0;
    while (!q.empty())
    {
        int total, x, y;

        tie(total, x, y) = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1)
            continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int new_x = x + dir_x[dir];
            int new_y = y + dir_y[dir];
            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
                continue;
            if (total + board[new_x][new_y] >= chck[new_x][new_y])
                continue;
            chck[new_x][new_y] = total + board[new_x][new_y];
            q.push({total + board[new_x][new_y], new_x, new_y});
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        cin >> n;

        init();

        bfs();

        cout << '#' << cur_case << ' ' << chck[n - 1][n - 1] << '\n';
    }
    return (0);
}