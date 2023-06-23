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





void code(int TC){
    int n; cin>>n;
    string s; cin>>s;
    int pref[n]{}, c[n]{};
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        pref[i] = pref[i-1*(i!=0)] + (s[i]=='-');
        v[i] = {2*pref[i]-i,i};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) c[v[i].S] = i;
    vector<vector<int>> tree(3,vector<int>(4*n+5));
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int x, int id){
        if(l==r){ 
            tree[id][node] = 1;
            return;
        }
        int mid = (l+r)>>1;
        if(x<=mid) update(2*node, l, mid, x, id);
        else update(2*node+1, mid+1, r, x, id);
        tree[id][node] = tree[id][2*node] + tree[id][2*node+1];
    };
    function<int(int,int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en, int id){
        if(st>r || en<l || en<st) return 0ll;
        if(st<=l && en>=r) return tree[id][node];
        int mid = (l+r)>>1;
        return query(2*node,l,mid,st,en,id) + query(2*node+1,mid+1,r,st,en,id);
    };
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=query(1,0,n-1,0,c[i]-1,((2*pref[i]-i)%3+3)%3);
        if(((2*pref[i]-(i+1))%3+3)%3==0 && 2*pref[i]-(i+1)>=0) ans++;
        update(1,0,n-1,c[i],((2*pref[i]-i)%3+3)%3);
        debug(ans);
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}