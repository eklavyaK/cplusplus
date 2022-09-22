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
    int n,q; cin>>n>>q;
    map<int,pair<int,int>> m;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(m.count(k)){
            m[k].S = i;
        }
        else{
            m[k].F = i;
            m[k].S = i;
        }
    }
    while(q--){
        int start,end;
        cin>>start>>end;
        if(!m.count(start)||!m.count(end))cout<<"No"<<endl;
        else{
            if(m[start].F<m[end].S)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}