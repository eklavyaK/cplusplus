#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n,z; cin>>n>>z;
	vector<int> arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr.begin(),arr.end());
	function<bool(int)> check = [&](int diff){
		map<int,int> m;
		int now = 0;
		for(int i=0;i<n;){
			while(arr[i]-arr[now]>diff){
				for(int j=1;j*j<=arr[now] && j<=z;j++){
					if(arr[i]%j==0){
						m[j]--; if(m[j]<=0)m.erase(j);
						if(arr[now]/j<=z){m[arr[now]/j]--;if(m[arr[now]/j]<=0)m.erase(arr[now]/j);}
					}
				}
				now++;
			}
			while(i<n && arr[i]-arr[now]<=diff){
				for(int j=1;j*j<=arr[i] && j<=z;j++){
					if(arr[i]%j==0){
						m[j]++; if(arr[i]/j<=z)m[arr[i]/j]++;
					}
				}
				i++;
			}
			if(m.size()==z)return true;
		}
		return false;
	};
	int l = 0, r = arr[n-1]+1;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid))r = mid-1;
		else l = mid+1;
	}
	if(r==arr[n-1]+1)cout<<-1<<endl;
	else cout<<r+1<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}