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
    string s; cin>>s;
    int n = s.size();
    vector<stack<int>> v(10);
    for(int i=0;i<n;i++){
        v[s[i]-'0'].push(i);
    }
    int last = n;
    int m; cin>>m;
    string l,r; cin>>l>>r;
    for(int i=m-1;i>=0;i--){
        int st = l[i]-'0';
        int en = r[i]-'0';
        int mn = n;
        for(int j=st;j<=en;j++){
            while(!v[j].empty() && v[j].top()>=last) v[j].pop();
            if(v[j].empty()){
                cout<<"YES"<<endl;
                return;
            }
            mn = min(v[j].top(),mn);
        }
        last = mn;
    }
    cout<<"NO"<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}