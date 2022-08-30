// https://www.acmicpc.net/problem/11726 (2 x n 타일링)
#include <bits/stdc++.h>
using namespace std;
int n;
int tile[1002];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    tile[1] = 1;
    tile[2] = 2;
    for (int i = 3; i <= n; i++)
        tile[i] = tile[i - 1] + tile[i - 2];
    
    cout << tile[n] % 10007;
    return (0);
}