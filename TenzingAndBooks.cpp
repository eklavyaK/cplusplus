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
    int n, x; cin>>n>>x;
    int curr = 0;
    for(int i=0;i<3;i++){
        bool f = true;
        for(int j=0;j<n;j++){
            int  k; cin>>k;
            if(!f) continue;
            if((k|x)==x) curr = curr|k;
            else f = false;
        }
    }
    if(curr==x) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}