#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int save, find;
    string  address, paswd;
    unordered_map<string, string>   map;

    cin >> save >> find;
    while (save--)
    {
        cin >> address >> paswd;
        map.insert({address, paswd});
    }

    while (find--)
    {
        cin >> address;
        cout << map[address] << '\n';
    }
    return (0);
}