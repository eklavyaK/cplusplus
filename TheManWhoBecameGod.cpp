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
    int n,k; cin>>n>>k;
    vector<int> sum;
    int last;
    cin>>last;
    for(int i=0;i<n-1;i++){
        int c; cin>>c;
        sum.push_back(abs(last-c));
        last = c;
    }
    sort(sum.begin(),sum.end());
    debug(sum);
    int ans = 0;
    for(int i=n-k-1;i>=0;i--){
        debug(i);
        ans+=sum[i];
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