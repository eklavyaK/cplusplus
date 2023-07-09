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
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> ans(n,vector<int>(m));
    bool a[n][m], f = 0;
    memset(a,0,sizeof(a));
    if(n & 1){
        if(k < m/2){
            cout<<"NO"<<endl;
            return;
        }
        else k -= m/2, f = 1;
        for(int i=0;i<m;i+=2) ans[0][i] = ans[0][i+1] = 97 + (i/2) % 26, a[0][i] = a[0][i] = 1;
    }
    if(k & 1){
        cout<<"NO"<<endl;
        return;
    }
    function<int(bool, int, int)> find = [&](int h, int i, int j){
        set<char> s;
        if(h){
            if(i-1>=0) s.insert(ans[i-1][j]), s.insert(ans[i-1][j+1]);
            if(j-1>=0) s.insert(ans[i][j-1]);
        }
        else{
            if(j-1>=0) s.insert(ans[i][j-1]), s.insert(ans[i+1][j-1]);
            if(i-1>=0) s.insert(ans[i-1][j]);
        }
        for(int c=97;c<=122;c++) if(!s.count(c)) return c;
        return 97ll;
    };
    for(int j=0;j<m && k>0;j+=2){
        if(j==m-1){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=f;i<n && k>0;i++){
            ans[i][j] = ans[i][j+1] = find(1,i,j);
            k--;
        }
    }
    for(int j=0;j<m;j++){
        for(int i=f;i<n;i+=2){
            if(!ans[i][j]) ans[i][j] = ans[i+1][j] = find(0,i,j);
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<(char)ans[i][j];
        }
        cout<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}