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
    int n,k; cin>>n>>k;
    int arr[n+1]; 
    int indeg[n+1]{};
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i]; 
        ans^=arr[i];
    }
    vector<vector<int>> tree(n+1);
    for(int i=0;i<n-1;i++){
        int  u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        indeg[u]++;indeg[v]++;
    }
    bool print = 0;
    if(ans==0){
        Y();return;
    }
    if(k==2){
        N();return;
    }
    int done[n+1]{};
    queue<int> q;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(indeg[i]==1){
            if(arr[i]==ans)cnt++;
            else q.push(i);
            done[i] = 1;
            if(cnt == 2)break;
        }
    }
    if(cnt!=2)
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i : tree[node]){
            if(!done[i]){
                indeg[i]--;
                arr[i]^=arr[node];
                if(indeg[i]==1){
                    if(arr[i]==ans)cnt++;
                    else q.push(i);
                    done[i] = 1;
                    if(cnt==2)break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!done[i]){
            Y();return;
        }
    }
    N();
}