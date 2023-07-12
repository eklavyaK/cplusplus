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
    int c[4][4];
    memset(c,0,sizeof(c));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            // for(int k=0;k<5;k++){
                // cout<<i<<j<<k<<' '<<(i+j+k)%4<<endl;
                c[(i+j)%4][i]++;
                c[(i+j)%4][j]++;
            // }
        }
    }
    debug(c[0][0])  ;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}