// https://www.acmicpc.net/problem/1026 (보물)
#include <bits/stdc++.h>
using namespace std;
int a[52];
int b[52];
int ans;

int comp(int a, int b)
{
    return (a > b);
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(b, b + n);
    sort(a, a + n, comp);

    for (int i = 0; i < n; i++)
        ans += a[i] * b[i];
    
    cout << ans;
    return (0);
}