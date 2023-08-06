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
#define debugarr(a,n) 42
#define debug(...) 42
#endif





void code(int TC){
     vector<int> v(10);
     for(int i = 1; i < 9; i++) v[i] = rand() % 100;
     debug(v);
     sort(v.begin(),v.end(),greater<>());
     debug(v);
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1; cin >> TT;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}