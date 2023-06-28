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





const int N = 3e5;
int tree[N*4], lazy[N*4], dp[N], sum[N];
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
    int n,q; cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>dp[i];
        update(1,0,n-1,i,i,dp[i]);
    }
    
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l,r,c; cin>>l>>r>>c;
            update(1,0,n-1,l,r,c);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl<<flush;
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}