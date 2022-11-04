#include <bits/stdc++.h>
using namespace std;

string  to_my_string(int n)
{
    string ans = "";

    while (n > 0)
    {
        char tmp = '0' + n % 10;
        n /= 10;
        string s(1, tmp);
        ans.append(s);
    }
    reverse(ans.begin(), ans.end());
    return (ans);

}

int how_many_clap(string &str)
{
    int ans = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '3' || str[i] == '6' || str[i] == '9')
            ans++;
    }
    return (ans);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int end_num;

    cin >> end_num;
    for (int cur_num = 1; cur_num <= end_num; cur_num++)
    {
        string str;
        int clap;
        
        str = to_my_string(cur_num);
        clap = how_many_clap(str);
        if (!clap)
            cout << cur_num << ' ';
        else
        {
            while (clap--)
                cout << '-';
            cout << ' ';
        }
    }
    return (0);
}