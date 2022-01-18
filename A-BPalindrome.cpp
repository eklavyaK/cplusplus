#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a, b, detect = 0;
        cin >> a >> b;
        string s;
        cin >> s;
        vector<int> v;
        int count_1 = 0, count_0 = 0;
        int n = (a + b - (a + b) % 2) / 2;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (s[a + b - 1 - i] == '0')
                {
                    detect = 1;
                    break;
                }
                else if(s[a + b - 1 - i] == '?') s[a + b - 1 - i] = '1';
                count_1+=2;
            }
            else if (s[i] == '0')
            {
                if (s[a + b - 1 - i] == '1')
                {
                    detect = 1;
                    break;
                }
                else if(s[a + b - 1 - i] == '?') s[a + b - 1 - i] = '0';
                count_0+=2;
            }
            else if (s[a + b - 1 - i] == '1')
            {
                s[i] = '1';
                count_1+=2;
            }
            else if (s[a + b - 1 - i] == '0')
            {
                s[i] = '0';
                count_0+=2;
            }
            else
                v.emplace_back(i);
        }
        if (detect)
        {
            cout << -1 << endl;
            continue;
        }
        if ((a + b) % 2)
        {
            if (s[(a + b - 1) / 2] == '?')
            {
                if (a % 2)
                    s[(a + b - 1) / 2] = '0';
                else
                    s[(a + b - 1) / 2] = '1';
            }
            else
            {
                if (s[(a + b - 1) / 2] == '0' && a % 2 == 0)
                {
                    cout << -1 << endl;
                    continue;
                }
                else if (s[(a + b - 1) / 2] == '1' && b % 2 == 0)
                {
                    cout << -1 << endl;
                    continue;
                }
            }
        }
        if(count_0<=a && count_1<=b)
        {
            count_0 = a - count_0 - a%2;
            count_1 = b - count_1 - b%2;
            if(count_0+count_1==2*v.size())
            {
                for(int i = 0; i<v.size(); i++) 
                {
                    if(count_1!=0)
                    {s[v[i]] = '1'; s[a+b-1-v[i]] = '1'; count_1-=2;}
                    else
                    {s[v[i]] = '0'; s[a+b-1-v[i]] = '0';}
                }
                cout<<s<<endl;
            }
            else cout<<-1<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}