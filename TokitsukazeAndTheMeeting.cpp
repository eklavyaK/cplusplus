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
    string s; cin>>s;
    vector<bool> f_row(n*m);
    int sz = n*m, cnt = 0;
    for(int i=0;i<sz;i++){
        if(s[i]=='1')cnt=1;
        if(cnt && cnt<=m)f_row[i] = 1;
        if(cnt)cnt++;
    }
    cnt = 0;
    vector<int> row(m);
    vector<bool> col(m);
    for(int i=0;i<sz;i++){
        if(f_row[i])row[i%m]++;
        if(s[i]=='1' && !col[i%m]){
            cnt++; col[i%m] = 1;
        }
        cout<<cnt+row[i%m]<<' ';
    }
    cout<<endl;
}