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
const int N = 2e5+5;
int n,m,worker[N];
bool check(int time){
    ll kaam = 0, rem = 0;
    for(int i=1;i<=n;i++){
        if(worker[i]<time){
            rem+=(time-worker[i])/2;
        }
        else if(worker[i]>time){
            kaam+=(worker[i]-time);
        }
    }
    return kaam<=rem;
}
void codeforce(){
    cin>>n>>m;
    fill(worker,worker+n+2,0);
    for(int i=0;i<m;i++){
        int k;cin>>k;
        worker[k]++;
    }
    int l = 1, r = m;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<min(r+1,m)<<endl;
}