// https://www.acmicpc.net/problem/10845 (큐)
#include <bits/stdc++.h>
using namespace std;
queue<int>  q;

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
        if (s == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (s == "pop" ||s == "front" ||s == "back")
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                if (s != "back")
                    cout << q.front() << '\n';
                else
                    cout << q.back() << '\n';
                if (s == "pop")
                    q.pop();
            }
        }
        else if (s == "size")
            cout << q.size() << '\n';
        else
            cout << q.empty() << '\n';
    }
    return (0);
}