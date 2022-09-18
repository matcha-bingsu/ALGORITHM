#include <bits/stdc++.h>
using namespace std;
int n;
int board[27][27];
int chck[27][27];
int xd[4] = {0, -1, 0, 1};
int yd[4] = {-1, 0, 1, 0};
vector<int>     v;

void    bfs(int x, int y, int cnt)
{
    queue<pair<int, int>>   q;
    q.push({x, y});
    chck[x][y] = 1;
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int xx = cur.first + xd[dir];
            int yy = cur.second + yd[dir];
            if (xx < 1 || yy < 1 || xx > n || yy > n)
                continue;
            if (!board[xx][yy] || chck[xx][yy])
                continue;
            q.push({xx, yy});
            chck[xx][yy] = 1;
            cnt++;
        }
    }
    v.push_back(cnt + 1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string  s;
        int     j = 1;
        cin >> s;
        for (auto c : s)
            board[i][j++] = c - 48;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] == 1 && !chck[i][j])
                bfs(i, j, 0);

    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return (0);
}