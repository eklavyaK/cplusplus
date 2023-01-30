#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	int arr[n],brr[n];
	int sum = 0, ans = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		ans+=arr[i]*arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>brr[i];
		sum+=brr[i];
		ans+=brr[i]*brr[i];
	}
	if(n==1){cout<<0<<endl;return;}
	vector<vector<int>> dp(n,vector<int>(1e4+1));
	dp[0][arr[0]] = 1; dp[0][brr[0]] = 1;
	for(int i=1;i<n;i++){
		for(int j=1e4;j>=0;j--)if(dp[i-1][j])dp[i][j+arr[i]]=1,dp[i][j+brr[i]]=1;
	}
	int mn = 1e9;
	for(int i=1;i<=1e4;i++){
		if(dp[n-1][i])mn = min(mn,i*i+(sum-i)*(sum-i));
	}
	cout<<(n-2)*ans+mn<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}