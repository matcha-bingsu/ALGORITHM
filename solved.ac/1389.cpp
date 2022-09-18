#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int chck[101];
int n, m, ans;

int bfs(int num)
{
    queue<pair<int, int> >  q;
    int sum = 0;
    chck[num] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        if (board[num][i])
        {
            q.push({i, 1});
            sum += 1;
            chck[i] = 1;
        }
    }
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (board[cur.first][i] == 1 && !chck[i])
            {
                chck[i] = 1;
                q.push({i, cur.second + 1});
                sum += cur.second + 1;
            }
        }
    }
    return (sum);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int mn = 987654321;
    cin >> n >> m;
    while (m--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        board[num1][num2] = 1;
        board[num2][num1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = bfs(i);
        if (tmp < mn)
        {
            mn = tmp;
            ans = i;
        }
        fill(chck, chck + (n + 1), 0);
    }
    cout << ans;
    return (0);
}