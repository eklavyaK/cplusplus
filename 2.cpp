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



set<char> st;

void code(int TC){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');
    int ans = 1, cnt = 0, mod = 1e9+7;
    for(int i=0;i<n;i++){
        if(st.count(s[i]))cnt++;
        int l = i;
        if(cnt==k){
            while(i+1<n && (!st.count(s[i+1])))i++;
            if(i!=n-1) ans = (ans*(i-l+1))%mod;
            cnt = 0;
        }
    }
    cout<<ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}