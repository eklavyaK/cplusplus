#define PROGRAM int main(){rapid_iostream;int tc=1;while(tc-->0){codeforce();}return 0;}
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
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<bool> is(m);
    for(int j=1;j<m;j++){
        for(int i=1;i<n;i++){
            if(s[i][j-1]=='X' && s[i-1][j]=='X'){
                is[j] = 1; break;
            }
        }
    }
    int cnt = 0;
    vector<int> tot(m);
    for(int i=0;i<m;i++){
        if(is[i])cnt++;
        tot[i] = cnt;
    }
    cin>>cnt;
    while(cnt--){
        int u,v; cin>>u>>v; u--;v--;
        tot[u]!=tot[v]?N():Y();
    }
}