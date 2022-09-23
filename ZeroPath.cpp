#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/



void codeforce(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> mx(n,vector<int>(m,-1e6));
    vector<vector<int>> mn(n,vector<int>(m,1e6));
    mx[0][0] = mn[0][0] = v[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0){
                mx[i][j] = max(mx[i][j],mx[i-1][j]+v[i][j]);
                mn[i][j] = min(mn[i][j],mn[i-1][j]+v[i][j]);
            }
            if(j-1>=0){
                mx[i][j] = max(mx[i][j],mx[i][j-1]+v[i][j]);
                mn[i][j] = min(mn[i][j],mn[i][j-1]+v[i][j]);
            }
        }
    }
    int x = mn[n-1][m-1];
    int y = mx[n-1][m-1];
    if(x<=0 && y>=0 && (-x)%2==0)Y();
    else N();
}