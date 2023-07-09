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





void code(int TC){
    int x,y,a,b; cin>>x>>y>>a>>b;
    if(a<b) swap(a,b);
    if(x>y) swap(x,y);
    function<bool(int)> check = [&](int m){
        if(m*b>x) return false;
        int l = 0, r = m;
        while(l<=r){
            int mid = (l+r)>>1;
            if(x-mid*a>0 && b*(m-mid)<=x-mid*a) l = mid+1;
            else r = mid-1;
        }
        return (l-1)*b + (m-l+1)*a<=y;
    };
    int l = 0, r = 1e9;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    cout<<l-1<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}