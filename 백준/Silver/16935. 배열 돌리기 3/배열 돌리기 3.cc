#include <bits/stdc++.h>
using namespace std;
int n, m, k, num, tmp2, x_half, y_half; 
int init[101][101];
int tmp[101][101];

void    one()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[n - 1 - i][j] = init[i][j];
}

void    two()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][m - 1 - j] = init[i][j];
}

void    three()
{
    tmp2 = n;
    n = m;
    m = tmp2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = init[m - 1 - j][i];
}

void    four()
{
    tmp2 = n;
    n = m;
    m = tmp2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tmp[i][j] = init[j][n - 1 - i];
            
}

void    five_six(int num)
{
    x_half = n / 2;
    y_half = m / 2;
    if (num == 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i < x_half && j < y_half)
                    tmp[i][j + y_half] = init[i][j];
                else if (i < x_half && j >= y_half)
                    tmp[i + x_half][j] = init[i][j];
                else if (i >= x_half && j < y_half)
                    tmp[i - x_half][j] = init[i][j];
                else 
                    tmp[i][j - y_half] = init[i][j];
            }
        }
    }
    else if (num == 6)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i < x_half && j < y_half)
                    tmp[i + x_half][j] = init[i][j];
                else if (i < x_half && j >= y_half)
                    tmp[i][j - y_half] = init[i][j];
                else if (i >= x_half && j < y_half)
                    tmp[i][j + y_half] = init[i][j];
                else 
                    tmp[i - x_half][j] = init[i][j];
            }
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> init[i][j];
    while (k--)
    {
        cin >> num;
        if (num == 1)
            one();
        else if (num == 2)
            two();
        else if (num == 3)
            three();
        else if (num == 4)
            four();
        else
            five_six(num);
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                init[i][j] = tmp[i][j];
        fill(tmp[0], tmp[100], 0);
    }
    for (int i = 0; i < 101; i++)
    {
            for (int j = 0; j < 101; j++)
            {
                if (!init[i][j])
                    break;
                cout << init[i][j] << ' ';
            }
        if (!init[i + 1][0])
            break;
        else
            cout << '\n';
    }
}