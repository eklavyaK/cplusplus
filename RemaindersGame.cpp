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
    int n,k; cin>>n>>k;
    int c[n];
    for(int i=0;i<n;i++) cin>>c[i];
    map<int,int> fac;
    for(int i=2;i*i<=k;i++){
        while(k%i==0) fac[i]++,k/=i;
    }
    if(k>1) fac[k]++;
    for(auto [f,num] : fac){
        num = pow(f,num);
        bool ok = false;
        for(int i=0;i<n;i++){
            if(c[i]%num==0) ok = true;
        }
        if(!ok){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}