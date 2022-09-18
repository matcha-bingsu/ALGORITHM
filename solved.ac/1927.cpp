// https://www.acmicpc.net/problem/1927
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int                                             n;
    priority_queue<int, vector<int>, greater<int>>  q;

    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (q.size() == 0)
                cout << "0\n";
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(num);
    }
    return (0);
}