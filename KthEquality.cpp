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
    int a,b,c,k; cin>>a>>b>>c>>k;
    int mx1 = pow(10,a)-1;
    int mx2 = pow(10,b)-1;
    int mx3 = pow(10,c)-1;
    int mn1 = pow(10,a-1);
    int mn2 = pow(10,b-1);
    int mn3 = pow(10,c-1);
    if(mn1+mn2>mx3 || mx2+mx1<mn3){
        cout<<-1<<endl;
        return;
    }
    for(int i=mn1;i<=mx1;i++){
        if(k<0) break;
        a = i;
        if(mx2+a<mn3) continue;
        b = max(mn2,mn3-a);
        int mx = min(mx3-a,mx2);
        debug(a);
        debug(b);
        debug(mx);
        k--;
        if(b>mx)break;
        if(k<=mx-b){
            b = b+k;
            cout<<a<<" + "<<b<<" = "<<a+b<<endl;
            return;
        }
        else k-=(mx-b);
    }
    cout<<-1<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}