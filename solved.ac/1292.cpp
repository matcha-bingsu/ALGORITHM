#include <bits/stdc++.h>
using namespace std;
int start, fin, total;
int num = 2;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> start >> fin;
    int arr[fin + 1];

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= fin; i++)
    {
        if (num != total)
        {
            arr[i] = arr[i - 1] + num;
            total++;
        }
        else
        {
            arr[i] = arr[i - 1] + ++num;
            total = 1;
        }
    }
    cout << arr[fin] - arr[start - 1];
    return (0);
}