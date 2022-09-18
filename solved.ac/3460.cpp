#include <bits/stdc++.h>
using namespace std;
int tc, num, i;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> tc;
    while (tc--)
    {
        vector<int> v;

        cin >> num;
        if (num % 2 != 0)
        {
            v.push_back(0);
            num--;
        }

        while (num != 0)
        {
            i = 1;
            while (num >= pow(2, i))
                i++;
            num -= pow(2, i - 1);
            v.push_back(i - 1);
        }
        
        sort(v.begin(), v.end());
        for (auto c : v)
            cout << c << ' ';
        cout << '\n';
    }   
    return (0);
}