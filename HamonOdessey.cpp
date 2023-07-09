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
    int n; cin>>n;
    int arr[n];
    int mx = (1ll<<60);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx = arr[i]&mx;
    }
    int rev[n+1]{};
    int fw[n+1]{};
    rev[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        rev[i] = rev[i+1]&arr[i];
    }
    fw[0] = arr[0];
    for(int i=1;i<n;i++){
        fw[i] = fw[i-1]&arr[i];
    }
    int cur = -1, ans = 0, sum = 0;
    for(int i=0;i<n;i++){
        ans++;
        int cur = arr[i];
        if(cur+sum+rev[i+1]==mx){
            continue;
        }
        while(i+1<n){
            i++;
            cur = cur&arr[i];
            if(cur+sum+rev[i+1]==mx){
                break;
            }
        }
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}