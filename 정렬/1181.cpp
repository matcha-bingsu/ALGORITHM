// https://www.acmicpc.net/problem/1181 (단어 정렬)
#include <bits/stdc++.h>
using namespace std;
int     N;
string  input[20001];

int comp(string str1, string str2)
{
    if (str1.length() == str2.length())
        return (str1 < str2);
    else
        return (str1.length() < str2.length());
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    
    sort(input, input + N, comp);

    for (int i = 0; i < N; i++)
    {
        if (input[i] == input[i - 1])
            continue;
        cout << input[i] << '\n';
    }
    return (0);
}