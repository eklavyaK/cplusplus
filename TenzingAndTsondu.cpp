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
    int n,m; cin>>n>>m;
    int sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        sum1+=k;
    }
    for(int i=0;i<m;i++){
        int k; cin>>k;
        sum2+=k;
    }
    if(sum1==sum2){
        cout<<"Draw"<<endl;
    }
    else if(sum1>sum2){
        cout<<"Tsondu"<<endl;
    }
    else{
        cout<<"Tenzing"<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}