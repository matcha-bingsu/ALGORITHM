#include <bits/stdc++.h>
using namespace std;
int     n, mx;
char    board[51][51];
int     dx[4] = {0, -1, 0, 1};
int     dy[4] = {-1, 0, 1, 0};

void    bfs()
{
    int arr[n];
    int cnt;
    for (int i = 0; i < n; i++)
    {
        fill(arr, arr + n, 0);
        arr[0] = 1;
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == board[i][j - 1])
                arr[j] = arr[j - 1];
            else
                arr[j] = arr[j - 1] + 1;
        }
        sort(arr, arr + n);
        cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                cnt++;
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
    }
    for (int j = 0; j < n; j++)
    {
        int arr[n];
        fill(arr, arr + n, 0);
        arr[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (board[i][j] == board[i - 1][j])
                arr[i] = arr[i - 1];
            else
                arr[i] = arr[i - 1] + 1;
        }
        sort(arr, arr + n);
        cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
                cnt++;
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string  s;
        int     j = 0;
        cin >> s;
        for (auto c : s)
            board[i][j++] = c;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int tmpx = i + dx[dir];
                int tmpy = j + dy[dir];
                if (tmpx < 0 || tmpy < 0 || tmpx >= n || tmpy >= n)
                    continue;
                if (board[i][j] == board[tmpx][tmpy])
                    continue;
                swap(board[i][j], board[tmpx][tmpy]);
                bfs();
                swap(board[i][j], board[tmpx][tmpy]);
            }
        }
    }
    cout << mx;
    return (0);
}