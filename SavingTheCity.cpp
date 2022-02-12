#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int a,b; cin>>a>>b; int l=-1,r=-1,track=1, count=0,result=0;
        string s; cin>>s; vector<int> c_m,c_g;int n = s.size();
        for(int i = 0; i<n; i++) if(s[i]=='1') {l=i;break;} if(l!=-1) {for(int i = n-1; i>=0; i--) if(s[i]=='1') {r=i;break;}} else {cout<<0<<endl;continue;}
        for(int i = l; i<=r;) {count=0;if(track){while(i<n && s[i]=='1'){count++;i++;} c_m.emplace_back(count);track=!track;}else {while(i<n && s[i]=='0'){count++;i++;} c_g.emplace_back(count);track=!track;}}
        result = a; for(int i = 0; i<c_g.size(); i++){if(c_g[i]*b<a) result+=c_g[i]*b; else result+=a;} cout<<result<<endl;
    }
    return 0;
}