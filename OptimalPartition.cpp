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

int inf = 1e9;


void code(int TC){
    int n; cin>>n;
    vector<int> arr(n), dp(n), sum(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> tree(n*4+5,-inf);
    function<void(int,int,int,int,int)> update = [&](int node, int  l, int r, int x, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)>>1;
        if(x<=mid) update(2*node,l,mid,x,val);
        else update(2*node+1,mid+1,r,x,val);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int node,  int l, int r, int st, int en){
        if(st>r || en<l || en<st) return -inf;
        if(st<=l && en>=r) return tree[node];
        int mid = (l+r)>>1;
        return max(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
    };
    set<pair<int,int>> st;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        sum[i] = sum[i-1*(i!=0)] + arr[i];
        v[i] = {sum[i],i};
    }
    int c[n]{};
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) c[v[i].S] = i;
    for(int i=0;i<n;i++){
        dp[i] = dp[i-1*(i!=0)] + (arr[i]>0?1*(arr[i]!=0):-1*(arr[i]!=0));
        int id = (lower_bound(v.begin(),v.end(),make_pair(sum[i],-1ll))-v.begin())-1;
        if(id>=0) dp[i] = max(dp[i],i+query(1,0,n-1,0,id));
        if(sum[i]>0) dp[i] = i+1;
        update(1,0,n-1,c[i],dp[i]-i);
    }
    cout<<dp[n-1]<<endl;
    debug(dp);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}