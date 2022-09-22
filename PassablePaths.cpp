#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
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
const int N = 2e5+5;
vector<int> tree[N];
int done[N], cnt=0,first=1;
bool ans = false, ok = false;
map<int,bool> st,now;
void dfs1(int node){
    done[node]=1;
    if(st.count(node)){
        first = node;
    }
    for(auto i : tree[node]){
        if(!done[i]){
            dfs1(i);
        }
    }
}
void dfs(int node){
    done[node]=1;
    if(st.count(node)){
        cnt++;
    }
    if(cnt==st.size()){
        ans = true;
        return;
    }
    for(auto i : tree[node]){
        if(!done[i])dfs(i);
        if(ans)return;
    }
    if(st.count(node)){
        cnt--;
    }
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    int deg[n+1]{};
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    int query; cin>>query;
    while(query--){
        int m; cin>>m;
        fill(done,done+N-1,0);
        st.clear();
        cnt = 0;
        ans = false;int k;
        for(int j=0;j<m;j++){
            cin>>k;
            st[k];
        }
        dfs1(1);
        fill(done,done+N-1,0);
        dfs(first);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}