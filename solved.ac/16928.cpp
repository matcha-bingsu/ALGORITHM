#include <bits/stdc++.h>
using namespace std;
int mp[101];
unordered_map<int, int> good;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    mp[0] = -1;
    int ladder, snake, start, end;
    cin >> ladder >> snake;

    while (ladder--)
    {
        cin >> start >> end;
        good[end] = start;
    }
    while (snake--)
    {
        cin >> start >> end;
        mp[end] = -1;
    }

    for (int i = 2; i <= 100; i++)
    {
        int option1;
        int option2 = 987654321;
        if (good.find(i) != good.end())
            mp[i] = mp[good[i]];
        else
        {
            if (i % 6 <= 1)
                option1 = i / 6;
            else
                option1 = i / 6 + 1;
            for (int j = 1; j <= 6; j++)
            {
                if (i - j < 1 || mp[i - j] == -1)
                    continue;
                option2 = min(option2, mp[i - j] + 1);
            }
            mp[i] = min(option1, option2); 
        }
    }
    cout << mp[100];
    return (0);
}