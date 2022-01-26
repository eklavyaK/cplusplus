#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    string s[3]; int in[3]; set<int> en,fn; for(int i = 0; i<3; i++) {cin>>s[i]; en.insert(s[i][1]); fn.insert(s[i][0]);in[i]=s[i][0];}
    if(en.size()==1)
    {
        if(fn.size()==1) cout<<0<<endl;
        else if(fn.size()==2) cout<<1<<endl;
        else {
            sort(in,in+3);if(in[1]-in[0]==1 && in[2]-in[1]==1) cout<<0<<endl;
            else if(in[1]-in[0]==2 || in[2]-in[1]==2) cout<<1<<endl;
            else if(in[1]-in[0]==1 || in[2]-in[1]==1) cout<<1<<endl;else cout<<2<<endl;
        }
    }
    else if(en.size()==2)
    {
        if(s[1][1]==s[2][1]) {abs(s[1][0]-s[2][0])<3?cout<<1<<endl:cout<<2<<endl;}
        else if(s[0][1]==s[2][1]) {abs(s[0][0]-s[2][0])<3?cout<<1<<endl:cout<<2<<endl;}
        else {abs(s[1][0]-s[0][0])<3?cout<<1<<endl:cout<<2<<endl;}
    }
    else cout<<2<<endl;
    return 0;
}