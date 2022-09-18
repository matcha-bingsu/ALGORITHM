#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string  input;
    cin >> input;

    int result = 0;
    string num;
    bool isminus = false;

    for (int i = 0; i <= input.size(); i++)
    {
        if (input[i] == '-' || input[i] == '+' || i == input.size())
        {
            if (isminus)
            {
                result -= stoi(num);
                num = "";
            }
            else
            {
                result += stoi(num);
                num = "";
            }
        }
        else
            num += input[i];
        if (input[i] == '-')
            isminus = true;
    }
    cout << result;
    return (0);
}