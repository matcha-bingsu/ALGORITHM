#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int arr[301][301];

void    rotate(int si, int sj, int ei, int ej)
{
    int tmp = arr[si][sj];

    for (int j = sj; j < ej; j++)
        arr[si][j] = arr[si][j + 1];

    for (int i = si; i < ei; i++)
        arr[i][ej] = arr[i + 1][ej];
    
    for (int j = ej; j > sj; j--)
        arr[ei][j] = arr[ei][j - 1];
    
    for (int i = ei; i > si; i--)
        arr[i][sj] = arr[i - 1][sj];

    arr[si + 1][sj] = tmp;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    while (r--)
    {
        int si = 0;
        int sj = 0;
        int ei = n - 1;
        int ej = m - 1;
        while (si < ei && sj < ej)
            rotate(si++, sj++, ei--, ej--);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return (0);
}