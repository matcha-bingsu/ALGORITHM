#include <bits/stdc++.h>
using namespace std;
int calculate(set<int> &garo, set<int> &saero)
{
    int j = 0;
    int mx = 0;

    for (auto tmp1 : saero)
    {
        int i = 0;
        for (auto tmp2 : garo)
        {
            mx = max(mx, (tmp1 - j) * (tmp2 - i));
            i = tmp2;
        }
        j = tmp1;
    }
    return (mx);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int garo_len, saero_len, num;
    set<int>    garo;
    set<int>    saero;

    cin >> saero_len >> garo_len >> num;
    while (num--)
    {
        int flag, number;
        
        cin >> flag >> number;
        if (flag)
            saero.insert(number);
        else
            garo.insert(number);
    }
    saero.insert(saero_len);
    garo.insert(garo_len);
    cout << calculate(garo, saero);
    return (0);
}