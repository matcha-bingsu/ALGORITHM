#include <bits/stdc++.h>
using namespace std;

string  num_to_string(int num)
{
    string ans = "";

    for (int i = 5; i >= 0; i--)
    {
        if (num >= pow(2, i))
        {
            ans.append("1");
            num -= pow(2, i);
        }
        else
            ans.append("0");
    }
    return (ans);
}

int to_graph_number(char c)
{
    int ans = 0;

    if (c >= 'A' && c <= 'Z')
        ans =  c - 'A';
    else if (c >= 'a' && c <= 'z')
        ans = c - 'a' + 26;
    else if (c >= '0' && c <= '9')
        ans = c - '0' + 52;
    else if (c == '+')
        ans = 62;
    else
        ans = 61;
    return (ans);
}

int to_ordinary_num(string ans, int idx)
{
    int ret = 0;

    for (int i = 7; i >= 0; i--)
    {
        if (ans[idx] == '1')
            ret += pow(2, i);
        idx++;
    }
    return (ret);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;
    string  str;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        string ans = "";
        cin >> str;
        
        for (int i = 0; i < str.size(); i++)
        {
            int num = to_graph_number(str[i]);
            ans.append(num_to_string(num));
        }

        cout << '#' << cur_case << ' ';
        for (int i = 0; i < ans.size(); i += 8)
        {
            int num = to_ordinary_num(ans, i);
            cout << char(num);
        }
        cout << "\n";
    }
    return (0);
}