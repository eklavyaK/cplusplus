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



const int N = 1e6;

void code(int TC){
    int n,m,q; cin>>n>>m>>q;
    string s; cin>>s;
    vector<vector<int>> st(n), en(n);
    for(int j=0;j<m;j++){
        int l,r; cin>>l>>r;
        l--, r--;
        st[l].push_back(j);
        en[r].push_back(j);
    }
    map<int,int> ord;
    vector<pair<int,int>> priority(n);
    for(int i=0;i<n;i++){
        for(auto j : st[i]) ord[j];
        if(ord.empty()){
            priority[i] = {N*N,i};
            continue;
        }
        auto [a,b] = *ord.begin();
        priority[i] = {N*a+b,i};
        ord[a]++;
        for(auto j : en[i]) ord.erase(j);
    }
    sort(priority.begin(),priority.end());
    vector<int> f(n), pos(n);
    int ptr = -1, zero = 0, all = 0, mn = 0;
    for(int i=0;i<n;i++) f[i] = (s[priority[i].S]=='1'), pos[priority[i].S] = i, all += (priority[i].F!=N*N);
    for(int i=0;i<n;i++) ptr += f[i];
    for(int i=0;i<=ptr;i++) zero += (f[i]^1);
    for(int i=0;i<all;i++) mn += (f[i]^1);
    while(q--){
        int x; cin>>x; x = pos[x-1];
        if(!f[x]){
            ptr++;
            if(!f[ptr]) zero++;
            if(x<=ptr) zero--;
            if(x<all) mn--;
        }
        else{
            if(!f[ptr]) zero--;
            ptr--;
            if(x<=ptr) zero++;
            if(x<all) mn++;
        }
        f[x]^=1;
        cout<<min(mn,zero)<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}