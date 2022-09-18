#include <bits/stdc++.h>
using namespace std;
int flag;
int save[30];
string given;
stack<pair<int, char>>  st;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> given;
    for (int i = 0; i < given.size(); i++)
    {
        if (given[i] == '(' || given[i] == '[')
            st.push({i, given[i]});
        else if (given[i] == ')' || given[i] == ']')
        {
            if (st.empty())
            {
                flag++;
                break;
            }
            if ((given[i] == ')' && st.top().second != '(') || (given[i] == ']' && st.top().second != '['))
            {
                flag++;
                break;
            }
            int         num;
            vector<int> tmp_arr;
            int         tmp_num = st.top().first;
            st.pop();
            if (given[i] == ')')
                num = 2;
            else
                num = 3;
            for (int j = tmp_num; j < i; j++)
                if (save[j])
                    tmp_arr.push_back(save[j]);
            if (tmp_arr.size() > 1)
                save[tmp_num] = accumulate(tmp_arr.begin(), tmp_arr.end(), 0) * num;
            else if (tmp_arr.size() == 1)
                save[tmp_num] = *tmp_arr.begin() * num;
            else
                save[tmp_num] = num;
            fill(save + (tmp_num + 1), save + i, 0);
        }
    }
    if (flag || !st.empty())
        cout << 0;
    else
        cout << accumulate(save, save + 30, 0);
    return (0);
}