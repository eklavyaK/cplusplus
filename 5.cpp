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
#define debugarr(a, n) 42
#define debug(...) 42
#endif





void code(int TC){
     int n, m; cin >> n >> m;
     vector<string> a(n);
     for(int i = 0; i < n; i++) cin >> a[i];
     vector<vector<int>> p(n, vector<int> (m)), sz(n, vector<int> (m, 1));
     for(int i = 0; i < n; i++){
          iota(p[i].begin(), p[i].end(), i * m);
     }
     function<int(int, int)> getpar = [&](int i, int j){
          if(p[i][j] == i * m + j) return i * m + j;
          return p[i][j] = getpar(p[i][j] / m, p[i][j] % m);
     };
     auto merge = [&](int i, int j, int r, int c){
          int u = getpar(i, j), v = getpar(r, c);
          if(u != v){
               if(sz[u / m][u % m] < sz[v / m][v % m]) swap(u, v);
               p[v / m][v % m] = u, sz[u / m][u % m] += sz[v / m][v % m];
          }
     };
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(i - 1 >= 0 && a[i][j] == '#' && a[i - 1][j] == '#') merge(i, j, i - 1, j);
               if(j - 1 >= 0 && a[i][j] == '#' && a[i][j - 1] == '#') merge(i, j - 1, i, j);
          }
     }
     int ans = 0;
     vector<int> li(n * m, -1), lj(n * m, -1), ri(n * m, -1), rj(n * m, -1);
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(a[i][j] == '.') continue;
               int c = getpar(i, j);
               if(li[c] == -1) li[c] = i;
               ri[c] = i;
          }
     }
     for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
               if(a[j][i] == '.') continue;
               int c = getpar(j, i);
               if(lj[c] == -1) lj[c] = i;;
               rj[c] = i;
          }
     }
     vector<vector<int>> sub(n + 1, vector<int> (m + 1));
     for(int i = 0; i < n * m; i++){
          if(li[i] != -1){
               li[i] -= li[i] != 0;
               ri[i] += ri[i] != n - 1;
               lj[i] -= lj[i] != 0;
               rj[i] += rj[i] != m - 1;
               sub[li[i]][lj[i]] += sz[i / m][i % m];
               sub[li[i]][rj[i] + 1] -= sz[i / m][i % m];
               sub[ri[i] + 1][lj[i]] -= sz[i / m][i % m];
               sub[ri[i] + 1][rj[i] + 1] += sz[i / m][i % m];
          }
     }
     for(int i = 0; i <= n; i++){
          int cur = 0;
          for(int j = 0; j <= m; j++){
               cur += sub[i][j];
               sub[i][j] = cur + (i == 0 ? 0: sub[i - 1][j]);
          }
     }
     vector<int> col(m);
     for(int i = 0; i < m; i++){
          vector<int> cur;
          int more = 0;
          for(int j = 0; j < n; j++){
               if(a[j][i] == '.') more += 1;
               if(i - 1 >= 0 && a[j][i - 1] == '#') cur.push_back(getpar(j, i - 1));
               if(i + 1 < m && a[j][i + 1] == '#') cur.push_back(getpar(j, i + 1));
               if(a[j][i] == '#') cur.push_back(getpar(j, i));
          }
          sort(cur.begin(), cur.end());
          for(int j = 0; j < cur.size(); j++){
               while(j + 1 < cur.size() && cur[j + 1] == cur[j]) j += 1;
               more += sz[cur[j] / m][cur[j] % m];
          }
          col[i] = more;
     }
     for(int i = 0; i < n; i++){
          vector<int> cur;
          int more = 0;
          for(int j = 0; j < m; j++){
               if(a[i][j] == '.') more += 1;
               if(i - 1 >= 0 && a[i - 1][j] == '#') cur.push_back(getpar(i - 1, j));
               if(i + 1 < n && a[i + 1][j] == '#') cur.push_back(getpar(i + 1, j));
               if(a[i][j] == '#') cur.push_back(getpar(i, j));
          }
          sort(cur.begin(), cur.end());
          for(int j = 0; j < cur.size(); j++){
               while(j + 1 < cur.size() && cur[j + 1] == cur[j]) j += 1;
               more += sz[cur[j] / m][cur[j] % m];
          }
          for(int j = 0; j < m; j++){
               ans = max(ans, more - sub[i][j] + col[j] - (a[i][j] == '.'));
          }
     }
     cout << ans << endl;
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);cerr.tie(0);
     cout.precision(30);
     int TT = 1; cin >> TT;
     for (int TC = 1; TC <= TT; TC++) 
          code(TC);
     return 0;
}