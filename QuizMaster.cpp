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
	int l = 0, r = 0, ans = arr[n-1]+1;
	map<int,int> m;
	while(r<n){
		while(r<n){
			for(int i=1;i*i<=arr[r] && i<=z;i++){
				if(arr[r]%i==0){
					m[i]++; if(arr[r]/i<=z)m[arr[r]/i]++;
				}
			}
			if(m.size()==z)break;
			else r++;
		}
		while(m.size()==z){
			ans = min(ans,arr[r]-arr[l]);
			for(int i=1;i*i<=arr[l] && i<=z;i++){
				if(arr[l]%i==0){
					m[i]--; if(m[i]<=0)m.erase(i);
					if(arr[l]/i<=z){m[arr[l]/i]--;if(m[arr[l]/i]<=0)m.erase(arr[l]/i);}
				}
			}
			l++;
		}
		r++;
	}
	ans==arr[n-1]+1?cout<<-1<<endl:cout<<ans<<endl;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}