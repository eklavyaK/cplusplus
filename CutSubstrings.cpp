#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define cerr cout
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


int inf = 500, mod = 1e9+7;

void code(int TC){
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();
    bool is[n]{}; int last = 0;
    for(int i=0;i<n;i++){
        bool f = true;
        for(int j=0;j<m;j++){
            if(i+j>=n || a[i+j]!=b[j]){
                f = false; break;
            }
        }
        is[i] = f;
        if(f) last = i;
    }
    int dp[n][n+1], cnt[n]{}, mn = -1, mx = inf;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        if(!is[i]) continue;
        else if(mn==-1) mn = i;
        else if(i>=mn+m) break;
        dp[i][1] = 1, cnt[i] = 1;
    }
    if(mn==-1){
        cout<<"0 1"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!is[i]) continue;
        int mn = -1, c = inf;
        for(int j=i-m;j>=0;j--){
            if(!is[j]) continue;
            else if(mn==-1) mn = j;
            else if(j<=mn-m) break;
            c = min(cnt[j],c);
        }
        if(mn!=-1) cnt[i] = c+1;
    }
    debugarr(cnt,n);
    for(int i=max(0ll,last-m+1);i<n;i++) if(is[i]) mx = min(mx,cnt[i]);
    for(int i=0;i<n;i++){
        if(!is[i]) continue;
        mn = -1;
        for(int j=i-m;j>=0;j--){
            if(!is[j]) continue;
            else if(mn==-1) mn = j;
            else if(j<=mn-m) break;
            assert(cnt[i]-1>=0);
            dp[i][cnt[i]] = (dp[i][cnt[i]] + dp[j][cnt[i]-1]) % mod;
        }
        debugarr(dp[i],mx+1);
    }
    int ans = 0;
    debug(last);
    for(int i=max(0ll,last-m+1);i<n;i++){
        ans = (ans + dp[i][mx]) % mod;
    }
    cout<<mx<<" "<<ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}