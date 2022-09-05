//https://www.acmicpc.net/problem/18808 (스티커 붙이기)
#include <bits/stdc++.h>
using namespace std;
int n, m, k, r, c, sx, sy, cnt;
int notebook[40][40];
int sticker[12][12];

int chck_shape()
{
    int x, y, flag;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + r > n || j + c > m)
                break;
            else
            {
                flag = 0;
                for (x = 0; x < r; x++)
                    for (y = 0; y < c; y++)
                        if (notebook[i + x][j + y] && sticker[x][y])
                            flag++;
            }
            if (!flag)
            {
                sx = i;
                sy = j;
                return (1);
            }
        }
    }
    return (0);
}

void    change_shape()
{
    int tmp_board[12][12];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp_board[i][j] = sticker[i][j];

    swap(r, c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sticker[i][j] = tmp_board[c - j -1][i];
}

void    put_in()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (sticker[i][j])
            {
                notebook[sx + i][sy + j] = 1;
                cnt++;
            }
        }
    }
}

void    solution()
{
    while (k--)
    {
        cin >> r >> c;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];

        for (int i = 0; i < 4; i++)
        {
            if (chck_shape())
            {
                put_in();
                break;
            }
            change_shape();
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    
    solution();
    cout << cnt;
    return (0);
}