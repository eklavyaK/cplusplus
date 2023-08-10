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

struct Node{
     int x, y, w, z;
};
const int N = 5e6 + 5;
vector<pair<int,int>> C[N];
vector<int> a(200000);

Node check(vector<int> v, int n){
     for(int i = 0; i < n - 1; i++){
          for(int j = i + 1; j < n; j++){
               for(int k = 0; k < n - 1; k++){
                    if(k == i || k == j) continue;
                    for(int l = k + 1; l < n; l++){
                         if(l == i || l == j) continue;
                         if(a[v[i]] + a[v[j]] == a[v[k]] + a[v[l]]){
                              return Node{v[i] + 1, v[j] + 1, v[k] + 1, v[l] + 1};
                         }
                    }
               }
          }
     }
     return Node{0, 0, 0, 0};
}

void code(int TC){
     int n; cin >> n;
     for(int i = 0; i < n; i++) cin >> a[i];
     for(int i = 0; i < n - 1; i++){
          for(int j = i + 1; j < n; j++){
               C[a[i] + a[j]].push_back({i, j});
               if(C[a[i] + a[j]].size() > 1){
                    set<int> f;
                    vector<int> V;
                    for(auto [u, v] : C[a[i] + a[j]]){
                         if(!f.count(u)) f.insert(u), V.push_back(u);
                         if(!f.count(v)) f.insert(v), V.push_back(v);
                    }
                    if(V.size() > 3){
                         auto [x, y, w, z] = check(V, (int) V.size());
                         if(x){
                              cout << "YES" << endl;
                              cout << x << " " << y << " " << w << " " << z << endl;
                              return;
                         }
                    }
               }
          }
     }
     cout << "NO" << endl;
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}