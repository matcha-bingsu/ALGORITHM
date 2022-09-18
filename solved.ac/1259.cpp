// https://www.acmicpc.net/problem/1259 (팰린드럼수)
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(1)
    {
        deque<int>  d;
        string      s;
        
        cin >> s;
        if (s.length() == 1 && s.front() == '0')
            break;
        for (int n : s)
            d.push_back(n - 48);
        while (!d.empty())
        {
            if (d.front() != d.back())
            {
                cout << "no\n";
                break;
            }
            else
            {
                d.pop_front();
                if (!d.empty())
                    d.pop_back();
            }
        }
        if (d.empty())
            cout << "yes\n";
    }
    return (0);
}