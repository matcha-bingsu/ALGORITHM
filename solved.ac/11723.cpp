#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    unordered_set<int>  us;
    
    int n;
    cin >> n;
    while (n--)
    {
        string  order;
        int     num;
        cin >> order;
        if (order == "add")
        {
            cin >> num;
            us.insert(num);
        }
        else if (order == "remove")
        {
            cin >> num;
            us.erase(num);
        }
        else if (order == "check")
        {
            cin >> num;
            if (us.find(num) != us.end())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (order == "toggle")
        {
            cin >> num;
            if (us.find(num) != us.end())
                us.erase(num);
            else
                us.insert(num);
        }
        else if (order == "all")
        {
            for (int i = 1; i <=20; i++)
                if (us.find(i) == us.end())
                    us.insert(i);
        }
        else if (order == "empty")
            us.clear();
    }
    return (0);
}