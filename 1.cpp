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

const int L = 10, N = 2e5 + 5;
int c[L], K[L][N];
set<vector<int>> S;

void code(int TC){
     int n; cin>>n;
     for(int i = 0; i < n; i++){
          cin >> c[i];
          for(int j = 0; j < c[i]; j++) cin >> K[i][j];
     }
     int m; cin >> m;
     for(int j = 0; j < m; j++){
          vector<int> v(n);
          for(int i = 0; i < n; i++) cin >> v[i];
          S.insert(v);
     }   
     vector<pair<int,vector<int>>> C;
     for(int i = max(0ll, c[0] - m - 1); i < c[0]; i++) C.push_back({K[0][i], vector<int> {i + 1}});
     for(int i = 1; i < n; i++){
          priority_queue<pair<int, vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> q;
          for(int j = c[i] - 1; j >= 0; j--){
               int ptr = C.size() - 1;
               while(ptr >= 0 && q.size() < m + 1){
                    auto [sum, v] = C[ptr];
                    v.push_back(j + 1);
                    q.push({sum + K[i][j], v});
                    ptr = ptr - 1;
               }
               while(ptr >= 0 && q.top().ff < C[ptr].ff + K[i][j]){
                    q.pop();
                    auto [sum, v] = C[ptr];
                    v.push_back(j + 1);
                    q.push({sum + K[i][j], v});
                    ptr = ptr - 1;
               }
          }
          C.clear();
          while(!q.empty()) C.push_back(q.top()), q.pop();
     }
     while(!C.empty()){
          if(!S.count(C.back().ss)){
               auto v = C.back().ss;
               for(auto i : v) cout << i << " "; cout << endl;
               break;
          }
          C.pop_back();
     }
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}