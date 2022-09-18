#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int howmany, a, b, x, y, num;
    cin >> howmany;
    while (howmany--)
    {
        int t = 0;
        int tmp_y = -1;
        unordered_set<int>  us;
        cin >> a >> b >> x >> y;
        while (tmp_y != y)
        {
            num = a * t + x;
            tmp_y = num % b;
            if (tmp_y == 0)
                tmp_y = b;
            if (us.find(tmp_y) == us.end())
                us.insert(tmp_y);
            else
            {
                cout << "-1\n";
                break;
            }
            t++;
        }
        if (tmp_y == y)
            cout << num << '\n';
    }
    return (0);
}