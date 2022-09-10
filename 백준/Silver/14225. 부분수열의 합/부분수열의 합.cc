#include <bits/stdc++.h>
using namespace std;
int     n;
bool    chck[2000001];
int     seq[21];
int     j = 1;

void    solve(int num, int sum)
{
    chck[sum] = 1;
    if (num == n)
        return ;
    solve(num + 1, sum);
    solve(num + 1, sum + seq[num]);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    solve(0, 0);
    while (chck[j])
        j++;
    cout << j;
    return (0);
}