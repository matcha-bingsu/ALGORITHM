// https://www.acmicpc.net/problem/18808 (스티커 붙이기)
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int note[42][42];
int r, c;
int paper[12][12];

void    rotate()
{
    int tmp[12][12];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = paper[i][j];
  
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
        paper[i][j] = tmp[r-1-j][i];

    swap(r, c);
}

bool    pastable(int x, int y)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (note[x + i][y + j] && paper[i][j])
                return (false);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (paper[i][j])
                note[x + i][y + j] = 1;
    return (true);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> k;

    while (k--)
    {
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> paper[i][j];
        
        for (int rot = 0; rot < 4; rot++)
        {
            bool is_paste = false;
            for (int i = 0; i <= n - r; i++)
            {
                if (is_paste)
                    break;
                for (int j = 0; j < m - c; j++)
                {
                    if (pastable(i, j))
                    {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste)
                break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += note[i][j];
    
    cout << cnt << '\n';
}