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
    string str; cin>>str;
    int leaves = (1<<(n-1));
    function<pair<int,string>(int,int,int)> segmentTree = [&](int node,int ll, int rr){
        int ret = 0;
        string s =  string(1,str[node-1]);
        if(ll==rr) return make_pair(1ll,s);
        int mid = (ll+rr)>>1;
        auto [l, ls] = segmentTree(2*node,ll,mid);
        auto [r, rs] = segmentTree(2*node+1,mid+1,rr);
        if(ls==rs){
            ret = l * l % mod;
            s.append(ls), s.append(rs);
        }
        else if(ls<rs){
            ret = 2 * l * r % mod;
            s.append(ls), s.append(rs);
        }
        else{
            ret = 2 * l * r % mod;
            s.append(rs), s.append(ls);
        }
        debug(node);
        debug(ret);
        debug(s);
        return make_pair(ret,s);
    };
    cout<<segmentTree(1,1,leaves).F<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}