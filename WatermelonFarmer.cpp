#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,w,mod,x,y;
    cin>>n>>m>>w>>mod>>x>>y;
    function<vector<vector<int>>(vector<vector<int>>, vector<vector<int>>, int, int, int)> mm = [&](vector<vector<int>> a, vector<vector<int>> b, int n, int c, int m){
        vector<vector<int>> ret(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = 0;
                for(int k = 0; k<c; k++){
                    curr += a[i][k]*b[k][j];
                }
                ret[i][j] = curr%mod;
            }
        }
        return ret;
    };
    function<vector<vector<int>>(vector<vector<int>>, int ,int)> exp = [&](vector<vector<int>> a, int n, int k){
        vector<vector<int>> res(n,vector<int>(n));
        for(int i=0;i<n;i++) res[i][i] = 1;
        while(k>0){
            if(k&1) res = mm(res,a,n,n,n);
            a = mm(a,a,n,n,n);
            k>>=1;
        }
        return res;
    };
    vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(m)),c(m,vector<int>(m));
    b[0][0] = x, b[n-1][m-1] = y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(abs(i-j)<=1)a[i][j]=1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++) if(abs(i-j)<=1)c[i][j]=1;
    }
    auto ans = mm(mm(exp(a,n,w),b,n,n,m),exp(c,m,w),n,m,m);
    for(auto i : ans) {for(auto j : i) cout<<j<<' '; cout<<endl;}
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}