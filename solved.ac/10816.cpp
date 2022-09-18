// https://www.acmicpc.net/problem/10816 (숫자카드2)
#include <bits/stdc++.h>
using namespace std;
int arr[20000002];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        arr[num + 10000000] += 1;
    }
    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;
        cout << arr[num + 10000000] << ' ';
    }
    return (0);
}