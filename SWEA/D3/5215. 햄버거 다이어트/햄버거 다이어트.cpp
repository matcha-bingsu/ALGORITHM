#include <bits/stdc++.h>
using namespace std;
int materials, limit_kcal, mx;

int get_limit_choice(vector<int>    &tmp)
{
    int limit_choice = materials;

    sort(tmp.begin(), tmp.end());
    while (accumulate(tmp.begin(), tmp.begin() + limit_choice, 0) > limit_kcal)
        limit_choice--;
    return (limit_choice);
}

void    yumyum(int total, int kcal, int idx, int cur_choice_num, int choice_num, vector<pair<int, int>>   &v)
{
    if (cur_choice_num == choice_num)
    {
        if (kcal <= limit_kcal && total > mx)
            mx = total;
        return ;
    }
    for (int i = idx; i < materials; i++)
        yumyum(total + v[i].first, kcal + v[i].second, i + 1, cur_choice_num + 1, choice_num, v);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int limit_choice;
        vector<pair<int, int>>  v;
        vector<int> tmp;

        mx = 0;
        cin >> materials >> limit_kcal;
        for (int i = 0; i < materials; i++)
        {
            int material, kcal;
            cin >> material >> kcal;
            v.push_back({material, kcal});
            tmp.push_back(kcal);
        }
        limit_choice = get_limit_choice(tmp);
        for (int choice_num = 1; choice_num <= limit_choice; choice_num++)
            yumyum(0, 0, 0, 0, choice_num, v);
        cout << '#' << cur_case << ' ' << mx << '\n';
    }
    return (0);
}