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
    set<int> st[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k; cin>>k;
            st[j].insert(k);
        }
    }
    map<set<int>,int> sett;
    for(int i=0;i<m;i++){
        sett[st[i]] = i;
    }
    bool z = -1;
    int ans[n][m];
    for(int j=0;j<m;j++){
        vector<int> v(n);
        set<int> now;
        for(int i=0;i<n;i++){
            cin>>v[i];
            now.insert(v[i]);
        }
        int index = sett[now];
        for(int i=0;i<n;i++){
            ans[i][index] = v[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}