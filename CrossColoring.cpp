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

const int mod = 998244353;
ll power(ll n, ll k){
    long  long ans = 1;
    while(k>0){
        if(k&1)ans = (ans*n)%mod;
        k>>=1; n = (n*n)%mod;
    }
    return ans;
}
void codeforce(){
    int n,m,k,q; 
    cin>>n>>m>>k>>q;
    int x[q], y[q];
    map<int,int> row,col;
    for(int i=0;i<q;i++){
        cin>>x[i]>>y[i];
        row[x[i]] = i;
        col[y[i]] = i;
    }
    set<int> a,b; int cnt = 0;
    vector<pair<int,int>> v;
    for(int i=0;i<q;i++){
        if(row[x[i]]<=i || col[y[i]]<=i){
            v.push_back({x[i],y[i]});
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        a.insert(v[i].F);
        b.insert(v[i].S);
        cnt++;
        if(a.size()==n || b.size()==m){
            cout<<power(k,cnt)<<endl;
            return;
        }
    }
    cout<<power(k,v.size())<<endl;
}