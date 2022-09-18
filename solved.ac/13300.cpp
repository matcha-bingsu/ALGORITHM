#include <bits/stdc++.h>
using namespace std;
int n, k, sex, grade, cnt;
int stud[7][2];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    while (n--)
    {
        cin >> sex >> grade;
        stud[grade][sex]++;
    }
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (stud[i][j] % k != 0)
                cnt += stud[i][j] / k + 1;
            else
                cnt += stud[i][j] / k;
        }
    }
    cout << cnt;
    return (0);
}