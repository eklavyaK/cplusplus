#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream cin.tie(0)->sync_with_stdio(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
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
/***************************************************MAIN PROGRAM*******************************************************/



int main(){
    rapid_iostream;
    int n,k; cin>>n>>k;
    vector<vector<int>> get(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>get[i][j];
        }
    }
    map<vector<int>,int> m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            vector<int> now;
            for(int x=0;x<k;x++){
                if(get[i][x]==get[j][x]){
                    now.push_back(get[i][x]);
                }
                else{
                    now.push_back(3-get[i][x]-get[j][x]);
                }
            }
            m[now]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        int k = m[get[i]];
        ans+= (ll)k*(k-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}