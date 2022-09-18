#include <bits/stdc++.h>
using namespace std;
int mn = 987654321;
string s;

int to_number(int *num)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int tmp = 1;
        for (int j = i; j < s.length() - 1; j++)
            tmp *= 10;
        ans += tmp * num[i];
    }
    return (ans);
}

void    get(int idx, int *target, int *bowl, int *save, int i)
{
    if (idx == s.length())
    {
        int ans;
        int bowl_num = to_number(bowl);
        int target_num = to_number(target);
        if (bowl_num > target_num)
            ans = bowl_num - target_num + s.length();
        else
            ans = target_num - bowl_num + s.length();
        mn = min(mn, ans);
        if (target_num > 100)
            mn = min(mn, target_num - 100);
        else
            mn = min(mn, 100 - target_num);
        return ;
    }
    if (lower_bound(save, save + i, target[idx]) != save + i)
        bowl[idx] = *lower_bound(save, save + i, target[idx]);
    else
        bowl[idx] = save[0];
    get(idx + 1, target, bowl, save, i);
    
    if (upper_bound(save, save + i, target[idx]) != save + i)
        bowl[idx] = *upper_bound(save, save + i, target[idx]);
    else
        bowl[idx] = save[0];
    get(idx + 1, target, bowl, save, i);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s;

    int target[s.length()];
    for (int i = 0; i < s.length(); i++)
        target[i] = s[i] - '0';

    int n;
    cin >> n;

    int tmp_save[10] = {0,};
    int save[10 - n];

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        tmp_save[in] = 1;
    }

    int i = 0;
    for (auto c : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
        if (!tmp_save[c])
            save[i++] = c;

    int bowl[s.length()];
    get(0, target, bowl, save, i);

    cout << mn;
    return (0);
}