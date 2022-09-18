// https://www.acmicpc.net/problem/11050 (이항계수 1)
#include <bits/stdc++.h>
using namespace std;

int get(int n)
{
    if (n == 1 || n == 0)
        return (1);
    return (n * get(n - 1));
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    
    int mom = get(n);
    int son = get(k) * get(n - k);

    cout << mom / son;
    return (0);
}