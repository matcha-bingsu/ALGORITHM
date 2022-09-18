#include <bits/stdc++.h>
using namespace std;
int n, m, sum, flag, init;

int is_prime(int n)
{
    if (n == 1)
        return (0);
    int i = 1;
    while (n >= i * i)
        i++;
    for (int j = 2; j <= i - 1; j++)
        if (n % j == 0)
            return (0);
    return (1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        if (is_prime(i))
        {
            if (!flag)
            {
                init = i;
                flag++;
            }
            sum += i;
        }   
    }
    if (!sum)
        cout << -1;
    else
        cout << sum << '\n' << init;
    return (0);
}