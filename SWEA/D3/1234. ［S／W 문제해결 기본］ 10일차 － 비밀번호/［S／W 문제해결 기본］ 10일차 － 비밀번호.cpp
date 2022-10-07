#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int test_case = 1; test_case <= 10; test_case++)
    {
        int num;
        string str;
        vector<int> v;

        cin >> num;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
            v.push_back(str[i] - '0');
        
        int flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i < v.size() - 1; i++)
            {
                if (v[i] == v[i + 1])
                {
                    flag++;
                    v.erase(v.begin() + i);
                    v.erase(v.begin() + i);
                    i--;
                }
            }
        }
        cout << '#' << test_case << ' ';
        for (auto each : v)
            cout << each;
        cout << '\n';
    }
    return (0);
}