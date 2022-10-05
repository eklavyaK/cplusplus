#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        queue<int> q;
        int color[n+1]{};
        int indeg[n+1]{};
        bool ans = 0;
        vector<vector<int>> tree(n+1);
        for(int i=0;i<k;i++){
            int node; cin>>node;
            q.push(node);
            color[node] = -1;
        }
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
            indeg[u]++;indeg[v]++;
        }
        if(color[1]){cout<<"NO"<<endl;continue;}
        color[1] = 1; q.push(1);
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(auto i : tree[node]){
                if(!color[i]){
                    color[i] = color[node];
                    q.push(i);
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(color[i]==1 && indeg[i]==1){
                ans = 1;break;
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}