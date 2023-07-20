#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif





void code(int TC){
    int n,m; cin>>n>>m;
    vector<tuple<int,int,int>> v(m);
    string s; cin>>s;
    int dis = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') dis+=(1<<(n-1-i));
    }
    debug(dis);
    for(int i=0;i<m;i++){
        int d; string s, t;
        cin>>d>>s>>t;
        int a = d, b = 0, c = 0;
        for(int j=0;j<n;j++){
            if(s[j]=='1') b+=(1<<(n-1-j));
            if(t[j]=='1') c+=(1<<(n-1-j));
        }
        debug(a,b,c);
        v[i] = {a,b,c};
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int> D(5000,1e9), V(5000);
    D[0] = 0;
    q.push({0,0});
    while(!q.empty()){
        auto [d,u] = q.top(); q.pop();
        D[u] = min(D[u],d);
        for(int j=0;j<m;j++){
            auto [a,b,c] = v[j];
            if((c&u)==c && D[(b|u)]>D[u]+a){
                D[(b|u)] = a+d;
                q.push({a+d,(b|u)});
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<5000;i++) if((dis&i)==dis) ans = min(ans,D[i]);
    cout<<(ans==1e9?-1:ans)<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}