// #include <bits/stdc++.h>
// using namespace std;
// // int mn = 987654321;

// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     int num, stan, tmp;
//     // cin >> num;
//     for (num = 1; num <= 100; num++)
//     {
//         int mn = 987654321;
//         stan = sqrt(num);
//         while (stan != 0)
//         {   
//             int cnt = 0;
//             int tmp = num;
//             int minus_tmp = stan;
//             while (1)
//             {
//                 tmp -= pow(minus_tmp, 2);
//                 cnt++;
//                 if (!tmp)
//                     break;
//                 minus_tmp = sqrt(tmp);
//             }
//             mn = min(mn, cnt);
//             stan--;
//         }
//         cout << num << " : " << mn << '\n';
//     }
//     return (0);
// }

#include <bits/stdc++.h>
using namespace std;
int mn = 987654321;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int num;
    cin >> num;
    int arr[num + 1];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for (int i = 4; i <= num; i++)
    {
        arr[i] = 987654321;
        for (int j = sqrt(i); j > 1; j--)
            arr[i] = min(arr[i], arr[i - j * j] + 1);
    }
    cout << arr[num];
    return (0);
}