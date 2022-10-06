#include <bits/stdc++.h>
using namespace std;
int n;
int mn = 987654321;
int number[21][21];
int team[11];
int chck[21];

int     get_sum(int *arr)
{
    int total = 0;

    for (int i = 0; i < n / 2 - 1; i++)
    {
        for (int j = i + 1; j < n / 2; j++)
            total += number[arr[i]][arr[j]] + number[arr[j]][arr[i]];
    }
    return (total);
}

void    yeah(int idx, int from)
{
    if (idx == n / 2)
    {
        int j = 0;
        int anther_team[11];
        
        for (int i = 0; i < n; i++)
        {
            if (!chck[i])
                anther_team[j++] = i;
        }
        mn = min(mn, abs(get_sum(team) - get_sum(anther_team)));
        return ;
    }

    for (int i = from; i < n; i++)
    {
        team[idx] = i;
        chck[i] = 1;
        yeah(idx + 1, i + 1);
        chck[i] = 0;
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> number[i][j];
    
    chck[0] = 1;
    yeah(1, 1);
    cout << mn;
    return (0);
}