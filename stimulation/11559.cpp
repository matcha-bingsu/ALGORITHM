//https://www.acmicpc.net/problem/11559 (뿌요뿌요)
#include <bits/stdc++.h>
using namespace std;
char    now[12][6];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int visited[12][6];
int pop_number;
queue<pair<int,int> >  pop_coordinate;

void    drag_down()
{
    for (int j = 0; j < 6; j++)
    {
        int i = 11;
        int q = 0;
         while (1)
        {
            while (i + q >= 0 && now[i + q][j] == '.')
                q--;
            int p = 0;
            while (i + q + p >= 0 && now[i + q + p][j] != '.')
                p--;
            for (int x = 0; x < abs(p); x++)
            {
                now[i - x][j] = now[i + q - x][j];
                if (q != 0)
                    now[i + q - x][j] = '.';
            }
            if (i + q + p > 0)
                i = i + p;
            else
                break;
        }
    }
}

void    pop()
{   
    queue<pair<int,int> >   q;

    while (!pop_coordinate.empty())
    {
        int i = pop_coordinate.front().first;
        int j = pop_coordinate.front().second;
        q.push({i, j});   
        visited[i][j] = 0;
        int tmp = now[i][j];
        now[i][j] = '.';
        while (!q.empty())
        {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int p = 0; p < 4; p++)
            {
                int nx = x + dx[p];
                int ny = y + dy[p];
                if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || !visited[nx][ny] || now[nx][ny] != tmp)
                    continue;
                q.push({nx, ny});
                visited[nx][ny] = 0;
                now[nx][ny] = '.';
            }
        } 
        pop_coordinate.pop();
    }
    pop_number++;
}

int pop_possible()
{
    queue<pair<int,int> >   q;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int cnt = 0;
            if (now[i][j] != '.' && !visited[i][j]) 
            {
                q.push({i, j});
                visited[i][j] = 1;
                while (!q.empty())
                {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    for (int p = 0; p < 4; p++)
                    {
                        int nx = x + dx[p];
                        int ny = y + dy[p];
                        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || visited[nx][ny] || now[nx][ny] != now[i][j])
                            continue;
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                        cnt++;
                    }
                }          
            }
            else
                visited[i][j] = 1;
            if (cnt > 2)
                pop_coordinate.push({i, j});
        }
    }
    return (pop_coordinate.size());
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 12; i++)
    {
        int j = 0;
        string s;
        cin >> s;
        for (char c : s)
            now[i][j++] = c;
    }

    while (pop_possible())
    {
        pop();
        drag_down();
        fill(visited[0], visited[12], 0);
    }
    cout << pop_number;

    return (0);
}