#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int ncheck[40];
int toleftcheck[40];
int torightcheck[40];

void    fill(int k, int i, int  status)
{
    ncheck[i] = status;
    toleftcheck[k + i] = status;
    torightcheck[k - i + n - 1] = status;
}
void    func(int k)
{
    if (k == n)
    {
        cnt++;
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        if (!ncheck[i] && !toleftcheck[k + i] && !torightcheck[k - i + n - 1])
        {
            fill(k, i, 1);
            func(k + 1);
            fill(k, i, 0);
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    func(0);
    cout << cnt;
}
