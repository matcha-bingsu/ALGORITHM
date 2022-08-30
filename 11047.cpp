// https://www.acmicpc.net/problem/11047 (동전 0)
#include <bits/stdc++.h>
using namespace std;
int arr[11], cnt, n, target;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> target;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        cnt += target / arr[i];
        target = target % arr[i];
    }
    cout << cnt;
    return (0);
}