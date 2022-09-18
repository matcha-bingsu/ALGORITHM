// https://www.acmicpc.net/problem/10866
#include <bits/stdc++.h>
using namespace std;
deque<int>  d;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push_front" || s == "push_back")
        {
            int num;
            cin >> num;
            if (s == "push_front")
                d.push_front(num);
            else
                d.push_back(num);
        }
        else if (s == "pop_back" || s == "back")
        {
            if (d.empty())
                cout << -1 << '\n';
            else
            {
                    cout << d.back() << '\n';
                if (s == "pop_back")
                    d.pop_back();
            }
        }
         else if (s == "pop_front" || s == "front")
        {
            if (d.empty())
                cout << -1 << '\n';
            else
            {
                    cout << d.front() << '\n';
                if (s == "pop_front")
                    d.pop_front();
            }
        }
        else if (s == "size")
            cout << d.size() << '\n';
        else
            cout << d.empty() << '\n';
    }

    return (0);
}