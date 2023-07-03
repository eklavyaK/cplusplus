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

const int N = 1005;
int P[N][N], S[1000005][2][2], L[N][N], n, m, q, cur, l, r, T;
set<int> I[N+N];
void add(int stair, int pos){
    auto it = I[stair].upper_bound(pos);
    r = *it, it--, l = *it;
    T -= (pos-l+1)*(pos-l+2)/2;
    T -= (r-pos+1)*(r-pos+2)/2;
    T += (r-l+1)*(r-l+2)/2 + 1;
    I[stair].insert(pos);
}
void remove(int stair, int pos){
    auto it = I[stair].upper_bound(pos);
    r = *it, it--, it--, l = *it;
    T += (pos-l+1)*(pos-l+2)/2;
    T += (r-pos+1)*(r-pos+2)/2;
    T -= (r-l+1)*(r-l+2)/2 + 1;
    I[stair].erase(pos);
}
void free(int u, int v){
    int stair_0 = S[P[u][v]][0][0];
    int stair_1 = S[P[u][v]][1][0];
    if(stair_0) add(stair_0,S[P[u][v]][0][1]);
    if(stair_1) add(stair_1,S[P[u][v]][1][1]);
}
void lock(int u, int v){
    int stair_0 = S[P[u][v]][0][0];
    int stair_1 = S[P[u][v]][1][0];
    if(stair_0) remove(stair_0,S[P[u][v]][0][1]);
    if(stair_1) remove(stair_1,S[P[u][v]][1][1]);
}
void code(int TC){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            P[i][j] = ++cur;
        }
    }
    cur = 0;
    for(int i=1;i<=m;i++){
        I[++cur].insert(0);
        int u = 1, v = i, f = 0, p = 0;
        while(u<=n && v<=m){
            S[P[u][v]][0][0] = cur;
            S[P[u][v]][0][1] = ++p;
            u += f, v += f^1, f^=1;
        }
        I[cur].insert(++p);
        T += (u+v-i-1) * (u+v-i) / 2;
    }
    for(int i=1;i<=n;i++){
        I[++cur].insert(0);
        int u = i, v = 1, f = 1, p = 0;
        while(u<=n && v<=m){
            S[P[u][v]][1][0] = cur;
            S[P[u][v]][1][1] = ++p;
            u += f, v += f^1, f^=1;
        }
        I[cur].insert(++p);
        T += (u+v-i-1) * (u+v-i) / 2;
    }
    debug(T);
    while(q--){
        int u, v; cin>>u>>v;
        L[u][v]?add(u,v):remove(u,v), L[u][v]^=1;
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