#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        string s; cin>>s; int n = s.length(), res = 0,i=0;
        char c = s[0];int r,l; while(i<n && s[i]==c) i++;l=i-1;
        for(;i<n; i++)
        {
            c = s[i];i++;
            while(i<n && s[i]==c) i++;
            r = i--;if(r<n&&s[r]!=s[l]) res!=0?res=min(r-l+1,res): res=r-l+1;l=i; 
        }
        cout<<res<<endl;
    }
    return 0;
}