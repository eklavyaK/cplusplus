#include<bits/stdc++.h>
#define endl "\n"
#define int long long
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int m,n; cin>>m>>n;
	int arr[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)cin>>arr[i][j];
	int x = 0, y = 0, ans = 0;
	for(int i=0;i<m;i++){
		int mx = 0, l = 0, r = 0;
		for(int j=0;j<n;j++){
			mx = max(mx,arr[i][j]);
			if(arr[i][j]==mx)l = j;
		}
		mx = 0;
		for(int j=0;j<n;j++){
			if(j==l)continue;
			mx = max(mx,arr[i][j]);
			if(arr[i][j]==mx)r = j;
		}
		if(mx>ans)ans=mx,x=l,y=r;
	}
	for(int i=0;i<n;i++){
		if(i==x || i==y)continue;
		int mx = 0;
		for(int j=0;j<m;j++)mx = max(mx,arr[j][i]);
		ans = min(ans,mx);
	}
	cout<<ans<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}