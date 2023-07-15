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


struct Node{
    int h, c;
};


void code(int TC){
    int n,h; cin>>n>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<Node>> dp(n,vector<Node>(n,Node{-1,-1}));
    for(int i=0;i<n;i++) dp[i][i] = {h,0};
    function<Node(int,int)>  join = [&](int l, int r){
        int mid = (arr[l]+arr[r])>>1;
        if(arr[r]-mid>h) return Node{0, 2*h};
        else return Node{h-(arr[r]-mid),2*(arr[r]-mid)-1};
    };
    function<Node(int,int)> calc = [&](int l, int r){
        if(r<l) return Node{-1,-1};
        if(dp[l][r].h!=-1) return dp[l][r];
        auto [nh,e] = join(l,r);
        dp[l][r].h = nh, dp[l][r].c = 1e18;
        for(int i=l;i<r;i++){
            if(dp[l][i].h==-1) dp[l][i] = calc(l,i);
            if(dp[i+1][r].h==-1) dp[i+1][r] = calc(i+1,r);
            dp[l][r].c = min(dp[l][r].c, dp[l][i].c+dp[i+1][r].c+e+dp[l][i].h+dp[i+1][r].h-2*h);
        }
        return dp[l][r];
    };
    calc(0,n-1);
    cout<<dp[0][n-1].h+dp[0][n-1].c<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}