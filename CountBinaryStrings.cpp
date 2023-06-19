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


int mod = 998244353;

void code(int TC){
    int n; cin>>n;
    vector<int> dsu(n), l2(n,-1), c(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int k; cin>>k;
            if(k==1) dsu[i] = j;
            else if(k==2) l2[j] = i;
        }
    }
    int class_number = 0;
    for(int i=0;i<n;i++){
        int end = dsu[i];
        dsu[i] = class_number;
        int init = i;
        c[class_number] = max(c[class_number],l2[i]);
        while(i+1<=end){
            i++;
            end = max(end,dsu[i]);
            dsu[i] = class_number;
            c[class_number] = max(c[class_number],l2[i]);
        }
        if(c[class_number]>=init){
            cout<<0<<endl;
            return;
        }
        class_number++;
    }
    debug(dsu);
    int dp[n]{2};
    int same[n][n]{2};
    for(int j=1;j<n;j++){
        if(dsu[j]==dsu[j-1]) dp[j] = dp[j-1];
        else if(c[dsu[j]]==-1) dp[j] = (dp[j-1]<<1)%mod;
        else dp[j] = ((dp[j-1]<<1)-same[c[dsu[j]]][j-1]+3*mod)%mod;
        for(int i=c[dsu[j]]+1;i<j;i++){
            same[i][j] = same[i][j-1];
            if(dsu[j]==dsu[j-1]) continue;
            if(c[dsu[j]]!=-1) same[i][j] = (same[i][j]-same[c[dsu[j]]][j-1]);
            same[i][j] = (same[i][j]+3*mod)%mod;
        }
        same[j][j] = dp[j];
    }
    debugarr(dp,n);
    cout<<dp[n-1]<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}