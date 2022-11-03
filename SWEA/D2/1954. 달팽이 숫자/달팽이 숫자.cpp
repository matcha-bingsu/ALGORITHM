#include <bits/stdc++.h>
using namespace std;
int number;

void    print(int cur_case, int n, int (*arr)[10])
{
    cout << '#' << cur_case << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n'; 
    }
}

void    fill(int (*arr)[10], int x, int y)
{
    for (int i = x; i < y; i++)
        arr[x][i] = number++;
    for (int i = x + 1; i < y; i++)
        arr[i][y - 1] = number++;
    for (int i = y - 2; i >= x; i--)
        arr[y - 1][i] = number++;
    for (int i = y - 2; i > x; i--)
        arr[i][x] = number++;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case, snail;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        cin >> snail;

        number = 1;
        int st = 0;
        int ed = snail;
        int arr[10][10];

        while (st < ed)
        {
            fill(arr, st, ed);
            st++;
            ed--;
        }

        print(cur_case, snail, arr);
    }
    return (0);
}