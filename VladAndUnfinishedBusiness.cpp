#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,k; cin>>n>>k;
	int x,y; cin>>x>>y;
	int indeg[n+1]{};
	set<int> houses;
	vector<vector<int>> tree(n+1);
	for(int i=0;i<k;i++){
		int node; cin>>node; 
		houses.insert(node);
	}
	for(int i=0;i<n-1;i++){
		int u,v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
		indeg[u]++;indeg[v]++;
	}
	set<int> path;
	vector<bool> done(n+1);
	bool f = false;
	function<void(int)> dfs = [&](int node){
		done[node] = 1;
		path.insert(node);
		if(node==y){
			f = true;
			return;
		}
		for(auto i : tree[node]){
			if(!done[i])dfs(i);
			if(f)return;
		}
		path.erase(node);
	};
	dfs(x);
	int time = path.size()-1;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==1 && !path.count(i))q.push(i);
	}
	vector<bool> is(n+1);
	fill(done.begin(),done.end(),0);
	while(!q.empty()){
		int node = q.front(); q.pop();
		done[node] = 1;
		if(is[node])time+=2;
		else if(houses.count(node))is[node]=1,time+=2;
		for(auto i : tree[node]){
			if(!done[i]){
				indeg[i]--;
				if(is[node])is[i] = 1;
				if(indeg[i]==1 && !path.count(i))q.push(i);
			}
		}
	}
	cout<<time<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}