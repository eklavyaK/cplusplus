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


int query(int i, int j){
    cout<<"? "<<i<<" "<<j<<endl<<flush;
    cin>>i; return i;
}

pair<int,int> run_double(int i, int j, int n){
    for(int k=j+1;k<=n;k++){
        int a = query(i,k);
        int b = query(j,k);
        if(a>b) return run_double(i,k,n);   
        else if(a<b) return run_double(j,k,n);
    }
    return {i,j};
}

void code(int TC){
    int n; cin>>n;
    auto [i,j] = run_double(1,2,n);
    cout<<"! "<<i<<' '<<j<<endl<<flush;
    cin>>n;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}