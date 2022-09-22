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
    int n; cin>>n;
    int a[n], b[n];
    map<int,int> m;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(k%2==0){
            k/=2;
        }
        m[k]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int j=0;j<32;j++){
        if(m.size())
        for(int i=0;i<n;i++){
            if(m.count(b[i])){
                m[b[i]]--;
                if(m[b[i]]==0)m.erase(b[i]);
                b[i]=-1;
            }
            else b[i]/=2;
        }
        else break;
    }
    if(m.size())cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}