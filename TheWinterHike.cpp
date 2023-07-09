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
    int arr[2*n][2*n];
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++) cin>>arr[i][j];
    }
    int ans = 0;
    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++) ans += arr[i][j];
    }
    cout<<ans + min({arr[n][0],arr[0][n],arr[2*n-1][0],arr[0][2*n-1],arr[n-1][n],arr[n][n-1],arr[2*n-1][n-1],arr[n-1][2*n-1]})<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}