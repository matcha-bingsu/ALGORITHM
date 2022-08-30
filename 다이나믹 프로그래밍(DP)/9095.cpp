
#include <bits/stdc++.h>
using namespace std;
int d[11];
int n, num;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    while (n--)
    {
        cin >> num;
        for (int i = 4; i <= num; i++)
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        cout << d[num] << '\n';
    }
    return (0);
}