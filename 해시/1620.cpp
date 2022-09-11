// https://www.acmicpc.net/problem/1620
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int  n, c;
    unordered_map<string, int>  book;
    string                      book2[100002];

    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        string  monster;
        cin >> book2[i];
        book[book2[i]] = i;
    }
    
    while (c--)
    {
        string  input;
        cin >> input;
        if (isdigit(input[0]))
            cout << book2[stoi(input)] << '\n';
        else
            cout << book[input] << '\n';
    }
    return (0);
}