#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
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


int knapsack(vector<int> & v){
    int n = v.size(), mx = 0, sum = 0;
    for(int i = 0; i < n; i++){
        mx = max(v[i], mx);
        sum += v[i];
    }
    if(mx >= sum/2) return mx * (sum - mx);
    vector<int> cnt(sum/2 + 1);
    for(int i = 0; i < n; i++) cnt[v[i]]++;
    vector<int> act;
    for(int i = 1; i <= sum/2; i++){
        if(!cnt[i]) continue;
        int cur = 1;
        while(cur < cnt[i]) act.push_back(cur * i), cnt[i] -= cur, cur <<= 1;
        if(cnt[i]) act.push_back(cnt[i] * i);
    }
    int can[sum/2 + 1]{1};
    for(auto u : act){
        for(int i = sum/2; i >= u; i--) if(can[i - u]) can[i] = 1;
    }
    int ans = 0;
    for(int i = sum/2; i >= 1; i--){
        if(can[i]){
            ans = i; break;
        }
    }
    return ans * (sum - ans);
}


void code(int TC){
    int n; cin >> n;
    vector<vector<int>> T(n + 5);
    for(int i = 2; i <= n; i++){
        int u; cin >> u;
        T[u].push_back(i);
        T[i].push_back(u);
    }
    int ans = 0;
    vector<int> sz(n + 5);
    function<void(int, int)> dfs = [&](int u, int p){
        vector<int> cur;
        for(auto v : T[u]){
            if(v == p) continue;
            dfs(v, u);
            sz[u] += sz[v];
            cur.push_back(sz[v]);
        }
        sz[u] = sz[u] + 1;
        if(cur.size()) ans += knapsack(cur);
    };
    dfs(1, 0);
    cout << ans <<  endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}