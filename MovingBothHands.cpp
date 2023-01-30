#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,m; cin>>n>>m;
	vector<vector<pair<int,int>>> graph(n+1),tree(n+1);
	for(int j=0;j<m;j++){
		int u,v,w; cin>>u>>v>>w;
		graph[u].push_back({v,w});
		tree[v].push_back({u,w});
	}
	vector<ll>dist(n+1,1e14);
	dist[1] = 0;
	set<pair<ll,int>> st;
	st.insert({0,1});
	while(!st.empty()){
		auto [dis,node] = *st.begin();
		st.erase({dis,node});
		for(auto [u,w] : graph[node]){
			if(dist[u]>dis+w){
				st.erase({dist[u],u});
				dist[u] = dis+w;
				st.insert({dist[u],u});
			}
		}
	}
	for(int i=1;i<=n;i++){
		st.insert({dist[i],i});
	}
	while(!st.empty()){
		auto [dis,node] = *st.begin();
		st.erase({dis,node});
		for(auto [u,w] : tree[node]){
			if(dist[u]>dis+w){
				st.erase({dist[u],u});
				dist[u] = dis+w;
				st.insert({dist[u],u});
			}
		}  
	}
	for(int i=2;i<=n;i++){
		cout<<(dist[i]==1e14?-1:dist[i])<<" ";
	}
	cout<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t = 1; while(t--)code();
	return 0;
}