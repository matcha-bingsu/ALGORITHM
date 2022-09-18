// https://www.acmicpc.net/problem/10814 
#include <bits/stdc++.h>
using namespace std;

int     age[100002];
string  name[100002];
int     m_age[100002];
string  m_name[100002];

void    merge(int st, int ed)
{
    int mid = (ed + st) / 2;
    int p1 = st;
    int p2 = mid;
    for (int i = st; i < ed; i++)
    {
        if (p1 == mid)
        {
            m_age[i] = age[p2];
            m_name[i] = name[p2++];
        }
        else if (p2 == ed)
        {
            m_age[i] = age[p1];
            m_name[i] = name[p1++]; 
        }
        else if (age[p1] > age[p2])
        {
            m_age[i] = age[p2];
            m_name[i] = name[p2++];
        }
        else
        {
            m_age[i] = age[p1];
            m_name[i] = name[p1++];
        }
    }
    for (int i = st; i < ed; i++)
    {
        age[i] = m_age[i];
        name[i] = m_name[i];
    }   
}

void    solution(int st, int ed)
{
    if (ed - st == 1)
        return ;
    int mid = (ed + st) / 2;
    solution(st, mid);
    solution(mid, ed);
    merge(st, ed);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> age[i] >> name[i];

    solution(0, n);
    for (int i = 0; i < n; i++)
        cout << m_age[i] << ' ' << m_name[i] << '\n';
    return (0);
}