#include <bits/stdc++.h>
using namespace std;
int standard;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;
    int arr[num];
    int hey[num];

    for (int i = 0; i < num; i++)
        cin >> arr[i];

    hey[0] = arr[0];
    for (int i = 1; i < num; i++)
        hey[i] = max(hey[i - 1] + arr[i], arr[i]);
    cout << *max_element(hey, hey + num);
}