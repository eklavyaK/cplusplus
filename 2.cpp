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
    int n, m, t;
    string r;
    cin >> n >> m >> t >> r;
    vector<string> s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    vector<int> x(t), y(t), l(t), I(t);
    for(int i = 0; i < t; i++){
        cin >> I[i] >> x[i] >> l[i] >> y[i];
        x[i]--;
        y[i]--;
        I[i]--;
    }
    set<int> st;
    for(int i = 0; i < n; i++) st.insert(i);
    for(int i = t - 1; i >= 0; i--){
        int id = x[i];
        auto it = st.lower_bound(y[i]);
        int fid = y[i] + l[i] - 1;
        if(it == st.end()) continue;
        id += (*it) - y[i];
        while(it != st.end()){
            auto itn = it;
            itn++;
            if(*it <= fid){
                r[*it] = s[I[i]][id];

            }
            else break;
            id += (*itn) - (*it);
            st.erase(*it);
            it = itn;
        }
        debug(r);
    }
    cout << r << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    cout.precision(30);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}