// https://www.acmicpc.net/problem/1463 (1로 만들기)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    
    int arr[n + 2];
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = 1 + arr[i - 1];
        if (i % 2 == 0)
            arr[i] = min(arr[i], 1 + arr[i / 2]);
        if (i % 3 == 0)
            arr[i] = min(arr[i],1 + arr[i / 3]);
    }
    cout << arr[n];
    return (0);
}