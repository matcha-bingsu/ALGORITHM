#include <bits/stdc++.h>
using namespace std;

int to_number(string &order)
{
    int ans;

    if (order == "ZRO")
        ans = 0;
    else if (order == "ONE")
        ans = 1;
    else if (order == "TWO")
        ans = 2;
    else if (order == "THR")
        ans = 3;
    else if (order == "FOR")
        ans = 4;
    else if (order == "FIV")
        ans = 5;
    else if (order == "SIX")
        ans = 6;
    else if (order == "SVN")
        ans = 7;
    else if (order == "EGT")
        ans = 8;
    else
        ans = 9;
    
    return (ans);
}

string  to_mystring(int n)
{
    string str;

    if (n == 0)
        str = "ZRO";
    else if (n == 1)
        str = "ONE";
    else if (n == 2)
        str = "TWO";
    else if (n == 3)
        str = "THR";
    else if (n == 4)
        str = "FOR";
    else if (n == 5)
        str = "FIV";
    else if (n == 6)
        str = "SIX";
    else if (n == 7)
        str = "SVN";
    else if (n == 8)
        str = "EGT";
    else
        str = "NIN";
    
    return (str);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int number;
        string str, order;
        multiset<int>   ms;

        cin >> str >> number;
        
        while (number--)
        {
            cin >> order;
            ms.insert(to_number(order));
        }

        cout << '#' << cur_case << '\n';
        while (!ms.empty())
        {
            cout << to_mystring(*ms.begin()) << ' ';
            ms.erase(ms.begin());
        }
    }
    return (0);
}