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
    vector<vector<pair<int,int>>> tree(n+1);
    bool label[n+1]{};
    map<string,int> mp;
    mp["imposter"] = -1;
    mp["crewmate"] = 1;
    for(int i=0;i<m;i++){
        int u,v; string c; cin>>u>>v>>c;
        tree[u].push_back({v,mp[c]});
        tree[v].push_back({u,mp[c]==1?2:-2});
    }
    bool done[n+1]{};
    int ans = 0, cnt = 0, imp = 0;
    function<bool(int)> dfs = [&](int node){
        done[node] = 1; cnt++;
        for(auto [next,ind] : tree[node]){
            if(!done[next]){
                if(ind == 1 || ind == 2){
                    if(label[node])label[next] = 1;
                    else imp++;
                }
                else{
                    if(!label[node])label[next] = 1;
                    else imp++;
                }
                if(!dfs(next))return false;
            }
            else{
                if(ind == 1 || ind == 2){
                    if(label[node]!=label[next]) return false;
                }
                else{
                    if(label[node]==label[next]) return false;
                }
            }
        }
        return true;
    };
    for(int i=1;i<=n;i++){
        if(!done[i]){
            cnt = 0; imp = 1;
            bool ok = dfs(i);
            if(ok)ans+=max(imp,cnt-imp);
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
}