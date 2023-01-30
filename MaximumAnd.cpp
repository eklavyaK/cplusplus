#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;


void code(){
	int n; cin>>n;
	int arr[n],brr[n]; int ans = 0;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++)cin>>brr[i];
	vector<bool> exc(30);
	for(int i=0;i<30;i++){
		map<int,int> m;
		for(int j=0;j<n;j++){
			int now = 0, r = i;
			for(int k=29;k>=29-i;k--,r--){
				if(exc[k])continue;
				if((1<<k)&arr[j])now+=(1<<r);
			}
			m[now]++;
		}
		for(int j=0;j<n;j++){
			int now = 0, r = i;
			for(int k=29;k>=29-i;k--,r--){
				if(exc[k])continue;
				if(!((1<<k)&brr[j]))now+=(1<<r);
			}
			if(m[now])m[now]--;
			else{
				exc[29-i] = 1;
				goto zero;
			}
		}
		ans+=(1<<(29-i));
		zero:;
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}