#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        string s; cin>>s;
        if(s.length()%2) cout<<"no"<<endl;
        else if (s.substr(0,s.length()/2) == s.substr(s.length()/2)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}