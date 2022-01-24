#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s; cin>>s;
    vector<int> vl,vr,res;
    for(int i = 0; i<s.size(); i++) 
    {if(s[i]=='(') vl.emplace_back(i); else vr.emplace_back(i);}
    int l = 0, r=vr.size()-1,count=0;
    while(l<vl.size() && r>=0)
    {
        if(vl[l]<vr[r]) {res.emplace_back(vl[l]);res.emplace_back(vr[r]);r--,l++;count+=2;}
        else r--;
    }
    sort(res.begin(),res.end());
    if(res.empty()) cout<<0<<endl;
    else {cout<<1<<'\n'<<res.size()<<'\n'; for(auto i : res) cout<<i+1<<" "; cout<<endl;}
    return 0;
}