// https://www.acmicpc.net/problem/10828 (스택)
#include <bits/stdc++.h>
using namespace std;
stack<int>  st;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n--)
    {
        string  s;
        cin >> s;

        if (s == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        else if (s == "pop" || s == "top")
        {
            if (st.empty())
                cout << -1 << '\n';
            else
            {
                cout << st.top() << '\n';
                if (s == "pop")
                    st.pop();
            }
        }
        else if (s == "size")
            cout << st.size() << '\n';
        else
            cout << st.empty() << '\n';
    }
    return (0);
}