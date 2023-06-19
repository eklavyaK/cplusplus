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
    int b[n];
    for(int i=0;i<n;i++) cin>>b[i];
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = (i+1)*(j+1) % n;
        }
    }
    for(int j=0;j<n;j++){
        int add = ((b[j] - ans[j][j]) % n + n);
        for(int i=0;i<n;i++){
            cout<< (ans[i][j] + add) % n <<" ";
        }
        cout<<endl;
    }
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}