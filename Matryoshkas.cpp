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
	map<int,int>m;
	for(int i=0;i<n;i++){
		int k; cin>>k;
		m[k]++;
	}
	int ans = 0;
	while(!m.empty()){
		ans++;
		auto c = m.begin();
		int now = c->first;
		while(m.count(now)){
			m[now]--;
			if(m[now]==0)m.erase(now);
			now++;
		}
	}
	cout<<ans<<endl;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}