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


vector<int> v({1,10,100,1000,10000});


void code(int TC){
    string s; cin>>s;
    int n = s.size();
    int sum[n]{};
    for(int i=0;i<n;i++){
        if(i==0) sum[i] = v[s[i]-'A'];
        else sum[i] = sum[i-1]+v[s[i]-'A'];
    }
    vector<int> forward_dp(n), backward_dp(n+1);
    vector<int> idx(5,-1),mxx(n+1,65);
    function<int(int,char)> compute = [&](int i,char c){
        int ans = v[c-'A'], mx = -1;
        for(int j=c-'A';j<5;j++) mx = max(idx[j],mx);
        if(mx>=0) ans+=forward_dp[mx];
        if(mx==-1) ans+=v[s[i]-'A']-sum[i];
        else if(mx>=0) ans+=sum[mx]-sum[i-1];
        return ans;
    };
    char mc = 'A';
    for(int i=n-1;i>=0;i--){
        backward_dp[i] = ((mc>s[i])?-1:1)*v[s[i]-'A']+backward_dp[i+1];
        mc = max(mc,s[i]);
        mxx[i] = mc;
    }
    for(int i=0;i<n;i++){
        forward_dp[i] = compute(i,s[i]);
        idx[s[i]-'A'] = i;
    }
    fill(idx.begin(),idx.end(),-1);
    int ans = -1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(mxx[i+1]>65+j) continue;
            ans = max(ans,compute(i,char(65+j))+backward_dp[i+1]);
        }
        idx[s[i]-'A'] = i;
    }
    cout<<ans<<endl;
    debug(v);
    debug(idx);
    debugarr(sum,n);
    debugvar(forward_dp);
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1; cin >> TC;
    for (int i = 1; i <= TC; i++) 
        code(i);
    return 0;
}