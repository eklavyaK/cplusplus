#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,k; cin>>n>>k;
	int arr[n+1]{};
	for(int i=1;i<=n;i++)cin>>arr[i];
	vector<int> v(arr,arr+n+1);
	sort(v.begin(),v.end());
	int x = 0, y = 1e9;
	for(int i=1;i<=n-ceil((ld)(n+k)/2)+1;i++){
		if(v[i+ceil((ld)(n+k)/2)-1]-v[i]<y-x){
			y = v[i+ceil((ld)(n+k)/2)-1];
			x = v[i];
		}
	}
	cout<<x<<' '<<y<<endl;
	int sum[n+1]{};
	for(int i=1;i<=n;i++){
		if(arr[i]>=x && arr[i]<=y)sum[i]=sum[i-1]+1;
		else sum[i] = sum[i-1]-1;
	}
	int f = sum[n], r=n;
	for(int i=n-1;i>=0;i--){
		if(sum[i]==f-1){
			if(k>1)cout<<i+1<<' '<<r<<endl;
			else if(k==1) cout<<1<<' '<<r<<endl;
			r = i; f--; k--;
		}
	}
	cout<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}