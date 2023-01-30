#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n; int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n); int ans = 0;
	for(int i=0;i<n;i++){
		if(i+1<n && arr[i+1]==arr[i])i++;
		if(i!=n-1 && arr[i]<i+1 && arr[i+1]>i+1)ans++;
		else if(i==n-1 && arr[i]<i+1)ans++;
	}
	if(arr[0])ans++;
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}