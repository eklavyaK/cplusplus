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
/*
The main idea behind centroid decomposition is to recursively decompose a given tree into subtrees in such a way that each subtree's size is roughly half of the original tree.

APPROACH:
     To find the centroid of a subtree S:
          run a dfs considering one vertex as root, simultaneously store the size of subtree at each node
          first candidate for centroid is root
          now check whether root has a child whose subtree size > size(S)/2
          if such child exists then that is new centroid candidate
          repeat the steps till you find centroid (centroid will always exist for a tree)
          don't check the vertices which were old centroid candidates, because they've been proven as not centroid
     
     After centroid is found for a subtree mark the centroid
     Now find the centroid of each child's subtree of the current centroid, those centroids will be children of current centroid
     By repeating this process recursively we finally get the centroid tree

COMPLEXITY: O(n * log(n))
*/
vector<int> centroidDecomposition(vector<vector<int>> T, int n){
     vector<int> I(n+5), sz(n+5), P(n+5);
     function<void(int,int)> dfs = [&](int u, int p){
          sz[u] = 1;
          for(auto v : T[u]) if(!I[v] && v != p) dfs(v, u), sz[u] += sz[v];
     };
     function<void(int,int)> decompose = [&](int u, int anc){
          dfs(u, 0);
          int ctr = u, p = 0;
          while(int f = 1){
               for(auto v : T[ctr]) if(!I[v] && 2 * sz[v] > sz[u] && v != p){
                    p = ctr, ctr = v, f = 0; break;
               }
               if(f) break;
          }
          I[ctr] = 1, P[ctr] = anc;
          for(auto u : T[ctr]) if(!I[u]) decompose(u,ctr);
     };
     decompose(1,0);
     return P;   //returns parent info of the centroid tree, 0 for root
}


void code(int TC){
     int n, C = 0, k1,k2; cin>>n>>k1>>k2;
     vector<vector<int>> T(n+5);
     for(int i=0;i<n-1;i++){
          int u,v; cin>>u>>v;
          T[u].push_back(v), T[v].push_back(u);
     }
     auto P = centroidDecomposition(T,n);
     for(int i=1;i<=n;i++) cout<<P[i]<<" ";
     cout<<endl;
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     int TT = 1;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}