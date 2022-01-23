#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; string s; cin>>n>>s;
        int r=-1, l=-1;for(int i = 0; i<n; i++) if(s[i]=='1'){l=i;break;}
        for(int i = n-1; i>=0; i--) if(s[i]=='0') {r=i;break;}
        if (r==-1||l==-1||r<l) cout<<s<<endl;
        else cout<<(s.substr(0,l)+s.substr(r))<<endl;
    }
    return 0;
}