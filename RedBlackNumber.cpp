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
#define debugarr(a,n)
#define debug(...)
#endif

const int N = 42, M = 10;
int R[M][N][N], dp[N][N][N][N][2], S[N], F[2], n, A, B;
string s;
void calc(){
    for(int i=1;i<M;i++){
        for(int k=1;k<N;k++){
            int cur = i;
            for(int j=0;j<N;j++){
                R[i][j][k] = cur % k;
                cur = cur * 10 % k;
            }   
        }
    }
}
void construct(int p, int r, int a, int b){
    if(p==n) return;
    assert(n-p-r>=0);
    bool c = dp[r][n-p-r][a][b][0];
    int next = dp[r][n-p-r][a][b][1];
    if(c) b = next;
    else a = next;
    construct(p+1,r-(c^1),a,b);
    s[p] = c?'B':'R';
}
void code(int TC){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<2;k++){
                for(int u=0;u<N;u++){
                    for(int v=0;v<N;v++) dp[i][j][u][v][k] = -1;
                }
            }
        }
    }
    cin>>n>>A>>B>>s;
    for(int i=0;i<n;i++) S[i] = s[i]-'0';
    for(int i=n-1;i>=0;i--){
        for(int red=1;red<n-i;red++){
            int blue = n-i-red;
            for(int u=0;u<A;u++){
                for(int v=0;v<B;v++){
                    if(dp[red-1][blue][u][v][0]!=-1){
                        dp[red][blue][(u+R[S[i]][red-1][A]) % A][v][0] = 0;
                        dp[red][blue][(u+R[S[i]][red-1][A]) % A][v][1] = u;
                    }
                    if(dp[red][blue-1][u][v][0]!=-1){
                        dp[red][blue][u][(v+R[S[i]][blue-1][B]) % B][0] = 1;
                        dp[red][blue][u][(v+R[S[i]][blue-1][B]) % B][1] = v;
                    }
                }
            }
        }
        dp[n-i][0][(F[0]*(i!=n-1) + R[S[i]][n-1-i][A]) % A][0][0] = 0;
        dp[n-i][0][(F[0]*(i!=n-1) + R[S[i]][n-1-i][A]) % A][0][1] = F[0];
        dp[0][n-i][0][(F[1]*(i!=n-1) + R[S[i]][n-1-i][B]) % B][0] = 1;
        dp[0][n-i][0][(F[1]*(i!=n-1) + R[S[i]][n-1-i][B]) % B][1] = F[1];
        F[0] = (F[0]*(i!=n-1) + R[S[i]][n-1-i][A]) % A;
        F[1] = (F[1]*(i!=n-1) + R[S[i]][n-1-i][B]) % B;
    }
    int d = n, r = 0;
    for(int i=1;i<n;i++){
        if(dp[i][n-i][0][0][0]!=-1 && abs(2*i-n)<d){
            d = abs(2*i-n), r = i;
            debug(i);
        }
    }
    debug(d,r);
    if(d==n){
        cout<<-1<<endl;
        return;
    }
    construct(0,r,0,0);
    cout<<s<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT; calc();
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}