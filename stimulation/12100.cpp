// https://www.acmicpc.net/problem/12100 (2048 easy)
#include <bits/stdc++.h>
using namespace std;
int N, mx, previous, rot;
int init[22][22];
int board[22][22];

void    rotate()
{
    int tmp[22][22];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[i][j] = board[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = tmp[j][N - 1 - i];
}

void    before_rotate(int dir)
{
    if (previous > dir)
        rot = previous - dir;
    else
        rot = dir - previous;
    while (rot--)
        rotate();
}

void    get_it(int dir)
{
    for (int i = 0; i < N; i++)
    {
        int idx = 0;
        int tmp[21] = {};
        for (int j = 0; j < N; j++)
        {
            if (!board[i][j])
                continue;
            if (tmp[idx] == 0) //비웠으면 일단 넣고
                tmp[idx] = board[i][j];
            else if (tmp[idx] == board[i][j])
                tmp[idx++] *= 2; //한번 합쳐진 부분이 다시 합쳐질 수 없도록
            else
                tmp[++idx] = board[i][j]; //다른 값을 가지는 블록이랑 충돌
        }
        for (int q = 0; q < N; q++)
            board[i][q] = tmp[q];
    }
}

void    solution()
{
    for (int i = 0; i < (1 << (2 * 5)); i++)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = init[i][j];

        int tmp = i;
        previous = 0;
        for (int i = 0; i < N; i++)
        {
            int dir = tmp % 4;
            tmp /= 4;
            before_rotate(dir);
            get_it(dir);
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mx = max(mx, board[i][j]);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> init[i][j];

    solution();
    cout << mx;
    return (0);
}