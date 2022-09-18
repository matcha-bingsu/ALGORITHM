#include <bits/stdc++.h>
using namespace std;
int n, num;
vector<int> v[101];
int chck[101];

void    rotate(int num)
{
    for (int i = 0; i < v[num].size(); i++)
    {
        if (!chck[v[num][i]])
        {
            chck[v[num][i]] = 1;
            rotate(v[num][i]);
        }
    }
}  

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            if (num)
                v[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        fill(chck, chck + (n + 1), 0);
        if (!v[i].empty())
            rotate(i);
        for (int i = 1; i <= n; i++)
            cout << chck[i] << ' ';
        cout << '\n';
    }
    return (0);
}