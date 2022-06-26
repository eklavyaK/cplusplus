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
    int n,m;cin>>n>>m;
    int a[n];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int cnt = 1;
        while(a[i]%m==0){
            a[i]/=m;
            cnt*=m;
        }
        v.push_back({a[i],cnt});
    }
    vector<pair<int,ll>> f1,f2;
    for(int i=0;i<n;i++){
        ll num = v[i].S;
        while(i+1<n && v[i].F==v[i+1].F){
            i++;num+=v[i].S;
        }
        f1.push_back({v[i].F,num});
    }
    int k; cin>>k; int b[k];
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    v.clear();
    for(int i=0;i<k;i++){
        int cnt = 1;
        while(b[i]%m==0){
            b[i]/=m;
            cnt*=m;
        }
        v.push_back({b[i],cnt});
    }
    for(int i=0;i<k;i++){
        ll num = v[i].S;
        while(i+1<k && v[i].F==v[i+1].F){
            i++;num+=v[i].S;
        }
        f2.push_back({v[i].F,num});
    }
    if(f1.size()!=f2.size())N();
    else{
        for(int i=0;i<f1.size();i++){
            if(f1[i].F!=f2[i].F || f1[i].S!=f2[i].S){
                N();return;
            }
        }
        Y();
    }
}