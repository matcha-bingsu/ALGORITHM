#include <bits/stdc++.h>
using namespace std;
int saero[1025][1025];

void    get_answer(int m)
{
    while (m--)
    {
        int sum = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i <= x2; i++)
            sum += saero[i][y2] - saero[i][y1 -1];
        cout << sum << '\n';
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, num;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            sum += num;
            saero[i][j] = sum;
        }
    }

    get_answer(m);
    return (0);
}