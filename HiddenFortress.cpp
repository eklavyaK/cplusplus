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

int C = 1e9;
int query(int x, int y){
    cout<<'?'<<' '<<x<<' '<<y<<endl<<flush;
    cin>>x; return x;
}

void code(int TC){
    int x = query(1,(query(1,1)+C-query(1,C))/2);
    int y = query((query(1,1)+C-query(C,1))/2,1);
    int p = query(C,(query(C,1)+C-query(C,C))/2);
    int q = query((query(1,C)+C-query(C,C))/2,C);
    cout<<'!'<<' '<<x+1<<' '<<y+1<<' '<<C-p<<' '<<C-q<<endl<<flush;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}