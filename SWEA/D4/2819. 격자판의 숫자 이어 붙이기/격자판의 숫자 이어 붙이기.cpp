#include <bits/stdc++.h>
using namespace std;
int arr[4][4];
unordered_set<int>  s;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void    init()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }
    s.clear();
}

void    bfs(int i, int j)
{
    queue<pair<pair<int, int>, pair<int, int>>>  q;
    q.push({{i, j}, {1, arr[i][j]}});
    while (!q.empty())
    {
        int x, y, len, number;

        tie(x, y) = q.front().first;
        tie(len, number) = q.front().second;
        q.pop();
        if (len == 7)
        {
            s.insert(number);
            continue;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];
            if (new_x < 0 || new_y < 0 || new_x >= 4 || new_y >= 4)
                continue;
            q.push({{new_x, new_y}, {len + 1, number * 10 + arr[new_x][new_y]}});
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
        init();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                bfs(i, j);
        }
        cout << '#' << cur_case << ' ' << s.size() << '\n'; 
    }
    return (0);
}