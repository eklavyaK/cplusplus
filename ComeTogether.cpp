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
    int x[3],y[3];
    for(int i=0;i<3;i++) cin>>x[i]>>y[i];
    int ans = 0;
    if((y[1]>=y[0] && y[2]>=y[0]) || (y[1]<=y[0] &&  y[2]<=y[0])){
        if((x[0]<=x[1] && x[0]<=x[2]) || (x[0]>=x[1] && x[0]>=x[2])){
            ans = min(abs(x[0]-x[1]),abs(x[0]-x[2])) + min(abs(y[0]-y[1]),abs(y[0]-y[2]));
        }
        else{
            ans = min(abs(y[0]-y[1]),abs(y[0]-y[2]));
        }
    }
    else{
        if((x[0]<=x[1] && x[0]<=x[2]) || (x[0]>=x[1] && x[0]>=x[2])){
            ans = min(abs(x[0]-x[1]),abs(x[0]-x[2]));
        }
    }
    cout<<ans+1<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}