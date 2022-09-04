#include <bits/stdc++.h>
using namespace std;
int num[201];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, number;
    cin >> n;
    while (n--)
    {
        cin >> number;
        num[number + 100]++;
    }
    cin >> number;
    cout << num[number + 100];
    return (0);
}