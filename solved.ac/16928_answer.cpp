#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> skip;
unordered_map<int, int> trap;
queue<pair<int, int> >  q;
int chck[101];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int ladder, snake, start, end;
    cin >> ladder >> snake;
    
    while (ladder--)
    {
        cin >> start >> end;
        skip.insert({start, end});
    }
    while (snake--)
    {
        cin >> start >> end;
        trap.insert({start, end});
    }
    
    q.push({1, 0});
    chck[1] = 1;
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        if (cur.first == 100)
        {
            cout << cur.second;
            return (0);
        }
        q.pop();
        for (auto dir : {1, 2, 3, 4, 5, 6})
        {
            int now = cur.first + dir;
            if (now > 100)
                continue;
            if (skip.find(now) != skip.end())
                q.push({skip[now], cur.second + 1});
            else if (trap.find(now) != trap.end())
                q.push({trap[now], cur.second + 1});
            else if (!chck[now])
                q.push({now, cur.second + 1});
            chck[now] = 1;
        }
    }
}