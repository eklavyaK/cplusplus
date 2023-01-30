#include<bits/stdc++.h>
#define endl "\n"
typedef long double ld;
typedef long long ll;
using namespace std;
ll mod = 1e9+7;
const int N = 2e5+5;
ll f[N];
void overload(){
	f[1] = 1; f[2] = 2;
	for(int i=3;i<=N-2;i++){
		f[i] = (f[i-1]+f[i-2]+1)%mod;
	}
}
void code(){
	int n,p; 
	cin>>n>>p;
	int arr[n];
	set<int> st;
	ll mx = pow(2,min(p,32));
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		bool f = true;
		int k = arr[i];
		if(k>=mx)continue;
		while(true){
			if(k%4==0)k/=4;
			else if(k&1 && k!=1) k = (k-1)/2;
			else break;
			if(st.count(k)){
				f = false; break;
			}
		}
		if(f)st.insert(arr[i]);
	}
	ll ans = 0;
	int r = 2, l = 0;
	for(auto i : st){
		while(i>=r)r*=2,l++;
		ans = (ans+f[p-l])%mod;
	}
	cout<<ans<<endl;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	overload();
	int t=1; while(t--)code();
	return 0;
}