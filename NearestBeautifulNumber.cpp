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
#define debugarr(a,n)
#define debug(...)
#endif



void code(int TC){
    string s; int k; cin>>s>>k;
    int n = s.size(), f[10]{};
    set<int> st;
    int last = 0;
    for(int i=0;i<n && k>0;i++){
        int d = s[i]-'0';
        if(!f[d]){
            f[d] = 1;
            st.insert(d);
            k--;
            last = d;
        }
    }
    if(k){
        cout<<s<<endl;
        return;
    }
    function<int(set<int>)> calc = [&](set<int> st){
        int r[n], f = n;
        debug(st);
        for(int i=0;i<n;i++){
            int d = s[i]-'0';
            auto it = st.lower_bound(d);
            if(it==st.end()){
                bool k = 1;
                for(int j=i-1;j>=0;j--){
                    if(s[j]-'0'!=*st.rbegin()){
                        r[j] = *st.upper_bound(s[j]-'0');
                        f = j+1; k = 0; break;
                    }
                }
                if(k) return 0ll;
            }
            else if(*it==d) r[i] = d;
            else r[i] = *it, f = i+1;
            if(f!=n) break;
        }
        int mn = *st.begin(), ret = 0, cur = 1;
        set<int> count;
        for(int i=0;i<f;i++){
            if(!count.count(s[i]-'0')) count.insert(s[i]-'0');
        }
        if(count.size()<st.size()) mn = 0;
        for(int i=f;i<n;i++) r[i] = mn;
        for(int i=n-1;i>=0;i--){
            ret += cur * r[i];
            cur *= 10;
        }
        return ret;
    };
    int ans = 1e10;
    set<int> rem = st;
    rem.erase(last);
    st = rem;
    for(int i=0;i<10;i++){
        if(!rem.count(i)){
            st.insert(i);
        }
        int a = calc(st);
        if(a) ans = min(ans,a);
        if(!rem.count(i)){
            st.erase(i);
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