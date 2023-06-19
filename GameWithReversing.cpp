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
    string a, b; cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    string bb = b;
    reverse(b.begin(),b.end());
    int l = 0, r = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=bb[i]) l++;
        if(b[i]!=a[i]) r++;
    }
    l = max(l,1ll);
    r = max(r,1ll);
    cout<<min(2*l-1+((l+1)&1),2*r-1+(r&1))<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}