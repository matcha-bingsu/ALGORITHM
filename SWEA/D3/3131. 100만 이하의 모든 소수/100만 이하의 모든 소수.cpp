#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    bool    chck[1000001];
    int until = sqrt(1000000);

    fill(chck, chck + 1000001, 0);
    for (int i = 2; i <= until; i++)
    {
        if (chck[i])
            continue;
        for (int j = i * i; j <= 1000000; j += i)
            chck[j] = true;
    }
    for (int i = 2; i <= 1000000; i++)
    {
        if (!chck[i])
            cout << i << ' ';
    }
    return (0);
}