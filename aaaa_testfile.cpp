#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,m; cin>>n>>m;
	int a[n+1]{}, c[m];
	for(int i=0;i<n;i++){
		int k; cin>>k;
		a[k]++;
	}
	priority_queue<int> u;
	for(int i=1;i<=n;i++){
		if(a[i])u.push(a[i]);
	}
	for(int i=0;i<m;i++){
		cin>>c[i];
	}
	int ans = 0;
	sort(c,c+m,greater<int>());
	for(int i=0;i<m && !u.empty();i++){
		int k = u.top(); u.pop();
		if(k>c[i]){
			ans+=c[i];
			u.push(k-c[i]);
		}
		else ans+=k;
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}