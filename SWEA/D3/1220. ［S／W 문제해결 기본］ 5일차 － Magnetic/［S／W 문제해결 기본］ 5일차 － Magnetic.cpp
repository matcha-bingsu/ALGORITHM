#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int cur_test = 1; cur_test <= 10; cur_test++)
    {
        int length;
        int total = 0;
        int arr[100][100];

        cin >> length;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cin >> arr[i][j];
        
        for (int j = 0; j < 100; j++)
        {
            int cnt = 0;
            int status = 0;
            for (int i = 0; i < 100; i++)
            {
                if (status == 1 && arr[i][j] == 2)
                    cnt++;
                if (arr[i][j])
                    status = arr[i][j];
            }
            total += cnt;
        }
        cout << '#' << cur_test << ' ' << total << '\n';
    }
    return (0);
}