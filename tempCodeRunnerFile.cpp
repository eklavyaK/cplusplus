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
    vector<int> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++)cin>>arr[i],sum+=arr[i];
    if(sum&1){
        cout<<"NO"<<endl;
        return;
    }
    bool f = false;
    function<bool(int)> check = [&](int r){
        int rem = arr[0] - r;
        vector<int> curr = arr;
        curr[0] = r;
        for(int i=1;i<n;i++){
            if(curr[i]<curr[i-1]) return false;
            curr[i] -= curr[i-1];
        }
        if(curr[n-1]==rem) f = true;
        return curr[n-1]<=rem;
    };
    int l = 0, r = arr[0];
    while(l<=r){
        int mid = (l+r)>>1;
        debug(mid);
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    cout<<(f?"YES":"NO")<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}