#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        int n, a, b, c, count = 0;
        cin >> n >> a >> b >> c;
        string s;
        cin>>s;
        char ch[n];bool flag[n] = {false};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                if (b != 0)
                {
                    ch[i] = 'P', b--;
                    count++;
                    flag[i]=1;
                }
            }
            else if (s[i] == 'P')
            {       
                if (c != 0)
                {
                    ch[i] = 'S';
                    c--;
                    count++;
                    flag[i]=1;
                }
            }
            else if (a != 0)
            {
                ch[i] = 'R';
                a--;
                count++;
                flag[i]=1;
            }
        }
        if (count >= ceil((float)n / 2))
        {
            cout << "yes"
                 << endl;
            for (int i = 0; i < n; i++)
            {
                if (flag[i])
                    cout << ch[i];
                else if (a != 0)
                {
                    cout << 'R';
                    a--;
                }
                else if (b != 0)
                {
                    cout << 'P';
                    b--;
                }
                else if(c!=0)
                {
                    cout << 'S';
                    c--;
                }
            }
        }
        else
            cout << "no";
        cout<<endl;
    }
    return 0;
}