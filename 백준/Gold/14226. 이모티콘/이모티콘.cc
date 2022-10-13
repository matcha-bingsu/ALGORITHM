#include <bits/stdc++.h>
using namespace std;
int    chck[2001][2001];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int    target;
    queue<tuple<int, int, int> > q;

    cin >> target;
    q.push({1, 0, 0});
    fill(chck[0], chck[2000], -1);
    chck[1][0] = 0;

    while (!q.empty())
    {
        int emoticon, clipboard, number;
        tie(emoticon, clipboard, number) = q.front();

        if (emoticon == target)
        {
            cout << number;
            return (0);
        }
        q.pop();

        //copy
        if (emoticon + clipboard <= 2000 && chck[emoticon + clipboard][clipboard] == -1)
        {
            chck[emoticon + clipboard][clipboard] = number + 1;
            q.push({emoticon + clipboard, clipboard, number + 1});
        }

        //paste
        if (chck[emoticon][emoticon] == -1)
        {
            chck[emoticon][emoticon] = number + 1;
            q.push({emoticon, emoticon, number + 1});
        }
        
        //delete
        if (emoticon - 1 >= 0 && chck[emoticon - 1][clipboard] == -1)
        {
            chck[emoticon - 1][clipboard] = number + 1;
            q.push({emoticon - 1, clipboard, number + 1});
        }
    }
    return (0);
}