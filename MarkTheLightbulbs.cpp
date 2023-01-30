#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	string s,t; cin>>s>>t;
	vector<pair<int,int>> cluster_s, cluster_t;
	for(int i=0;i<n;i++){
		if(s[i]=='0')continue;
		int k = i;
		while(i+1<n && s[i+1]=='1')i++;
		cluster_s.push_back({k,i});
	}
	for(int i=0;i<n;i++){
		if(t[i]=='0')continue;
		int k = i;
		while(i+1<n && t[i+1]=='1')i++;
		cluster_t.push_back({k,i});
	}
	if(cluster_t.size()!=cluster_s.size() || s[0]!=t[0] || t[n-1]!=s[n-1]){
		cout<<-1<<endl; return;
	}
	ll ans = 0;
	for(int i=0;i<cluster_s.size();i++){
		ans+=(abs(cluster_s[i].first-cluster_t[i].first)+abs(cluster_s[i].second-cluster_t[i].second));
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}