#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
    int n; cin>>n;
    vector<vector<int>> tree(n+1);
    vector<int> value(n+1);
    vector<int> par(n+1);
    vector<int> indeg(n+1);
    vector<int> dep(n+1);
    for(int i=2;i<=n;i++){
        int node; cin>>node;
        par[i] = node;
        indeg[i]++;
        indeg[node]++;
    }
    par[1] = 1;
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(indeg[i]==1)q.push(i);
    }
    vector<int> indeg1 = indeg;
    set<int> st;
    while(!q.empty()){
        int node = q.front(); q.pop();
        int now = 1;
        while(indeg[par[node]]==2){
            if(par[node]==1)break;
            now++; node = par[node];
        }
        indeg1[par[node]]--;
        value[par[node]]+=now;
        if(par[node]==1 && indeg[1]==1)value[1]++;
        if(par[node]!=1 && indeg1[par[node]]==1)st.insert(par[node]);
        dep[par[node]]=max(dep[par[node]],now+1);
    }
    indeg = indeg1;
    while(!st.empty()){
        int node = *st.begin();
        st.erase(node);
        q.push(node);
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        dep[par[node]] = max(dep[par[node]],dep[node]+1);
        value[par[node]]+=value[node];
        indeg[par[node]]--;
        if(indeg[par[node]]==1){
            value[par[node]] = max(value[par[node]],dep[par[node]]);
            if(par[node]!=1)q.push(par[node]);
        }
    }
    value[1] = max(value[1],dep[1]);
    cout<<value[1]<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}