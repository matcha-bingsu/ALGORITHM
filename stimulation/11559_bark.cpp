//https://www.acmicpc.net/problem/11559 (뿌요뿌요)
#include <bits/stdc++.h>
using namespace std;

bool    isPuyo;
bool    vis[12][6];
string  board[12];
int     dx[] = {1, 0, -1, 0};
int     dy[] = {0, 1, 0, -1};
int     ans;

void    reset()
{
    for(int i = 0; i < 12; ++i)
        for(int j = 0; j < 6; ++j)
            vis[i][j] = false;
}

void    puyo(int x, int y)
{
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int> > q;
    vector<pair<int, int> > tmp;
    q.push({x, y});
    tmp.push_back({x, y});
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || vis[nx][ny] || board[nx][ny] != color)
                continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            tmp.push_back({nx, ny});
        }
    }

    if (tmp.size() >= 4)
    {
        isPuyo = true;
        for (auto cur : tmp)
            board[cur.first][cur.second] = '.';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; i++)
        cin >> board[i];

    do{
        isPuyo = false;
        //drag down하는 부분
        for (int j = 0; j < 6; j++)
        {
            for (int i = 10; i >= 0; i--)
            {
                int tmp = i;
                while (tmp < 11 && board[tmp + 1][j] == '.')
                {
                    swap(board[tmp][j], board[tmp + 1][j]);
                    tmp++;
                }
            }
        }

        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                if (!vis[i][j] && board[i][j] != '.')
                    puyo(i, j);
        
        if (isPuyo)
            ans++;
        reset();
    }while (isPuyo);
    cout << ans;
}