#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test_case;

    cin >> test_case;
    for (int cur_case = 1; cur_case <= test_case; cur_case++)
    {
        int num, valid, number;
        
        cin >> num >> valid;

        int students[num + 1];
        fill(students, students + (num + 1), 0);
    
        while (valid--)
        {
            cin >> number;
            students[number] = 1;
        }
        cout << '#' << cur_case << ' ';
        for (int i = 1; i <= num; i++)
        {
            if (!students[i])
                cout << i << ' ';
        }
        cout << '\n';
    }
    return (0);
}