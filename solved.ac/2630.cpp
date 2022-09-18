#include <bits/stdc++.h>
using namespace std;
int white, blue;
int arr[130][130];

int one(int n, int xs, int ys)
{
    int st = arr[xs][ys];
    for (int i = xs; i < xs + n; i++)
        for (int j = ys; j < ys + n; j++)
            if (arr[i][j] != st)
                return (0);
    return (1);
}

void    solution(int n, int xs, int ys)
{
    if (one(n, xs, ys))
    {
        if (arr[xs][ys] == 0)
            white++;
        else
            blue++;
        return ;
    }
    int half = n / 2;
    solution(half, xs, ys);
    solution(half, xs, ys + half);
    solution(half, xs + half, ys);
    solution(half, xs + half, ys + half);
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    solution(n, 0, 0);
    cout << white << '\n' << blue << '\n';
    return (0);
}