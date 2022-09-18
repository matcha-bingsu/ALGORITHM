// https://www.acmicpc.net/problem/11279 (최대 힙)
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>>    q;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--)
    {
        int order;
        cin >> order;
        if (order == 0)
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(order);
    }
    return (0);
}