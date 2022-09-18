#include <bits/stdc++.h>
using namespace std;
int n, a, mx;
int alpha[123];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> a;
    string          words[n];
    vector<char>    v;
    vector<int>     tmp;
    alpha['a'] = 1;
    alpha['t'] = 1;
    alpha['n'] = 1;
    alpha['i'] = 1;
    alpha['c'] = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        for (int j = 4; j < words[i].size() - 4; j++)
            v.push_back(words[i][j]);
    }
    if (a < 5)
        cout << 0;
    else
    {
        for (int i = 0; i < v.size(); i++)
            if (v[i] == 'a' || v[i] == 't' || v[i] == 'n' || v[i] == 'i' || v[i] == 'c')
                v.erase(v.begin() + i--);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (i < a - 5)
                tmp.push_back(0);
            else
                tmp.push_back(1);
        }
        do{
            int cnt = 0;
            for (int i = 0; i < tmp.size(); i++)
                if (tmp[i] == 0)
                    alpha[v[i]] = 1;
            for (int i = 0; i < n; i++)
            {
                int j = -1;
                while (++j < words[i].size())
                    if (!alpha[words[i][j]])
                        break;
                if (j == words[i].size())
                    cnt++;
            }
            mx = max(mx, cnt);
            for (int i = 0; i < tmp.size(); i++)
                if (tmp[i] == 0)
                    alpha[v[i]] = 0;
        }while (next_permutation(tmp.begin(), tmp.end()));
        cout << mx;
    }
    return (0);
}