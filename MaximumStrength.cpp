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
    string a, b; cin>>a>>b;
    if(a.size()<b.size()) swap(a,b);
    int diff = a.size()-b.size();
    if(diff){
        b = string(diff,'0') + b;
    }
    int n = a.size(), ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            ans = abs(a[i]-b[i]) + (n-1-i)*9;
            break;
        }
    }
    cout<<ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}