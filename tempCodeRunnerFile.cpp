#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif





void code(int TC){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int u = 0, v = 0, c = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[0]) c += 1;
        if(c == k){
            u = i;
            break;
        }
    }
    c = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == a[n - 1]) c += 1;
        if(c == k){
            v = i;
            break;
        }
    }
    if(a[0] == a[n - 1]){
        c = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == a[0]) c+=1;
        }
        if(c >= k){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        return;
    }
    if(v > u) cout << "YES" << endl;
    else cout << "NO" << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    cout.precision(30);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}