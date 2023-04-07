#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    int n = a+b+2*(c+d);
    string s; cin>>s;
    vector<vector<int>> range(3);
    int ca = 0, cb = 0, l = 0;
    for(int i=0;i<n;i++)s[i]=='A'?ca++:cb++;
    while(true){
        int j = l;
        if(l+1>=n)break;
        else if(s[l]==s[l+1]){
            l++; continue;
        }
        while(l+1<n && s[l]!=s[l+1])l++;
        int i = l;
        if(s[j]=='A' && s[i]=='B') range[0].push_back(i-j+1);
        else if(s[j]=='B' && s[i]=='A') range[2].push_back(i-j+1);
        else range[1].push_back(i-j+1);
        l++;
    }
    if(ca!=a+c+d||cb!=b+c+d){
        cout<<"NO"<<endl;
        return;
    }
    sort(range[0].begin(),range[0].end());
    sort(range[1].begin(),range[1].end());
    sort(range[2].begin(),range[2].end());
    for(auto i : range[0]){
        if(c>0){
            if(c<(i>>1))d-=(i>>1)-c-1, c = 0;
            else c-=(i>>1);
        }
        else if(d>0) d-=(i>>1)-1;
        else break;
    }
    for(auto i : range[1]){
        if(c>0){
            if(c<(i>>1))d-=(i>>1)-c, c = 0;
            else c-=(i>>1);
        }
        else if(d>0) d-=(i>>1)-c;
        else break;
    }
    for(auto i : range[2]){
        if(d>0){
            if(d<(i>>1))c-=(i>>1)-d-1, d = 0;
            else d-=(i>>1);
        }
        else if(c>0) c-=(i>>1)-1;
        else break;
    }
    if(c>0 || d>0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}