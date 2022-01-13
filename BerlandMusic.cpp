#include<bits/stdc++.h>
using namespace std;
/***************************************************Berland Music********************************************************/
int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int a[n],in[n+1];
        for(int i = 0; i<n; i++) {cin>>a[i]; in[a[i]] = i;}
        string s; cin>>s;
        vector<int> vl, vd;
        for(int i = 0; i<n; i++) {if(s[i]=='1') vl.push_back(a[i]); else vd.push_back(a[i]);}
        sort(vl.begin(),vl.end());
        sort(vd.begin(),vd.end());
        vd.insert(vd.end(),vl.begin(),vl.end());
        for(int i = 0; i<n; i++) a[in[vd[i]]] = i+1;
        for(auto i : a) cout<<i<<" "; cout<<endl;
    }
    return 0;
}