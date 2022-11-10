#include <bits/stdc++.h>
using namespace std;

int compare(string &cmp, string &str, int idx)
{
    int j = 0;

    if (idx + cmp.size() >= str.size())
        return (1);
    while (j < cmp.size() && cmp[j] == str[idx])
    {
        j++;
        idx++;
    }
    if (j == cmp.size())
        return (1);
    else
        return (0);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int mx = 0;
        string str, tmp; 
        string cmp = "";

        cin >> str;
        tmp = str[0];
        cmp.append(tmp);
        
        for (int i = 1; i < str.size(); i++)
        {
            if (!compare(cmp, str, i))
            {
                tmp = str[i];
                cmp.append(tmp);
            }
            else
            {
                mx = max(mx, int(cmp.size()));
                i += cmp.size() - 1;
                if (i >= str.size())
                    break;
            }
        }
        cout << '#' << cur_case << ' ' << mx << '\n';
    }
    return (0);
}