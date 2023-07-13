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


vector<int> calc(vector<int> a, int n){
    vector<int> L(n);
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().F>a[i]-i) st.pop();
        if(st.empty()){
            L[i] = (a[i]*(a[i]+1))/2;
            if(a[i]-(i+1)>0) L[i]-=(a[i]-(i+1))*(a[i]-i)/2;
        }
        else L[i] = L[st.top().S] + (a[i]*(a[i]+1) - (a[i]-(i-st.top().S))*(a[i]-(i-st.top().S)+1))/2;
        st.push({a[i]-i,i});
    }
    return L;
}


void code(int TC){
    int n; cin>>n;
    vector<int> a(n);
    int all = 0, ans = 0;
    for(int i=0;i<n;i++) cin>>a[i], all+=a[i];
    vector<int> L, R;
    L.insert(L.end(),a.begin(),a.end());
    R.insert(R.end(),a.rbegin(),a.rend());
    L = calc(L,n), R = calc(R,n);
    reverse(R.begin(),R.end());
    debug(L);
    debug(R);
    for(int i=0;i<n;i++) ans = max(L[i]+R[i]-2*a[i],ans);
    cout<<all-ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}