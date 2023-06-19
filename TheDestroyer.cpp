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
    int arr[105]{};
    for(int i=0;i<n;i++){
        int k;cin>>k;
        arr[k]++;
    }
    for(int i=0;i<102;i++){
        if(arr[i]<arr[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}