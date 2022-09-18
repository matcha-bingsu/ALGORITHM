#include <bits/stdc++.h>
using namespace std;
int pibo[21];
int n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    pibo[0] = 0;
    pibo[1] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        pibo[i] = pibo[i - 1] + pibo[i - 2];
    cout << pibo[n];
    return (0);
}