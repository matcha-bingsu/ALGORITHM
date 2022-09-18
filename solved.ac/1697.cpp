// https://www.acmicpc.net/problem/1697 
#include <bits/stdc++.h>
using namespace std;
int board[100001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    queue<pair<int, int>>   q;
    pair<int, int>          cur;
    q.push({n, 0});

    board[n] = -1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.first == k)
            break;
        for (auto num : {cur.first - 1, cur.first + 1, 2 * cur.first})
        {
            int t = cur.second + 1;
            if (num < 0 || num > 100000)
                continue;
            if (board[num] != 0)
                continue;
            q.push({num, t});
            board[num] = -1;
        }
    }
    cout << cur.second;
    return (0);
}