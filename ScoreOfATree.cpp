#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
void code(){
	int n; cin>>n;
	vector<vector<int>> tree(n+1);
	int indeg[n+1]{}; ll z = 1;
	for(int i=0;i<n-1;i++){
		z = (z*2)%mod;
		int u,v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
		indeg[u]++;indeg[v]++;
	}
	ll ans = 0;
	queue<int> q;
	vector<int> dep(n+1,1);
	for(int i=2;i<=n;i++){
		if(indeg[i]==1)q.push(i);
	}
	vector<bool> done(n+1);
	while(!q.empty()){
		int node = q.front(); q.pop();
		done[node] = 1;
		ans=(ans+z*dep[node])%mod;
		for(auto i : tree[node]){
			if(!done[i]){
				indeg[i]--;
				dep[i] = max(dep[i],dep[node]+1);
				if(indeg[i]==1 && i!=1)q.push(i);
			}
		}
	}
	cout<<(ans+dep[1]*z)%mod<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}