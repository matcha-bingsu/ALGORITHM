#include <bits/stdc++.h>
using namespace std;
int mn = 987654321;
int chck[10];

int allowed(int num, int flag)
{
    if (!flag)
    {
        if (num == 0 && chck[0])
            return (0);
        while (num)
        {
            if (chck[num % 10])
                return (0);
            num /= 10; 
        }
        return (1);
    }
    int cnt = 0;
    if (num == 0)
        return (1);
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int target, m;
    cin >> target >> m;

    while (m--)
    {
        int num;
        cin >> num;
        chck[num] = 1;
    }
    
    mn = abs(target - 100);
    for (int i = 0; i <= 1000000; i++)
    {
        if (allowed(i, 0))
            mn = min(mn, abs(target - i) + allowed(i, 1));
    }
    cout << mn;
    return (0);    
}