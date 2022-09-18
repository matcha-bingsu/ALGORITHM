// https://www.acmicpc.net/problem/1978 (소수 찾기)
#include <bits/stdc++.h>
using namespace std;
int arr[101];
int cnt, n;

int is_sosu(int  n)
{
    if (n == 1)
        return (0);
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return (0);
    return (1);    
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++)
        if (is_sosu(arr[i]))
            cnt++;
        
    cout << cnt;
    return (0);
}