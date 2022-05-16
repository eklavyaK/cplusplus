#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> graph;
int check[200001];
void addedge(int x, int y){
    graph[x].push_back(y);
    graph[y].push_back(x);              //in case of directed graph we shouldn't write this line;
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int x = q.front(); q.pop();
        check[x]=1; 
        cout<<x<<' ';
        for(auto it = graph[x].begin(); it!=graph[x].end();it++){
            if(!check[*it]){
                q.push(*it);
            }
        }
    }
}
int main(){
    int n; cin>>n;
    for(int i = 0; i<n-1; i++){
        int l,r; cin>>l>>r;
        addedge(l,r);
    }
    bfs(1);           //passing the root vertex
}