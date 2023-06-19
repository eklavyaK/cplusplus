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
    int a = 0, b= 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(k==-1) b++;
        else a++;
    }
    int ans = 0, now = b;
    for(int i=0;i<now;i++){
        if(b&1) b--,a++,ans++;
        else if(b>a) b--,a++, ans++;
        else break;
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