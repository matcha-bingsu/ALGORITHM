#include <bits/stdc++.h>
using namespace std;

int calculate(int *scores)
{
    int answer = 0;
    int mx = 0;

    for (int i = 0; i < 101; i++)
    {
        if (scores[i] > mx)
        {
            mx = scores[i];
            answer = i;   
        }
        else if (scores[i] == mx)
            answer = max(i, answer);
    }
    return (answer);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cur_case, test_case;
    int number, answer;
    int scores[101];
    
    cin >> test_case;
    while (test_case--)
    {
        fill(scores, scores + 101, 0);
        
        cin >> cur_case;
        for (int i = 0; i < 1000; i++)
        {
            cin >> number;
            scores[number]++;
        }
        answer = calculate(scores);
        cout << '#' << cur_case << ' ' << answer << '\n';
    }
    return (0);
}