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

int n,k,A;
const int N = 3e5;
int tree[N*4], lazy[N*4], dp[N];
vector<pair<int,int>> X[N];
void pushdown(int node){
    lazy[2*node] += lazy[node];
    tree[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    tree[2*node+1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int st, int en, int c){
    if(en<st || st>r || en<l) return;
    if(st<=l && en>=r){
        tree[node]+=c, lazy[node]+=c;
        return;
    }
    pushdown(node);
    int mid = (l+r)>>1;
    update(2*node,l,mid,st,en,c);
    update(2*node+1,mid+1,r,st,en,c);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(en<st || st>r || en<l) return LLONG_MAX;
    if(st<=l && en>=r) return tree[node];
    pushdown(node);
    int mid = (l+r)>>1;
    return min(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}
void code(int TC){
    cin>>n>>k>>A;
    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        // x = rand() % k;
        // y = rand() % (k-x);
        // c = rand() % 1000;
        // cout<<x<<' '<<y<<' '<<c<<endl;
        X[x].push_back({y,c});
    }
    for(int i=k;i>=0;i--){
        int curr = 0;
        for(auto [y,c] : X[i]){
            update(1,0,k,i+1,k-y-1,c);
            curr+=c;
        }
        dp[i] = dp[i+1] + curr;
        int q = query(1,0,k,i+1,k);
        dp[i] = min(dp[i], query(1,0,k,i+1,k)-i*A);
        update(1,0,k,i,i,dp[i]+i*A);
        // vector<int> now;
        // for(int j=0;j<=k;j++){
        //     now.push_back(query(1,0,k,j,j));
        // }
        // debug(now);
    }
    debugarr(dp,k+1);
    cout<<dp[0]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}
/*
20 20 500
1 18 334
0 9 724 
18 0 962
4 9 145
1 12 961
11 7 942
7 2 391
4 14 153
12 6 421
16 2 895
7 3 771
18 1 912
7 0 35
14 5 811
2 3 673
4 5 711
13 1 547
4 6 757
17 1 723
1 17 778
*/