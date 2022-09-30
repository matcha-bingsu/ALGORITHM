/*
시간복잡도 : 4^10
쓸 알고리즘 : 백트래킹
N수 : 11
시작시작 : 02.07 ~ 2.28 (이전에 답 본 적 있음)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
int mx = -2147483648;
int mn = 2147483647;

void    get(int idx, int total, int add, int sub, int mul, int div)
{
    if (idx == n)
    {
        mx = max(mx, total);
        mn = min(mn, total);
        return ;
    }
    if (add)
        get(idx + 1, total + arr[idx], add - 1, sub, mul, div);
    if (sub)
        get(idx + 1, total - arr[idx], add, sub - 1, mul, div);
    if (mul)
        get(idx + 1, total * arr[idx], add, sub, mul - 1, div);
    if (div)
        get(idx + 1, total / arr[idx], add, sub, mul, div - 1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int number, add, sub, mul, div;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        arr.push_back(number);
    }
    cin >> add >> sub >> mul >> div;
    get(1, arr[0], add, sub, mul, div);
    cout << mx << '\n' << mn;
    return (0);
}