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
    int arr[n];
    int done[2*n+5]{};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<2*n+5) done[arr[i]] = 1;
    }
    set<int> st;
    st.insert(arr[0]);
    for(int i=0;i<n;i++){
        set<int> next;
        if(arr[i]<2*n+5) st.insert(arr[i]);
        for(auto j : st){
            int lc = j*arr[i]/gcd(j,arr[i]);
            if(lc>2*n+5) continue;
            done[lc] = 1;
            next.insert(lc);
        }
        st = next;
    }
    for(int i=1;i<2*n+5;i++){
        if(!done[i]){
            cout<<i<<endl;
            break;
        }
    }
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}