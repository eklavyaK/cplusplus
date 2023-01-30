#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,m,s; cin>>n>>m>>s;
	vector<vector<int>> graph(n+1);
	for(int j=0;j<m;j++){
		int u,v; cin>>u>>v;
		graph[u].push_back(v);
	}
	set<int> st,now;
	bool ans = false;
	vector<int> path1,path2;
	int t = 0;
	function<void(int)> dfs = [&](int node){
		if(st.count(node)){
			ans = true;
			t = node;
			path1.push_back(node);
			return;
		}
		now.insert(node);
		for(auto i : graph[node]){
			if(!now.count(i))dfs(i);
			if(ans){
				path1.push_back(node);
				return;
			}
		}
	};
	st.insert(s);
	for(auto i : graph[s]){
		now.clear(); 
		now.insert(s); dfs(i);
		st.insert(now.begin(),now.end());
		if(ans){
			path1.push_back(s);
			cout<<"Possible"<<endl;
			break;
		}
	}
	if(!t){cout<<"Impossible"<<endl;return;}
	vector<bool> done(n+1);
	done[s] = 1;
	ans = false;
	function<void(int)> dfs1 = [&](int node){
		if(node==t){
			ans = true;
			path2.push_back(node);
			return;
		}
		done[node] = 1;
		for(auto i : graph[node]){
			if(!done[i])dfs1(i);
			if(ans){
				path2.push_back(node);
				return;
			}
		}
	};
	for(auto i : graph[s]){
		dfs1(i);
		if(ans){
			path2.push_back(s);
			break;
		}
	}
	cout<<path1.size()<<endl;
	for(auto it = path1.rbegin(); it!=path1.rend(); it++){
		cout<<*it<<' ';
	}
	cout<<endl<<path2.size()<<endl;
	for(auto it = path2.rbegin(); it!=path2.rend(); it++){
		cout<<*it<<' ';
	}
	cout<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t=1; while(t--)code();
	return 0;
}