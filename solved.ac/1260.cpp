#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
int chck[1001];

void    dfs(int num)
{
    cout << num <<  ' ';
    chck[num] = 1;
    sort(&v[num][0], &v[num][0] + v[num].size());
    for(int i = 0; i < v[num].size(); i++)
        if (!chck[v[num][i]])
            dfs(v[num][i]);

}

void    bfs(int num)
{
    queue<pair<int, int> >  q;

    cout << '\n' << num << ' ';
    chck[num] = 1;
    for (int i = 0; i < v[num].size(); i++)
        q.push({num, v[num][i]});
    
    while (!q.empty())
    {
        pair<int, int>  cur = q.front();
        q.pop();
        if (!chck[cur.second])
        {
            cout << cur.second << ' ';
            chck[cur.second] = 1;
            for (int i = 0; i < v[cur.second].size(); i++)
            {
                if (chck[v[cur.second][i]])
                    continue;
                q.push({cur.second, v[cur.second][i]});
            }
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, st;
    cin >> n >> m >> st;

    while (m--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }

    dfs(st);
    fill(chck, chck + (n + 1), 0);
    bfs(st);
    return (0);
}