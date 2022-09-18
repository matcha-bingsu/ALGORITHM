// https://www.acmicpc.net/problem/11866 (요세푸스 문제 0)
#include <bits/stdc++.h>
using namespace std;
queue<int>  q;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int  n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << '<';
    while (!q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if (q.size() != 1)
            cout << ", ";
        q.pop();
   }
   cout << '>';
    return (0);
}