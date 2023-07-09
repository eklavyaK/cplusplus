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
    int cnt[n+1]{}, arr[n+1]{};
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        k = i-k<0 ? n+(i-k) : i-k;
        cnt[k]++;
        arr[i] = k;
    }
    debugarr(cnt,n+1);
    debugarr(arr,n+1);
    function<bool(int)> process = [&](int k){
        int vis[n+1]{}, c = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            ++c;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                j = j+k-arr[j];
                if(j>n) j-=n;
                else if(j<1) j+=n;
            }
        }
        return n-c<=m;
    };
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(2*m>=n-cnt[i] && process(i)) ans.push_back(i);
    }
    cout<<ans.size()<<" ";
    for(auto i : ans) cout<<i<<" ";cout<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}