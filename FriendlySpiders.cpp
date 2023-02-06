#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<vector<int>> graph(6e5+5);
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=2;j*j<=k;j++){
            if(k%j==0){
                graph[i].push_back(3e5+j);
                graph[3e5+j].push_back(i);
                while(k%j==0)k/=j;
            }
        }
        if(k!=1){
            graph[i].push_back(3e5+k);
            graph[3e5+k].push_back(i);
        }
    }
    int st, en; cin>>st>>en;
    int par[graph.size()]{};
    queue<int> q;
    q.push(st);
    par[st] = st;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto i : graph[node]){
            if(par[i])continue;
            par[i] = node;
            q.push(i);
        }
    }
    if(!par[en]){
        cout<<-1<<endl;
        return;
    }
    vector<int> ans;
    while(true){
        if(en<=3e5)ans.push_back(en);
        if(en==st)break;
        en = par[en];
    }
    cout<<ans.size()<<endl;
    for(auto it = ans.rbegin(); it!=ans.rend(); it++)cout<<*it<<' ';
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}