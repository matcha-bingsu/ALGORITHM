// https://www.acmicpc.net/problem/11659 (구간 합 구하기 4)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    int arr[100002];
    arr[0] = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num + arr[i - 1];
    }
    
    while (m--)
    {
        int i, j;

        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << '\n'; 
    }
    return (0);
}