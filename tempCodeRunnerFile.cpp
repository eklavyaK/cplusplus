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
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n;i++){
        if(i % 3 ==0 && (n-1-i) % 3 == 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    for(int j=0;j<26;j++){
        int f = -1;
        for(int i=0;i<n;i++){
            if(f==-1){
                if(s[i]-'a'==j && i % 3 == 0) f = i;
            }
            else{
                if((n-1-i) % 3 != 0) continue;
                if((i-f-1) % 3 == 0){
                    cout<<"YES"<<endl;
                    return;
                }
                else if((i-f-1) >= 1 && (i-f-1) % 3 == 1){
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
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