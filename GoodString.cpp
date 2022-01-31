#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; string s; cin>>n>>s;
        if(s[0]=='<' && s[n-1]=='>')
        {
        int r,l;
        for(int i = 0; i<n; i++) if(s[i]=='>') {l=i;break;}
        for(int i = n-1; i>=0; i--) if(s[i]=='<') {r = n-1-i;break;}
        cout<<min(r,l)<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}