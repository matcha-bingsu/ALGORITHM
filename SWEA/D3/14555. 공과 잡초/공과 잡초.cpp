 #include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;
    cin >> test_case;

    for (int cur_test = 1; cur_test <= test_case; cur_test++)
    {
        string  field;
        int     cnt = 0;

        cin >> field;
        for (int i = 0; i < field.size(); i++)
        {
            if (field[i] == '(' && (field[i + 1] == '|' || field[i + 1] == ')'))
            {
                cnt++;
                i++;
            }
            else if (field[i] == ')' && i - 1 >= 0 && (field[i - 1] == '|' || field[i - 1] == '('))
                cnt++;
        }
        cout << '#' << cur_test << ' ' << cnt << '\n';
    }
    return (0);
}