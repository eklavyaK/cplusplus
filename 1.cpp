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


const int N = 2e5 + 5;
int S[N], I[N], P[N];

void code(int TC){
     int n; cin >> n;
     for(int u = 2; u <= n; u++){
          int v; cin >> v;
          P[u] = v;
          I[u]++, I[v]++;
     }
     queue<int> q;
     for(int u = 1; u <= n; u++) if(I[u] == 1) q.push(u);
     while(!q.empty()){
          int u = q.front(); q.pop();
          I[P[u]]--, S[P[u]] += S[u] + 1;
          if(I[P[u]] == 1 && P[u] != 1) q.push(P[u]);
     }
     for(int u = 1; u <= n; u++) cout << S[u] << " ";
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}