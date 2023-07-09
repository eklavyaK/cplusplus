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


int a[300][300];


void code(int TC){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int rev[n];
    int done[300]{};
    rev[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        rev[i] = arr[i]^rev[i+1];
    }
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        ans = max(ans,rev[i]);
        for(int j=0;j<300;j++){
            if(done[j]){
                ans = max(ans,rev[i]^j);
            }
        }
        done[rev[i]] = 1;
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    for(int i=0;i<300;i++){
        for(int j=0;j<300;j++){
            a[i][j] = i^j;
        }
    }
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}