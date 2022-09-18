#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return (a);
}

int main(void)
{
    int num, i;
    cin >> num;
    while (num--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int lcm = a * b / gcd(a, b);
        for (i = x; i <= lcm; i += a)
        {
            int tmp = i % b;
            if (!tmp)
                tmp = b;
            if (tmp == y)
            {
                cout << i << '\n';
                break;
            }
        }
        if (i > lcm)
            cout << "-1\n";
    }
    return (0);
}