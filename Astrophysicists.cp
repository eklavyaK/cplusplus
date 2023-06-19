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
    int n,k,g; cin>>n>>k>>g;
    int l = ceil((ld)g/2)-1;
    if(n*l>=k*g){
        cout<<k*g<<endl;
        return;
    }
    int last = k*g-(n-1)*l;
    int r = last%g;
    if(r>=l+1){
        cout<<k*g-last-g+r<<endl;
    }
    else cout<<k*g-last+r<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}