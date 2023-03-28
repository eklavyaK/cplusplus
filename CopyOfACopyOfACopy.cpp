#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,k; cin>>n>>m>>k;
    vector<vector<string>> s(k+1,vector<string>(n));
    for(int j=0;j<=k;j++){
        for(int i=0;i<n;i++){
            cin>>s[j][i];
        }
    }
    vector<pair<int,int>> ops;
    function<bool(int,int,int)> compare = [&](int u, int i, int j){
        if(s[u][i-1][j]==s[u][i+1][j] && s[u][i+1][j]==s[u][i][j-1] && s[u][i][j-1]==s[u][i][j+1] && s[u][i][j]!=s[u][i-1][j]) return false;
        return true;
    };
    function<bool(int,int)> check = [&](int u, int v){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[u][i][j]==s[v][i][j])continue;
                else if(i==0||j==0||i==n-1||j==m-1||compare(u,i,j))return false;
                ops.push_back({i+1,j+1});
            }
        }
        return true;
    };
    vector<vector<int>> graph(k+1);
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(i==j)continue;
            if(check(i,j)) graph[i].push_back(j);
            ops.clear();
        }
    }
    bool f = false;
    vector<int> ans, vis(k+1);
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        ans.push_back(node);
        if(ans.size()==k+1){
            f = true; return;
        }
        for(auto i : graph[node]){
            if(!vis[i] && graph[i].size()+1>k-ans.size())dfs(i);
            if(f)return;
        }
        ans.pop_back();
        vis[node] = 0;
    };
    for(int i=0;i<=k;i++){
        if(graph[i].size()==k){
            dfs(i);
            break;
        }
    }
    // cout<<ans.size()<<endl;
    // for(auto i : ans) cout<<i<<" ";
    // exit(0);
    cout<<ans[0]+1<<endl;
    int cnt = 0;
    vector<vector<int>> print;
    for(int r = 0; r<k; r++){
        check(ans[r],ans[r+1]);
        cnt+=ops.size();
        for(auto i : ops){
            print.push_back({1,i.F,i.S});
        }
        print.push_back({2,ans[r+1]+1});
        ops.clear();
    }
    cout<<print.size()<<endl;
    for(auto i : print){
        for(auto j : i)cout<<j<<' ';
        cout<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}