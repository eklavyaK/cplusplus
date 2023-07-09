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
#define deg(...)
#endif

const int N = 1005;
int P[N][N], L[N][N], n, m, q, cur, l, r, T;
vector<pair<int,int>> S[N*N];
set<int> I[N+N];
void add(int stair, int pos){
    auto it = I[stair].upper_bound(pos);
    r = *it-1, it--, l = *it+1;
    T -= (pos-l) * (r-pos) + (r-l);
    I[stair].insert(pos);
}
void remove(int stair, int pos){
    auto it = I[stair].upper_bound(pos);
    r = *it-1, it--, it--, l = *it+1;
    T += (pos-l) * (r-pos) + (r-l);
    I[stair].erase(pos);
}
void code(int TC){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            P[i][j] = ++cur;
        }
    }
    cur = 0;
    for(int i=1;i<m;i++){
        I[++cur].insert(0);
        int u = 1, v = i, f = 0, p = 0;
        while(u<=n && v<=m){
            S[P[u][v]].push_back({cur,++p});
            u += f, v += f^1, f^=1;
        }
        T += p * (p-1) / 2;
        I[cur].insert(++p);
    }
    for(int i=1;i<n;i++){
        I[++cur].insert(0);
        int u = i, v = 1, f = 1, p = 0;
        while(u<=n && v<=m){
            S[P[u][v]].push_back({cur,++p});
            u += f, v += f^1, f^=1;
        }
        T += p * (p-1) / 2;
        I[cur].insert(++p);
    }
    T += n*m;
    while(q--){
        int u, v; cin>>u>>v;
        debug(L[u][v]);
        for(auto [s,p] : S[P[u][v]]) L[u][v]?remove(s,p):add(s,p);
        L[u][v]?T++:T--;
        L[u][v]^=1;
        cout<<T<<endl;
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