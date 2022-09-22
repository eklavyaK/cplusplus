#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
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
    int a[n];
    string ans(m,'B');
    map<int,bool> g;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]-1<=m+1-a[i]-1){
            if(g.count(a[i]-1)){
                g[m+1-a[i]-1];
            }
            else g[a[i]-1];
        }
        else{
            if(g.count(m+1-a[i]-1)){
                g[a[i]-1];
            }
            else g[m+1-a[i]-1];
        }
    }
    for(auto i : g){
        ans[i.F] = 'A';
    }
    cout<<ans<<endl;
}