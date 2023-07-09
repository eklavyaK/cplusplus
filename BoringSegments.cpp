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
#define debug(...)  42
#endif


const int N = 4e5, M = 2e6+2e5;
int tree[M*4], lazy[M*4];
void pushdown(int node){
    lazy[2*node] += lazy[node];
    tree[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    tree[2*node+1] += lazy[node];
    lazy[node] = 0;
}
void update(int node, int l, int r, int st, int en, int c){
    if(en<st || l>en || r<st) return;
    if(st<=l && en>=r){
        tree[node] += c, lazy[node] += c;
        return;
    }
    pushdown(node);
    int mid = (l+r)>>1;
    update(2*node, l, mid, st, en, c);
    update(2*node+1, mid+1, r, st, en, c);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(en<st || l>en || r<st) return LLONG_MAX;
    if(st<=l && en>=r) return tree[node];
    pushdown(node);
    int mid = (l+r)>>1;
    return min(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}

void code(int TC){
    int n, m; cin>>n>>m; m<<=1;
    vector<pair<int,int>> seg(n);
    vector<pair<int,int>> wgt(n);
    for(int i=0;i<n;i++){
        int l, r, w; cin>>l>>r>>w;
        l<<=1; r<<=1;
        seg[i] = {l,r};
        wgt[i] = {w,i};
    }
    sort(wgt.begin(),wgt.end());
    int ans = wgt[n-1].F-wgt[0].F, pos = 0;
    for(int i=0;i<n;i++){
        auto [wg, p] = wgt[i];
        auto [l,r] = seg[p];
        update(1,2,m,l,r,1);
        while(pos<i && tree[1]>0){
            auto [w,np] = wgt[pos];
            auto [nl,nr] = seg[np];
            if(query(1,2,m,nl,nr)>1){
                update(1,2,m,nl,nr,-1);
                pos++;
            }
            else break;
        }
        if(tree[1]>0) ans = min(ans,wg-wgt[pos].F), debug(ans);
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}