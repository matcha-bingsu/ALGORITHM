#include <bits/stdc++.h>
using namespace std;

void    fix(int idx, char to, string *init)
{
    string tmp = "";
    
    tmp = to;
    for (int i = idx; i < init->length(); i++)
        init->replace(i, 1, tmp);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;
    cin >> test_case;

    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int     cnt = 0;
        string  aim;
        string  init = "";

        cin >> aim;
        for (int i = 0; i < aim.length(); i++)
            init.append("0");
        
        for (int i = 0; i < aim.length(); i++)
        {
            if (aim[i] == init[i])
                continue;
            else
            {
                fix(i, aim[i], &init);
                cnt++;
                i--;
            }
        }
        cout << '#' << cur_case << ' ' << cnt << '\n';
    }
    return (0);
}