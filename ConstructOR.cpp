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
    int a,b,d; cin>>a>>b>>d;
    int x = a|b, lsx = -1, lsd = -1;
    for(int i=0;i<31;i++){
        if(lsx==-1 && ((1<<i)&x)) lsx = i;
        if(lsd==-1 && ((1<<i)&d)) lsd = i;
    }
    if(lsd>lsx){
        cout<<-1<<endl;
        return;
    }
    int ans = d;
    for(int i=0;i<30;i++){
        if(((1<<i)&x) && !((1<<i)&ans)) ans += (d<<(i-lsd));
    }
    cout<<ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cerr.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}