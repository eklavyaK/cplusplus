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
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif

const int mod = 998244353, N = 2e5;
vector<vector<int>> fac(N+5);
int exp(int a, int n){
    int res = 1;
    while(n>0){
        if(n&1) res = (res*a) % mod;
        a = (a*a) % mod; n>>=1;
    }
    return res;
}


void code(int TC){
    int n; cin>>n;
    int x[2*n], y[2*n];
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,rx,ry; 
        cin>>u>>v>>rx>>ry;
        int k = gcd(rx,ry);
        rx/=k, ry/=k;
        x[i] = rx, y[i] = ry;
        graph[u].push_back({v,i});
        x[n+i] = ry, y[n+i] = rx;
        graph[v].push_back({u,n+i});
    }
    int f[n+5]{}, root[n+5]{};
    function<void(int,int)> dfs = [&](int node,int par){
        for(auto [u,i] : graph[node]){
            if(u==par) continue;
            for(auto j : fac[x[i]]){
                int cnt = 0, curr = x[i];
                while(curr%j==0) curr/=j, cnt++;
                if(f[j]<cnt) root[j] += cnt-f[j];
                f[j] = max(0ll,f[j]-cnt);
            }
            for(auto j : fac[y[i]]){
                int cnt = 0, curr = y[i];
                while(curr%j==0) curr/=j, cnt++;
                f[j]+=cnt;
            }
            debug(node);
            debug(u);
            debugarr(f,n);
            debugarr(root,n);
            dfs(u,node);
            for(auto j : fac[y[i]]){
                int cnt = 0, curr = y[i];
                while(curr%j==0) curr/=j, cnt++;
                f[j]-=cnt;
            }
            for(auto j : fac[x[i]]){
                int cnt = 0, curr = x[i];
                while(curr%j==0) curr/=j, cnt++;
                f[j]+=cnt;
            }
            debug(node);
            debug(u);
            debugarr(f,n);
            debugarr(root,n);
        }
    };
    dfs(1,0);
    vector<int> ans(n+1,1);
    debugarr(root,n);
    for(int i=1;i<=n;i++) ans[1] = ans[1] * exp(i,root[i]) % mod;
    debug(ans[1]);
    function<void(int,int)> compute = [&](int node,int par){
        for(auto [u,i] : graph[node]){
            if(u==par) continue;
            ans[u] = ans[node] * y[i] % mod * exp(x[i],mod-2) % mod;
            compute(u,node);
        }
    };
    compute(1,0);
    int tot = 0;
    for(int i=1;i<=n;i++) tot += ans[i];
    cout<<tot % mod<<endl;
    
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    for(int i=2;i<=N;i++){
        int curr = i;
        for(int j=2;j*j<=curr;j++){
            if(curr%j!=0) continue;
            fac[i].push_back(j);
            while(curr%j==0)curr/=j;
        }
        if(curr>1) fac[i].push_back(curr);
    }
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}