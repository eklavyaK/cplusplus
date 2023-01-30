#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,c; cin>>n>>c;
	vector<int> arr, sum(c+1);
	for(int i=0;i<n;i++){
		int k; cin>>k;
		if(!sum[k])arr.push_back(k);
		sum[k]=1;
	}
	n = arr.size();
	int mx = *max_element(arr.begin(),arr.end());
	vector<int> abs;
	for(int i=1;i<=mx;i++){
		if(!sum[i])abs.push_back(i);
	}
	for(int i=1;i<=mx;i++){
		sum[i] = sum[i-1]+sum[i];
	}
	int l = abs.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<l && (ll)arr[i]*abs[j]<=mx;j++){
			if(sum[min((ll)mx,(ll)arr[i]*(abs[j]+1)-1)]-sum[arr[i]*abs[j]-1]>0){
				cout<<"No"<<endl;
				return;
			}
		}
	}
	cout<<"Yes"<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}