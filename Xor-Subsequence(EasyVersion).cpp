#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n; int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	int dp[n]{};
	for(int i=n-1;i>=0;i--){
		for(int j=i-1;j>=max(0,i-700);j--){
			if((i^arr[j])<(j^arr[i])) dp[j] = max(dp[j],dp[i]+1);
		}
	}
	cout<<1+*max_element(dp,dp+n)<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}