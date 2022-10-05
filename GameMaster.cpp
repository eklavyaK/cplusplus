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
    int n; cin>>n;
    map<int,int> a,b;
    int sta[n], stb[n];
    int va[n], vb[n];
    for(int i=0;i<n;i++){
        cin>>sta[i];
        a[sta[i]] = i;
        va[i] = sta[i];
    }
    for(int i=0;i<n;i++){
        cin>>stb[i];
        b[stb[i]] = i;
        vb[i] = stb[i];
    }
    bool ans[n]{};
    sort(va,va+n);
    sort(vb,vb+n);
    int lasta = va[n-1];
    int lastb = 1e9+5;
    int mna = va[n-1];
    int ina = n-1, inb = n;
    int mnb = stb[a[va[ina]]];
    ans[a[va[ina]]] = 1;
    bool c = 0;
    while(true){
        if(c){
            c = !c;
            if(mna==lasta)break;
            int start = upper_bound(va,va+n,mna)-va;
            for(int i=start;i<ina;i++){
                ans[a[va[i]]] = 1;
                mnb = min(mnb,stb[a[va[i]]]);
            }
            ina = start-1;
            lasta = mna;
        }
        else{
            c = !c;
            if(mnb==lastb)break;
            int start = upper_bound(vb,vb+n,mnb)-vb;
            for(int i=start;i<inb;i++){
                ans[b[vb[i]]] = 1;
                mna = min(mna,sta[b[vb[i]]]);
            }
            inb = start-1;
            lastb = mnb;
        }
    }
    for(auto i : ans)cout<<i;cout<<endl;
}