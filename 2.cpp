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
    int n; cin >> n;
    vector<int> c(n);
    vector<pair<int,int>> a(n);
    set<pair<int,int>> st;
    for(int i = 0; i < n; i++) cin >> a[i].ff, a[i].ss = i, c[i] = a[i].ff, st.insert({a[i].ff, a[i].ss});
    int k; cin >> k;
    sort(a.begin(), a.end());
    int z = k / a[0].ff;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        st.erase({c[i], i});
        if(k < 0) break;
        if(st.empty()) ans[i] = k / c[i];
        else{
            int x = st.begin() -> ff;
            if(x <= c[i]) continue;
            int l = 0, r = z;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(mid * c[i] + (z - mid) * x <= k) r = mid - 1;
                else l = mid + 1;
            }
            k -= (r + 1) * c[i];
            ans[i] = (r + 1);
            z -= (r + 1);
        }
    }
    for(int i = n - 2; i >= 0; i--) ans[i] += ans[i + 1];
    for(auto i : ans) cout << i << " ";
    cout << endl;
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