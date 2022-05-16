#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> graph;
int check[200001];
void addedge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);          //in case of directed graph we shouldn't write this line;
}
void dfs(int x){
    check[x]=1;
    cout<<x<<' ';
    for(auto it = graph[x].begin(); it!=graph[x].end();it++){
        if(!check[*it]){
            dfs(*it);
        }
    }
}
int main(){
    int n; cin>>n;
    for(int i = 0; i<n-1; i++){
        int l,r; cin>>l>>r;
        addedge(l,r);
    }
    dfs(1);        //the passed argument must be a vertex of graph, in case of directed graph it must a vertex where an arrow begins
}