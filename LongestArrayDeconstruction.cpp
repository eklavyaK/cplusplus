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
#define debugarr(a,n)
#define debug(...)
#endif


const int N = 200005;
int tree[N*4];
vector<int> v[N];
void update(int node, int l, int r, int p, int v){
    if(l==r){
        tree[node] = v;
        return;
    }
    int mid = (l+r)>>1;
    if(p<=mid) update(2*node,l,mid,p,v);
    else update(2*node+1,mid+1,r,p,v);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(en<st || r<st || en<l) return 0;
    if(st<=l && en>=r) return tree[node];
    int mid = (l+r)>>1;
    return max(query(2*node, l, mid, st, en), query(2*node+1, mid+1, r, st, en));
}
void code(int TC){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        if(i-k>=0) v[k].push_back(i-k);
    }
    int ans = 0;
    for(int i=N-5;i>=1;i--){
        for(int j=0;j<v[i].size();j++){
            int q = query(1, 0, N-5, v[i][j], N-5);
            update(1, 0, N-5, v[i][j], q + 1);
            ans = max(ans, q + 1);
        }
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