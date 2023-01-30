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
	int arr[n][n-1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++)cin>>arr[i][j];
	}
	int cnt[n+1]{};
	vector<int> ans;
	for(int j=0;j<n-2;j++){
		int p = 0;
		for(int i=0;i<n;i++){
			cnt[arr[i][j]]++;
			if(cnt[arr[i][j]]==n-1)p = arr[i][j];
		}
		ans.push_back(p);cnt[p]=0;
	}
	map<int,int> m;
	for(int i=0;i<n;i++){
		m[arr[i][n-2]]++;
	}
	ans.push_back(0);
	ans.push_back(0);
	for(auto i : m){
		if(i.second==n-1)ans[n-1] = i.first;
		else ans[n-2] = i.first;
	}
	for(auto i : ans) cout<<i<<' ';cout<<endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}