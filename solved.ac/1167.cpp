#include <bits/stdc++.h>
using namespace std;
int         mx;
vector<int> arr[100001];
vector<int> arr_dis[100001];
int         chck[100001];

void    get_it(int num, int ans)
{
    chck[num] = 1;
    mx = max(mx, ans);
    for (int i = 0; i < arr[num].size(); i++)
    {
        if (!chck[arr[num][i]])
            get_it(arr[num][i], ans + arr_dis[num][i]);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, num, station, dis;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        while (1)
        {
            cin >> station;
            if (station == -1)
                break;
            cin >> dis;
            arr[num].push_back(station);
            arr_dis[num].push_back(dis);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!chck[i])
            get_it(i, 0);

    cout << mx;
    return (0);
}