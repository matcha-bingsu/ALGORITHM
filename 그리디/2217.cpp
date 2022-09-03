// https://www.acmicpc.net/problem/2217 (로프)
#include <bits/stdc++.h>
using namespace std;
int arr[100002];
int mx, n;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        mx = max(mx, arr[i] * (n - i));

    cout << mx;
    return (0);
}