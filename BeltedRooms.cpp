#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,count=0; string s; cin>>n>>s; bool detectg = false, detectl = false;
        for(int i = 0; i<n; i++) {if(detectg && detectl) break; else if(s[i]=='>') detectg = true; else if(s[i]=='<') detectl = true;}
        if(!detectg || !detectl) {cout<<n<<endl; continue;}
        s = s.substr(n-1,1) + s;
        for(int i = 1; i<=n; i++) if(s[i-1] == '-' || s[i] == '-') count++;
        cout<<count<<endl;
    }
    return 0;
}